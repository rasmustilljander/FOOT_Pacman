#include "GameScreen.h"

GameScreen::GameScreen()
	: BaseGameScreen()
{	
	mHUD = new HUD();
	mWorldHandler = new WorldHandler();
	mKeyboardHandler = new KeyboardInputHandler();
}

GameScreen::~GameScreen()
{
	//delete mHUD;
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
	mWorldHandler->Draw( mCamera );	
}

void GameScreen::Update()
{
	mGameTimer->Tick();
	float lDeltaTime = mGameTimer->GetDeltaTime();
	KeyBoardMovement(lDeltaTime);
	//MouseMovement();
	UpdateGhost(lDeltaTime);
	mCamera->UpdateView();
}

void GameScreen::KeyBoardMovement(float lDeltaTime)
{
	/*
	bool w = false;
	bool a = false;
	bool s = false;
	bool d = false;
	*/

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