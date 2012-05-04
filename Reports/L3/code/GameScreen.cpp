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

	//mHUD->Initialize( lDevice );
	mWorldHandler->Initialize( lDevice );
}

void GameScreen::ShutDown()
{

}

void GameScreen::Draw()
{
	//mHUD->Draw();
	mWorldHandler->Draw( mCamera );
}

void GameScreen::Update()
{
	mGameTimer->Tick();
	KeyBoardMovement(mGameTimer->GetDeltaTime()); //needs deltatime value
	MouseMovement();

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

void GameScreen::ActivateScreen(GameScreenState lGameScreenState)
{
	mGameScreenState = lGameScreenState;
}