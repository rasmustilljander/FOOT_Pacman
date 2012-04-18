#include <exception>
using namespace std;

#ifndef __Renderer_h__
#define __Renderer_h__

#include "Utilities.h"
// #include "ScreenHandler.h"

class Renderer
{
	public:
		Main* main;
		//ScreenHandler* screenHandler;

		void Update();
		void Draw();
		void Initialize();
	private:
		ScreenHandler* mScreenHandler;

		void SetUpViewPort();
		void CreateBackBuffer();
};

#endif
