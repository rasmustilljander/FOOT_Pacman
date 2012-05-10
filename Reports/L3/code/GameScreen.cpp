#include "GameScreen.h"

GameScreen::GameScreen()
	: BaseGameScreen()
{	
	mLivesLeft = 3;

	mHUD = new HUD();
	mKeyboardHandler = new KeyboardInputHandler();
	mPacman = new Player();
	mDead = false;
}

GameScreen::~GameScreen()
{
	delete mHUD;
	delete mPacman;
	delete mKeyboardHandler;
	mGhost.clear();
}

void GameScreen::StartUp(ID3D10Device* lDevice)
{
	BaseGameScreen::StartUp(lDevice);
	mOldCursorPosition.x = 0;
	mOldCursorPosition.y = 0;

	mHUD->Initialize( lDevice );
	mWorldHandler->Initialize( lDevice );
	LoadGhosts(lDevice);
	ShowCursor(false);
	mPacman->SetPosition(mCamera2->getCameraPosition());
}

void GameScreen::ShutDown()
{

}

void GameScreen::Draw()
{
	
	mWorldHandler -> Draw(mCamera2);	
	for(UINT i = 0; i < mGhost.size(); i++)
		mGhost.at(i)->Draw(mCamera2);

	if (mDead == true)
	{
		mHUD->DrawDeathEffect();
		GetRawMouseInput().A.x = 0;
		GetRawMouseInput().A.y = 0;
	}
	else
		mHUD->Draw();
}

void GameScreen::Update()
{
	if (mDead == false)
	{
		mGameTimer->Tick();
		float lDeltaTime = mGameTimer->GetDeltaTime();
	
		if(!mKeyboardHandler->CheckPressedKey(M))
		{
			KeyBoardMovement(lDeltaTime);
			MouseMovement();
			UpdateGhost(lDeltaTime);
			ObjectCollisions();
			mCamera2->update();
			D3DXVECTOR3 lPosVector = mCamera2->getCameraPosition();
			D3DXVECTOR3 lDirVector = mCamera2->getViewDirection();
			mAudioHandler->UpdatePosition( lPosVector.x, lPosVector.y, lPosVector.z, lDirVector.x, lDirVector.y, lDirVector.z );
		}
		else
		{
			mCamera2->adjustHeadingPitch(0,1);
			mCamera2->SetPosition(600,800,600);
			GetRawMouseInput().A.x = 0;
			GetRawMouseInput().A.y = 0;
		}
		mPacman->SetPosition(mCamera2->getCameraPosition());
	}
	
}

void GameScreen::ObjectCollisions()
{
	for(UINT i = 0; i < mGhost.size(); i++)
	{
		if(GetCollisionHandler().ObjectCollisionCheck(mPacman , mGhost.at(i)))
		{
			mDead = true;
			mLivesLeft --;
			mHUD->setLivesLeft(mLivesLeft);

			mAudioHandler->PlayDeathSound();
		}
	}
	vector<Candy*> *lVector = mWorldHandler->GetCandy();
	if(!lVector->empty())
	{
		for(UINT i = 0; i < lVector->size(); i++)
		{
			if(GetCollisionHandler().ObjectCollisionCheck(mPacman , lVector->at(i)))
			{
				if (lVector->at(i)->GetType() == 0)
				{
					mScore += 100;
					mHUD->setScore(mScore);
				}
				else
				{
					mScore +=300;
					mHUD->setScore(mScore);
					mSuperCandyInEffect = true;
				}
				lVector->erase(lVector->begin() + i);
				mAudioHandler->PlayCandySound();
			}
		}
	}
}

void GameScreen::KeyBoardMovement(float lDeltaTime)
{
	

	//Forward
	if(mKeyboardHandler->CheckPressedKey(W))
		mCamera2->setMovementToggle( 0, 1 );
	else
		mCamera2->setMovementToggle( 0, 0);
	//Left
	if(mKeyboardHandler->CheckPressedKey(A))
		mCamera2->setMovementToggle( 2, -1 );
	else
		mCamera2->setMovementToggle( 2, 0 );
	//Back
	if(mKeyboardHandler->CheckPressedKey(S))
		mCamera2->setMovementToggle( 1, -1 );
	else
		mCamera2->setMovementToggle( 1, 0 );
	//Right
	if(mKeyboardHandler->CheckPressedKey(D))
		mCamera2->setMovementToggle( 3, 1 );
	else
		mCamera2->setMovementToggle( 3, 0 );

}

void GameScreen::MouseMovement()
{
	mCamera2->adjustHeadingPitch(0.005f * GetRawMouseInput().A.x, 0.005f * GetRawMouseInput().A.y);
	GetRawMouseInput().A.x = 0;
	GetRawMouseInput().A.y = 0;
}

void GameScreen::UpdateGhost(float lDeltaTime)
{
	for(UINT i = 0; i < mGhost.size(); i++)
	{
		mGhost.at(i)->Update(lDeltaTime);
		D3DXVECTOR3 lVector = mGhost.at(i)->GetPosition();
		mAudioHandler->UpdateGhostPosition( i, lVector.x, lVector.y, lVector.z );
	}
}

void GameScreen::ActivateScreen(GameScreenState lGameScreenState)
{
	mGameScreenState = lGameScreenState;

	mAudioHandler->PlayBackgroundSound();
	for ( int i = 0; i < mGhost.size(); i++ )
	{
		D3DXVECTOR3 lVector = mGhost.at(i)->GetPosition();
		mAudioHandler->PlayGhostSound( i, lVector.x, lVector.y, lVector.z );
	}
}

void GameScreen::LoadGhosts(ID3D10Device* lDevice)
{

	Waypoint* lWaypoint = mWorldHandler->GetGhostSpawnWaypoint();

	mGhost.push_back(new Ghost(lWaypoint->GetPosition(), lWaypoint));
	mGhost.push_back(new Ghost(lWaypoint->GetPosition(), lWaypoint));
	mGhost.push_back(new Ghost(lWaypoint->GetPosition(), lWaypoint));
	mGhost.push_back(new Ghost(lWaypoint->GetPosition(), lWaypoint));
	for(UINT i = 0; i < mGhost.size() ; i++)
		mGhost.at(i)->Initialize(lDevice,"gameobject.fx");
	mGhost.at(0)->IsEdible(false);
	mGhost.at(1)->IsEdible(false);
	mGhost.at(2)->IsEdible(true);
	mGhost.at(3)->IsEdible(true);

}