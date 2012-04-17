
#ifndef __MenuObject_h__
#define __MenuObject_h__

// #include "MenuScreen.h"
// #include "EndScreen.h"
#include "GameObject.h"

class MenuScreen;
class EndScreen;
// class GameObject;
class MenuObject;

class MenuObject: public GameObject
{
	public:
		MenuScreen* menuScreen;
		EndScreen* endScreen;

};

#endif
