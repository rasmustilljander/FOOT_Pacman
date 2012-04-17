
#ifndef __GameScreen_h__
#define __GameScreen_h__

// #include "HUD.h"
// #include "CollisionHandler.h"
#include "BaseGameScreen.h"

class HUD;
class CollisionHandler;
// class BaseGameScreen;
class GameScreen;

class GameScreen: public BaseGameScreen
{
	public:
		HUD* HUD;
		CollisionHandler* collisionHandler;

	private:
		bool mSuperCandyInEffect;

};

#endif
