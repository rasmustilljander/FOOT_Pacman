
#include "DeathScreen.h"

DeathScreen::DeathScreen()
	: BaseGameScreen()
{

}

DeathScreen::~DeathScreen()
{

}

void DeathScreen::StartUp(ID3D10Device* lDevice)
{
	BaseGameScreen::StartUp(lDevice);
}
void DeathScreen::ShutDown()
{
	this->~DeathScreen();
}

void DeathScreen::ActivateScreen(GameScreenState lGameScreenState)
{
	mGameScreenState = lGameScreenState;
}

void DeathScreen::Draw()
{
}

void DeathScreen::Update()
{
}