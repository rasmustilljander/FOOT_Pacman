#ifndef BASEGAMESCREEN_H
#define BASEGAMESCREEN_H

// #include "GameTimer.h"
#include "WorldHandler.h"
#include "BaseScreen.h"
#include "GameTimer.h"

class BaseGameScreen: public BaseScreen
{
public:
		BaseGameScreen();
		virtual ~BaseGameScreen();
		void StartUp(ID3D10Device* lDevice);

protected:
		WorldHandler* mWorldHandler;
		GameTimer* mGameTimer;

};

#endif
