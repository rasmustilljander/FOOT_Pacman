
#ifndef __DeathScreen_h__
#define __DeathScreen_h__

// #include "Player.h"
#include "BaseGameScreen.h"

class Player;
// class BaseGameScreen;
class DeathScreen;

class DeathScreen: public BaseGameScreen
{
	public:
		Player* player;

};

#endif
