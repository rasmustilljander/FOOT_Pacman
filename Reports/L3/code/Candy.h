#ifndef CANDY_H
#define CANDY_H

#include "GameObject.h"

class Candy: public GameObject
{
public:
	Candy();
	Candy(int lType, D3DXVECTOR3 lPosition);
	virtual ~Candy();
	int GetType() { return mType; }

private:
	void SetResources();
	void SetupVertices();
private:
	int mType;
};

#endif
