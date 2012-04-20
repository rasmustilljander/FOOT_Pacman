#include "BaseScreen.h"

BaseScreen::BaseScreen()
{
}

BaseScreen::~BaseScreen()
{
}



void BaseScreen::StartUp(ID3D10Device* lDevice)
{
	mCamera = new Camera();
}

