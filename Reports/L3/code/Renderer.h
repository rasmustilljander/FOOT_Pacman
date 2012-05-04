#include <exception>
using namespace std;

#ifndef __Renderer_h__
#define __Renderer_h__

#include "Utilities.h"
//#include "ScreenHandler.h"
#include "WorldHandler.h"
#include "Camera.h"

class Renderer
{
public:
		Renderer();
		~Renderer();
		void Update();
		void Draw();
		void Initialize(HWND* lHwnd);
private:
		void CreateSwapChain();
		void SetUpViewPort();
		void CreateBackBufferAndRenderTarget();
private:
	UINT					mWidth, mHeight;
	HWND*					hWnd;

	D3D10_DRIVER_TYPE       mDriverType;
	ID3D10Device*           mDevice;
	IDXGISwapChain*         mSwapChain;
	ID3D10RenderTargetView* mRenderTargetView;
	ID3D10Texture2D*        mDepthStencil;
	ID3D10DepthStencilView* mDepthStencilView;
	ID3D10RasterizerState*	mRastState;

	//ScreenHandler* mScreenHandler;
	WorldHandler* mWorld;
	Camera* cam;

};

#endif
