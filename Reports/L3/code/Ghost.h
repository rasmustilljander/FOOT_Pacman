#ifndef GHOST_H
#define GHOST_H

#include "NonStaticGameObject.h"

class Ghost: public NonStaticGameObject
{
public:
	Ghost();
	virtual ~Ghost();

	void Update();
	void Move(float dt);
	void SetTargetPosition(D3DXVECTOR lTargetPosition);


};

#endif
