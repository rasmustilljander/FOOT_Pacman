#ifndef PLAYER_H
#define PLAYER_H

#include "NonStaticGameObject.h"

class Player: public NonStaticGameObject
{
public:
	Player();
	virtual ~Player();
	
	void SetPosition(D3DXVECTOR3 lPos);
	void Update(float lDT);
	D3DXVECTOR3 GetPosition() { return mPosition; }
	D3DXVECTOR3 GetOldPosition() { return mOldPosition; }
private:
	void SetResources();
	void SetupVertices();
private:
	D3DXVECTOR3 mOldPosition;

};

#endif
