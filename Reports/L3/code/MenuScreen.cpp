
#include "MenuScreen.h"

MenuScreen::MenuScreen()
	: BaseScreen()
{
}

MenuScreen::~MenuScreen()
{
}

void MenuScreen::StartUp(ID3D10Device* lDevice)
{
	BaseScreen::StartUp(lDevice);
}

void MenuScreen::ShutDown()
{
}

void MenuScreen::Draw()
{
}

void MenuScreen::Update()
{
	if(GetAsyncKeyState(VK_TAB) & 0x8000)
		mGameScreenState = End;
	OutputDebugString("Yay\n");
}

void MenuScreen::ActivateScreen(GameScreenState lGameScreenState)
{
	mGameScreenState = lGameScreenState;
}
