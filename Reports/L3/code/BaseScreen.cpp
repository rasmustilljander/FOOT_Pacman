#include "BaseScreen.h"

BaseScreen::BaseScreen()
{
}

BaseScreen::~BaseScreen()
{
	delete mCamera2;
	delete mAudioHandler;
}



void BaseScreen::StartUp(ID3D10Device* lDevice)
{
	mScore = 0;
	mCamera2 = new Camera2();
	mCamera2->setPerspectiveProjectionLH( FieldOfView, ScreenAspect, NearPlane, FarPlane );
	mCamera2->setPositionAndView(800,100,50,0,0);
	mCamera2->setMovementSpeed(gPlayerMovementSpeed*3);

	mAudioHandler = new AudioHandler();
	mAudioHandler->Initialize();
}

