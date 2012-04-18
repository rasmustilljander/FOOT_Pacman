
#ifndef DEATHSCREEN_H
#define DEATHSCREEN_H

// #include "Player.h"
#include "BaseGameScreen.h"



class DeathScreen: public BaseGameScreen
{
public:
		
		void StartUp(ID3D10Device* lDevice, ID3D10Effect* lEffect);
		void ShutDown();
		void ActivateScreen(
		//Player* player;
private:
	DeathScreen();
	~DeathScreen();
};

#endif
