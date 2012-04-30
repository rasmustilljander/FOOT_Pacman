#include "ScreenHandler.h"



ScreenHandler::ScreenHandler()
{
	
}

ScreenHandler::~ScreenHandler()
{
	delete mDeathScreen;
	delete mEndScreen;
	delete mGameScreen;
	delete mMenuScreen;
	delete mMapScreen;
	//mDeathScreen->ShutDown();
	//mGameScreen->ShutDown();
	//mEndScreen->ShutDown();
	//mMenuScreen->ShutDown();
	//mMapScreen->ShutDown();
}

void ScreenHandler::Update() 
{
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
	ScreenStartUp(lDevice);
	ResourceLoader.GetResourceLoader().LoadTextures(lDevice);

	mPrevGameScreenState = Menu;
	mScreen = mMenuScreen;
}

void ScreenHandler::ScreenStartUp(ID3D10Device* lDevice)
{
	mDeathScreen->StartUp(lDevice);
	mEndScreen->StartUp(lDevice);
	mGameScreen->StartUp(lDevice);
	mMapScreen->StartUp(lDevice);
	mMenuScreen->StartUp(lDevice);
}
