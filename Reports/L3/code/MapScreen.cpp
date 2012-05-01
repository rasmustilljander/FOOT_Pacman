
#include "MapScreen.h"


MapScreen::MapScreen()
	: BaseScreen()
{
}

MapScreen::~MapScreen()
{
}

void MapScreen::StartUp(ID3D10Device* lDevice)
{
	BaseScreen::StartUp(lDevice);
}

void MapScreen::ShutDown()
{
}

void MapScreen::Draw()
{
}

void MapScreen::Update()
{
}

void MapScreen::ActivateScreen(GameScreenState lGameScreenState)
{
	mGameScreenState = lGameScreenState;
}