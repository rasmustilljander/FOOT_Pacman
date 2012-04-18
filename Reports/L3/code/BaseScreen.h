#include <exception>
#include "Utilities.h"
#include "GameScreenState.h"


#ifndef BASESCREEN_H
#define BASESCREEN_H

//#include "ScreenHandler.h"
// #include "Camera.h"
// #include "AudioHandler.h"
// #include "KeyboardInputHandler.h"




class BaseScreen
{
public:
		BaseScreen();
		virtual ~BaseScreen();
		void virtual StartUp(ID3D10Device* lDevice, ID3D10Effect* lEffect) = NULL;
		void virtual ShutDown() = NULL;
		void virtual Activate(GameScreenState lGameScreenState) = NULL;
		GameScreenState GetScreenState() const
		{
			return mGameScreenState;
		}
		void Update();
		void Draw();
protected:
		GameScreenState mGameScreenState;
		static int mScore;
		//Camera mCamera;
		//AudioHandler mAudioHandler;

};

#endif
