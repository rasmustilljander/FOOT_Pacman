#include <exception>

#include "BaseScreen.h"
#include "GameScreen.h"
#include "MapScreen.h"
#include "DeathScreen.h"
#include "EndScreen.h"
#include "MenuScreen.h"

#ifndef SCREENHANDLER_H
#define SCREENHANDLER_H

// #include "Renderer.h"



class ScreenHandler
{
public:
	ScreenHandler();
	~ScreenHandler();
	void Update();
	void Draw();
	void Initialize(ID3D10Device* lDevice, ID3D10Effect* lEffect);

private:
	void SwapScreenState(GameScreenState lScreenState);

private:	
	GameScreen* mGameScreen;
	DeathScreen* mDeathScreen;
	MapScreen* mMapScreen;
	EndScreen* mEndScreen;
	MenuScreen* mMenuScreen;
	BaseScreen* mScreen;

	
	GameScreenState mPrevGameScreenState;

};

#endif
