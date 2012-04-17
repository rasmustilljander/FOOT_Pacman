
#ifndef __WallObject_h__
#define __WallObject_h__

// #include "WorldHandler.h"
#include "GameObject.h"

class WorldHandler;
// class GameObject;
class WallObject;

class WallObject: public GameObject
{
	public:
		WorldHandler* worldHandler;

	private:
		D3DXVECTOR3 mPosition;

};

#endif
