
#ifndef MAPSCREEN_H
#define MAPSCREEN_H

#include "BaseScreen.h"


class MapScreen: public BaseScreen
{

public:
	MapScreen();
	~MapScreen();
	void StartUp(ID3D10Device* lDevice, ID3D10Effect* lEffect);
	void ShutDown();



};

#endif