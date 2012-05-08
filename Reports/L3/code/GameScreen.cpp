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
	ShowCursor(false);
}

void GameScreen::ShutDown()
{

}

void GameScreen::Draw()
{
	mHUD->Draw();
	mWorldHandler -> Draw(mCamera2);	
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

	//if (lMousePosition.x > mOldCursorPosition.x)
	//{
	//	dx = abs(lMousePosition.x - mOldCursorPosition.x);
	//}
	//else if(lMousePosition.x < mOldCursorPosition.x)
	//{
	//	dx = -abs(lMousePosition.x - mOldCursorPosition.x);
	//}
	//if (lMousePosition.y > mOldCursorPosition.y)
	//{
	//	dy = abs(lMousePosition.y - mOldCursorPosition.y);
	//}
	//else if(lMousePosition.y < mOldCursorPosition.y)
	//{
	//	dy = -abs(lMousePosition.y - mOldCursorPosition.y);
	//}
	//int a = GetRawMouseInput().A.x;
	//int b = GetRawMouseInput().A.y;

	//mCamera2->adjustHeadingPitch(0.025f * dx, 0.025f * dy);
	////mCamera2->adjustHeadingPitch(0.025f * GetRawMouseInput().A.x, 0.025f * GetRawMouseInput().A.y);
	//SetCursorPos(500, 500);
	
	//mOldCursorPosition = lMousePosition;
	//SetCursorPos(mOldCursorPosition.x, mOldCursorPosition.y);

	mCamera->Pitch(dy * gCursorSensitivity);
	mCamera->RotateY(dx * gCursorSensitivity);
	if (lMousePosition.x > 500)
		dx = 1.5f ;
	else if(lMousePosition.x < 500)
		dx = -1.5f;
	if (lMousePosition.y > 500)
		dy = 1.5f;
	else if(lMousePosition.y < 500)
		dy = -1.5f;
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