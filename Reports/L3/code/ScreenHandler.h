#include <exception>
using namespace std;

#ifndef __ScreenHandler_h__
#define __ScreenHandler_h__

// #include "Renderer.h"
// #include "ScreenStateStruct.h"
// #include "BaseScreen.h"
// #include "GameScreenState.h"

class Renderer;
class ScreenStateStruct;
class BaseScreen;
// enum GameScreenState;
class ScreenHandler;

class ScreenHandler
{
	public:
		Renderer* renderer;
		ScreenStateStruct* screenStateStruct;
		BaseScreen* baseScreen;
		GameScreenState* gameScreenState;

		void Update();
		void Draw();
		void Initialize(ID3D10Device* lDevice, ID3D10Effect* lEffect);
	private:
		ScreenStateStruct mScreenStateStruct;
		GameScreen* mGameScreen;
		DeathScreen* mDeathScreen;
		mGameScreen* mMapScreen;
		EndScreen* mEndScreen;
		MenuScreen* mMenuScreen;

};

#endif
