#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "HUD.h"
// #include "CollisionHandler.h"
#include "BaseGameScreen.h"
#include "Player.h"
#include "KeyboardInputHandler.h"
#include "Ghost.h"

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
	void LoadGhosts();
		
private:
	void UpdateGhost(float lDeltaTime);

private:
	bool mSuperCandyInEffect;
	HUD* mHUD;
	Player* mPacman;
	POINT mOldCursorPosition;
	//CollisionHandler* collisionHandler;
	KeyboardInputHandler* mKeyboardHandler;
	vector<Ghost*> mGhost;

	private:
		bool mSuperCandyInEffect;
		HUD* mHUD;
		Player* mPacman;
		POINT mOldCursorPosition;
		//CollisionHandler* collisionHandler;
		KeyboardInputHandler* mKeyboardHandler;
};

#endif
