#ifndef GHOST_H
#define GHOST_H

#include "NonStaticGameObject.h"

class Ghost: public NonStaticGameObject
{
public:
	void Update();
	void Move(float dt);
	void SetTargetPosition(D3DXVECTOR lTargetPosition);


};

#endif
