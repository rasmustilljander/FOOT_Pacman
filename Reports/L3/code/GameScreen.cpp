#include "GameScreen.h"

GameScreen::GameScreen()
	: BaseGameScreen()
{	
	mHUD = new HUD();
	mKeyboardHandler = new KeyboardInputHandler();
	mPacman = new Player();
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

	mHUD->Draw();
}

void GameScreen::Update()
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
	}
	else
	{
		mCamera2->adjustHeadingPitch(0,1);
		mCamera2->SetPosition(600,800,600);	
	}
	mPacman->SetPosition(mCamera2->getCameraPosition());
	
}

void GameScreen::ObjectCollisions()
{
	for(UINT i = 0; i < mGhost.size(); i++)
	{
		if(GetCollisionHandler().ObjectCollisionCheck(mPacman , mGhost.at(i)))
			mCamera2->setPositionAndView(600,800,600,1, 0);
	}
	vector<Candy*> *lVector = mWorldHandler->GetCandy();
	if(!lVector->empty())
	{
		for(UINT i = 0; i < lVector->size(); i++)
		{
			if(GetCollisionHandler().ObjectCollisionCheck(mPacman , lVector->at(i)))
			{
				lVector->erase(lVector->begin() + i);
				mScore += 100;
				mHUD->setScore(mScore);
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
		mGhost.at(i)->Update(lDeltaTime);
}

void GameScreen::ActivateScreen(GameScreenState lGameScreenState)
{
	mGameScreenState = lGameScreenState;
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