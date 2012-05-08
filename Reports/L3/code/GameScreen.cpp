#include "GameScreen.h"

GameScreen::GameScreen()
	: BaseGameScreen()
{	
	mHUD = new HUD();
	mKeyboardHandler = new KeyboardInputHandler();
}

GameScreen::~GameScreen()
{
	delete mHUD;
	//delete mPacman;
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
	LoadGhosts();
}

void GameScreen::ShutDown()
{

}

void GameScreen::Draw()
{
	mHUD->Draw();
	mWorldHandler -> Draw(mCamera);	
}

void GameScreen::Update()
{
	mGameTimer->Tick();
	float lDeltaTime = mGameTimer->GetDeltaTime();
	KeyBoardMovement(lDeltaTime);
	MouseMovement();
	UpdateGhost(lDeltaTime);
	mCamera->UpdateView();
	//mCamera2->update();
}

void GameScreen::KeyBoardMovement(float lDeltaTime)
{
	//Forward
	if(mKeyboardHandler->CheckPressedKey(W))
		mCamera->Walk(gPlayerMovementSpeed * lDeltaTime);
	//Left
	if(mKeyboardHandler->CheckPressedKey(A))
		mCamera->Strafe(-gPlayerMovementSpeed  * lDeltaTime);
	//Back
	if(mKeyboardHandler->CheckPressedKey(S))
		mCamera->Walk(-gPlayerMovementSpeed  * lDeltaTime);
	//Right
	if(mKeyboardHandler->CheckPressedKey(D))
		mCamera->Strafe(gPlayerMovementSpeed  * lDeltaTime);

	////Forward
	//if(mKeyboardHandler->CheckPressedKey(W))
	//	mCamera2->setMovementToggle( 0, 1 );
	//else
	//	mCamera2->setMovementToggle( 0, 0);
	////Left
	//if(mKeyboardHandler->CheckPressedKey(A))
	//	mCamera2->setMovementToggle( 2, -1 );
	//else
	//	mCamera2->setMovementToggle( 2, 0 );
	////Back
	//if(mKeyboardHandler->CheckPressedKey(S))
	//	mCamera2->setMovementToggle( 1, -1 );
	//else
	//	mCamera2->setMovementToggle( 1, 0 );
	////Right
	//if(mKeyboardHandler->CheckPressedKey(D))
	//	mCamera2->setMovementToggle( 3, 1 );
	//else
	//	mCamera2->setMovementToggle( 3, 0 );

}

void GameScreen::MouseMovement()
{
	POINT lMousePosition;
	GetCursorPos(&lMousePosition);
	int dx = 0;
	int dy = 0;
	dx = lMousePosition.x - mOldCursorPosition.x;
	dy = lMousePosition.y - mOldCursorPosition.y;
	mCamera->Pitch(dy * gCursorSensitivity);
	mCamera->RotateY(dx * gCursorSensitivity);

	//mCamera2->adjustHeadingPitch(0.000025f * dx, 0.000025f * dy);
	mOldCursorPosition = lMousePosition;
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

void GameScreen::LoadGhosts()
{
	D3DXVECTOR3 spawnVector(0, 0, -200);
	//mWaypoint.push_back(new Waypoint(D3DXVECTOR3(200, -200, 0)));

	/*Waypoint* lWaypoint = mWorldHandler->GetGhostSpawnWaypoint();

	mGhost.push_back(new Ghost(spawnVector, lWaypoint));
	mGhost.push_back(new Ghost(spawnVector, lWaypoint));
	mGhost.push_back(new Ghost(spawnVector, lWaypoint));
	mGhost.push_back(new Ghost(spawnVector, lWaypoint));

	delete lWaypoint;*/
	mGhost.push_back(new Ghost(spawnVector, mWorldHandler->GetGhostSpawnWaypoint()));
	mGhost.push_back(new Ghost(spawnVector, mWorldHandler->GetGhostSpawnWaypoint()));
	mGhost.push_back(new Ghost(spawnVector, mWorldHandler->GetGhostSpawnWaypoint()));
	mGhost.push_back(new Ghost(spawnVector, mWorldHandler->GetGhostSpawnWaypoint()));
}