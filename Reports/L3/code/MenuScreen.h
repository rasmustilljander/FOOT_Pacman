
#ifndef __MenuScreen_h__
#define __MenuScreen_h__

// #include "MenuObject.h"
#include "BaseScreen.h"

class MenuObject;
// class BaseScreen;
class MenuScreen;

class MenuScreen: public BaseScreen
{
	public:
		MenuScreen* menuScreen;
		MenuObject* menuObject;

};

#endif
