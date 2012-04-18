#ifndef PLAYER_H
#define PLAYER_H

#include "NonStaticGameObject.h"

class Player: public NonStaticGameObject
{
public:
	Player();
	virtual ~Player();
	
	Update(float lDT);

};

#endif
