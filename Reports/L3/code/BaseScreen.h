#include <exception>
#include "Utilities.h"
#include "GameScreenState.h"


#ifndef BASESCREEN_H
#define BASESCREEN_H

//#include "ScreenHandler.h"
#include "Camera.h"
// #include "AudioHandler.h"
// #include "KeyboardInputHandler.h"




class BaseScreen
{
public:
		BaseScreen();
		virtual ~BaseScreen();
		void virtual StartUp(ID3D10Device* lDevice);
		void virtual ShutDown() = NULL;
		void virtual ActivateScreen(GameScreenState lGameScreenState) = NULL;
		void Update();
		void virtual Draw() = NULL;
		GameScreenState GetScreenState() const
		{
			return mGameScreenState;
		}
		
protected:
		GameScreenState mGameScreenState;
		static int mScore;
		Camera* mCamera;
		//AudioHandler mAudioHandler;

};

#endif
