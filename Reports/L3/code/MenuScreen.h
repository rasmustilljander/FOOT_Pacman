
#ifndef MENUSCREEN_H
#define MENUSCREEN_H

// #include "MenuObject.h"
#include "BaseScreen.h"


class MenuScreen: public BaseScreen
{
public:
	MenuScreen();
	~MenuScreen();
	void StartUp(ID3D10Device* lDevice, ID3D10Effect* lEffect);
	void ShutDown();


};

#endif