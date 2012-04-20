#include "ScreenHandler.h"



ScreenHandler::ScreenHandler()
{
}

ScreenHandler::~ScreenHandler()
{
	mDeathScreen->ShutDown();
	mGameScreen->ShutDown();
	delete mEndScreen;
	//mEndScreen->ShutDown();
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
	mScreen->Draw();
}

void ScreenHandler::Initialize(ID3D10Device* lDevice) 
{
	mDeathScreen = new DeathScreen();
	mEndScreen = new EndScreen();
	mGameScreen = new GameScreen();
	mMapScreen = new MapScreen();
	mMenuScreen = new MenuScreen();
	
	mPrevGameScreenState = Menu;
	mScreen = mMenuScreen;
}
