
#ifndef GAMESCREEN_H
#define GAMESCREEN_H

// #include "HUD.h"
// #include "CollisionHandler.h"
#include "BaseGameScreen.h"


class GameScreen: public BaseGameScreen
{
	public:
		GameScreen();
		~GameScreen();
		void StartUp(ID3D10Device* lDevice, ID3D10Effect* lEffect);
		void ShutDown();
	
	//	HUD* HUD;
		//CollisionHandler* collisionHandler;

	private:
		bool mSuperCandyInEffect;

};

#endif
