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
	mHUD->Draw();
	mWorldHandler -> Draw(mCamera2);	
	for(UINT i = 0; i < mGhost.size(); i++)
		mGhost.at(i)->Draw(mCamera2);
}

void GameScreen::Update()
{
	mGameTimer->Tick();
	float lDeltaTime = mGameTimer->GetDeltaTime();
	KeyBoardMovement(lDeltaTime);
	MouseMovement();
	UpdateGhost(lDeltaTime);

	//mCamera->UpdateView();
	
	mCamera2->update();
	mPacman->SetPosition(mCamera2->getCameraPosition());
	for(UINT i = 0; i < mGhost.size(); i++)
	{
		if(GetCollisionHandler().ObjectCollisionCheck(mPacman , mGhost.at(i)))
			mCamera2->SetPosition(400,50,400);
	}	
}

void GameScreen::KeyBoardMovement(float lDeltaTime)
{
	////Forward
	//if(mKeyboardHandler->CheckPressedKey(W))
	//	mCamera->Walk(gPlayerMovementSpeed * lDeltaTime);
	////Left
	//if(mKeyboardHandler->CheckPressedKey(A))
	//	mCamera->Strafe(-gPlayerMovementSpeed  * lDeltaTime);
	////Back
	//if(mKeyboardHandler->CheckPressedKey(S))
	//	mCamera->Walk(-gPlayerMovementSpeed  * lDeltaTime);
	////Right
	//if(mKeyboardHandler->CheckPressedKey(D))
	//	mCamera->Strafe(gPlayerMovementSpeed  * lDeltaTime);

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
	POINT lMousePosition;
	GetCursorPos(&lMousePosition);
	int dx = 0;
	int dy = 0;

	//mCamera->Pitch(dy * gCursorSensitivity);
	//mCamera->RotateY(dx * gCursorSensitivity);

	if (lMousePosition.x > 500)
		dx = 2.5f ;
	else if(lMousePosition.x < 500)
		dx = -2.5f;
	if (lMousePosition.y > 500)
		dy = 2.5f;
	else if(lMousePosition.y < 500)
		dy = -2.5f;
	mCamera2->adjustHeadingPitch(0.025f * dx, 0.025f * dy);
	SetCursorPos(500, 500);
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
	//D3DXVECTOR3 spawnVector(0, 0, -200);
	//mWaypoint.push_back(new Waypoint(D3DXVECTOR3(200, -200, 0)));

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
	//delete lWaypoint;
	//mGhost.push_back(new Ghost(spawnVector, mWorldHandler->GetGhostSpawnWaypoint()));
	//mGhost.push_back(new Ghost(spawnVector, mWorldHandler->GetGhostSpawnWaypoint()));
	//mGhost.push_back(new Ghost(spawnVector, mWorldHandler->GetGhostSpawnWaypoint()));
	//mGhost.push_back(new Ghost(spawnVector, mWorldHandler->GetGhostSpawnWaypoint()));
}