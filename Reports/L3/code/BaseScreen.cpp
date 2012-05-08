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
	mCamera->SetLens( 60, (float)1024/768, 0.1f, 1000); //TODO: move variables into utilities
	mCamera->UpdateView();

	mCamera2 = new Camera2();
	mCamera2->setPerspectiveProjectionLH( 60, (float)1024/768, 0.1f, 1000.0f );
	mCamera2->setPositionAndView(0,200,-400,0,0);
	mCamera2->setMovementSpeed(50);
}

