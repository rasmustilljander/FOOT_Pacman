#include <exception>
using namespace std;

#ifndef __Renderer_h__
#define __Renderer_h__

// #include "Main.h"
// #include "ScreenHandler.h"

class Main;
class ScreenHandler;
class Renderer;

class Renderer
{
	public:
		Main* main;
		ScreenHandler* screenHandler;

		void Update();
		void Draw();
		void Initialize();
	private:
		ScreenHandler* mScreenHandler;

		void SetUpViewPort();
		void CreateBackBuffer();
};

#endif
