#ifndef PLAYER_H
#define PLAYER_H

#include "NonStaticGameObject.h"

class Player: public NonStaticGameObject
{
public:
	Player();
	virtual ~Player();
	
	void Update(float lDT);
	D3DXVECTOR3 GetPosition() { return mPosition; }
private:
	void SetResources();
	void SetupVertices();

};

#endif
