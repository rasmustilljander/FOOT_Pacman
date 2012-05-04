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
	mCamera->SetLens( 45, 1024/768, 0.1f, 1000); //TODO: move variables into utilities
}

