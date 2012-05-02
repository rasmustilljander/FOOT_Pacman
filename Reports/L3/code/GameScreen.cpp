#include "GameScreen.h"

GameScreen::GameScreen()
	: BaseGameScreen()
{	
	//mHUD = new HUD();
}

GameScreen::~GameScreen()
{
	//delete mHUD;
}

void GameScreen::StartUp(ID3D10Device* lDevice)
{
	//BaseGameScreen::StartUp(lDevice);
	//mWorldHandler->Initialize( lDevice );
	//mHUD->Initialize( lDevice );
}

void GameScreen::ShutDown()
{

}

void GameScreen::Draw()
{
//	mHUD->Draw();
}

void GameScreen::Update(float lDeltaTime)
{
	KeyBoardMovement(lDeltaTime);
	MouseMovement();


}

void GameScreen::KeyBoardMovement(float lDeltaTime)
{
	bool w = false;
	bool a = false;
	bool s = false;
	bool d = false;
	//Forward
	if(w == true)
		mCamera->Walk(gMovementSpeed * lDeltaTime);
	//Left
	if(a == true)
		mCamera->Walk(-gMovementSpeed  * lDeltaTime);
	//Back
	if(s == true)
		mCamera->Walk(-gMovementSpeed  * lDeltaTime);
	//Right
	if(d == true)
		mCamera->Walk(gMovementSpeed  * lDeltaTime);
}

void GameScreen::MouseMovement()
{
	POINT lMousePosition;
	GetCursorPos(&lMousePosition);
	int dx = 0;
	int dy = 0;
	dx = lMousePosition.x - mOldCursorPosition.x;
	dy = lMousePosition.y - mOldCursorPosition.y;
	mCamera->Pitch(dy * gCursosSensitivity);
	mCamera->RotateY(dx * gCursosSensitivity);
	mOldCursorPosition = lMousePosition;
}

void GameScreen::ActivateScreen(GameScreenState lGameScreenState)
{
	mGameScreenState = lGameScreenState;
}