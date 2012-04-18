
#ifndef ENDSCREEN_H
#define ENDSCREEN_H

// #include "MenuObject.h"
#include "BaseScreen.h"


class EndScreen: public BaseScreen
{
public:
	EndScreen();
	~EndScreen();
	void StartUp(ID3D10Device* lDevice, ID3D10Effect* lEffect);
	void ShutDown();

};

#endif
