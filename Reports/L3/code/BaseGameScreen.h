
#ifndef __BaseGameScreen_h__
#define __BaseGameScreen_h__

// #include "GameTimer.h"
// #include "WorldHandler.h"
#include "BaseScreen.h"



class BaseGameScreen: public BaseScreen
{
public:
		BaseGameScreen();
		virtual ~BaseGameScreen();

protected:
		float mDeltaTime;
		//WorldHandler mWorldHandler;
		//GameTimer* mGameTimer;

};

#endif