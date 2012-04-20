
#include "BaseGameScreen.h"


BaseGameScreen::BaseGameScreen()
	: BaseScreen()
{
	mWorldHandler = new WorldHandler();
}
BaseGameScreen::~BaseGameScreen()
{
}

void BaseGameScreen::StartUp(ID3D10Device* lDevice)
{
	BaseScreen::StartUp(lDevice);
}