#include <exception>
using namespace std;

#ifndef __BaseScreen_h__
#define __BaseScreen_h__

// #include "ScreenHandler.h"
// #include "Camera.h"
// #include "AudioHandler.h"
// #include "KeyboardInputHandler.h"

class ScreenHandler;
class Camera;
class AudioHandler;
class KeyboardInputHandler;
class BaseScreen;

class BaseScreen
{
	public:
		ScreenHandler* screenHandler;
		Camera* camera;
		AudioHandler* audioHandler;
		KeyboardInputHandler* keyboardInputHandler;

		void Initialize(ID3D10Device* lDevice, ID3D10Effect* lEffect);
		void Update();
		void Draw();
	protected:
		static int mScore;
		Camera mCamera;
		AudioHandler mAudioHandler;

};

#endif
