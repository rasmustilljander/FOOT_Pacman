#ifndef GHOST_H
#define GHOST_H

#include "NonStaticGameObject.h"

class Ghost: public NonStaticGameObject
{
public:
	Ghost();
	virtual ~Ghost();

	void Update(float lDT);
	void SetTargetPosition(D3DXVECTOR3 lTargetPosition);
private:
	void SetResources();
	void SetupVertices();


};

#endif
