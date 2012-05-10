#include "BaseGameScreen.h"

BaseGameScreen::BaseGameScreen()
	: BaseScreen()
{	
	mWorldHandler = new WorldHandler();
	mGameTimer = new GameTimer();
	mGameTimer->Start();
}

BaseGameScreen::~BaseGameScreen()
{
	delete mWorldHandler;
	delete mGameTimer;
}

void BaseGameScreen::StartUp(ID3D10Device* lDevice)
{
	BaseScreen::StartUp(lDevice);
}