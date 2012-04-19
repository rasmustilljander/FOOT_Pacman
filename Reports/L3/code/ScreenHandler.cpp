#include "ScreenHandler.h"

int main()
{
	return 0;
}

ScreenHandler::ScreenHandler()
{
}

ScreenHandler::~ScreenHandler()
{
	mDeathScreen->ShutDown();
	mGameScreen->ShutDown();
	mEndScreen->ShutDown();
	mMenuScreen->ShutDown();
	mMapScreen->ShutDown();
}

void ScreenHandler::Update() 
{
	//throw "Not yet implemented";
	mScreen->Update();
	if(mScreen->GetScreenState() != mPrevGameScreenState)
	{
		SwapScreenState(mScreen->GetScreenState());
	}
}

void ScreenHandler::SwapScreenState(GameScreenState lGameScreenState)
{
	if(lGameScreenState == Death)
		mScreen = mDeathScreen;
	else if(lGameScreenState == Ingame)
		mScreen = mGameScreen;
	else if(lGameScreenState == End)
		mScreen = mEndScreen;
	else if(lGameScreenState == Menu)
		mScreen = mMenuScreen;
	else if(lGameScreenState == Map)
		mScreen = mMapScreen;
	else
		return;
	mPrevGameScreenState = mScreen->GetScreenState();
	
}

void ScreenHandler::Draw() 
{
	//throw "Not yet implemented";
	mScreen->Draw();
}

void ScreenHandler::Initialize(ID3D10Device* lDevice) 
{
	////throw "Not yet implemented";
	
	mDeathScreen->StartUp(lDevice);
	mEndScreen->StartUp(lDevice);
	mGameScreen->StartUp(lDevice);
	mMapScreen->StartUp(lDevice);
	mMenuScreen->StartUp(lDevice);
	
	
	mPrevGameScreenState = Menu;
	mScreen = mMenuScreen;
}

