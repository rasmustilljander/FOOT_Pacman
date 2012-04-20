
#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "HUD.h"
// #include "CollisionHandler.h"
#include "BaseGameScreen.h"


class GameScreen: public BaseGameScreen
{
	public:
		GameScreen();
		~GameScreen();
		void StartUp(ID3D10Device* lDevice);
		void ShutDown();
		void Draw();
		void ActivateScreen(GameScreenState lGameScreenState);
		

	private:
		bool mSuperCandyInEffect;
		HUD* mHUD;
		//CollisionHandler* collisionHandler;
};

#endif
