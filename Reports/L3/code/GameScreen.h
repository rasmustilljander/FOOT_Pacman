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
		void Update(float lDeltaTime);
		void KeyBoardMovement(float lDeltaTime);
		void MouseMovement();
		void ActivateScreen(GameScreenState lGameScreenState);
		

	private:
		bool mSuperCandyInEffect;
		HUD* mHUD;
		POINT mOldCursorPosition;
		//CollisionHandler* collisionHandler;
};

#endif
