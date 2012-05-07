#include "EndScreen.h"

EndScreen::EndScreen()
	: BaseScreen()
{
}

EndScreen::~EndScreen()
{
}

void EndScreen::StartUp(ID3D10Device* lDevice)
{
	BaseScreen::StartUp(lDevice);
}

void EndScreen::ShutDown()
{
	
}

void EndScreen::Draw()
{
}

void EndScreen::Update()
{
	if(GetAsyncKeyState(VK_BACK) & 0x8000)
		mGameScreenState = Menu;
	
}

void EndScreen::ActivateScreen(GameScreenState lGameScreenState)
{
	mGameScreenState = lGameScreenState;
}