#include <exception>
using namespace std;

#ifndef __AudioHandler_h__
#define __AudioHandler_h__

// #include "BaseScreen.h"

class BaseScreen;
class AudioHandler;

class AudioHandler
{
	public:
		BaseScreen* baseScreen;

		void PlayGhostAudio();
		void PlayCandyAudio();
};

#endif
