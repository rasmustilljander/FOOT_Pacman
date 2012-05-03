#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "HUD.h"
// #include "CollisionHandler.h"
#include "BaseGameScreen.h"
#include "Player.h"
#include "KeyboardInputHandler.h"


class GameScreen: public BaseGameScreen
{
	public:
		GameScreen();
		~GameScreen();
		void StartUp(ID3D10Device* lDevice);
		void ShutDown();
		void Draw();
		void Update();
		void KeyBoardMovement(float lDeltaTime);
		void MouseMovement();
		void ActivateScreen(GameScreenState lGameScreenState);
		

	private:
		bool mSuperCandyInEffect;
		HUD* mHUD;
		Player* mPacman;
		POINT mOldCursorPosition;
		//CollisionHandler* collisionHandler;
		KeyboardInputHandler* mKeyboardHandler;
};

#endif
