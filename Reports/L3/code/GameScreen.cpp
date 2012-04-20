
#include "GameScreen.h"

GameScreen::GameScreen()
	: BaseGameScreen()
{	
	mHUD = new HUD();
}

GameScreen::~GameScreen()
{

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
	mHUD->Draw();
}

void GameScreen::Update()
{
}

void GameScreen::ActivateScreen(GameScreenState lGameScreenState)
{
}