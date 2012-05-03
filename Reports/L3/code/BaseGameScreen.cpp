#include "BaseGameScreen.h"

BaseGameScreen::BaseGameScreen()
	: BaseScreen()
{
	mGameTimer = new GameTimer();
	mGameTimer->Start();
}

BaseGameScreen::~BaseGameScreen()
{

}

void BaseGameScreen::StartUp(ID3D10Device* lDevice)
{
	BaseScreen::StartUp(lDevice);
}