#include <exception>
using namespace std;

#ifndef __GameTimer_h__
#define __GameTimer_h__

// #include "BaseGameScreen.h"

class BaseGameScreen;
class GameTimer;

class GameTimer
{
	public:
		BaseGameScreen* baseGameScreen;

		void Reset();
		void Start();
		double GetElapsedTimeSeconds();
		double GetElapsedTimeMilliseconds();
};

#endif
