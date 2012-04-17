
#ifndef __Player_h__
#define __Player_h__

// #include "DeathScreen.h"
#include "NonStaticGameObject.h"

class DeathScreen;
// class NonStaticGameObject;
class Player;

class Player: public NonStaticGameObject
{
	public:
		DeathScreen* deathScreen;

};

#endif
