using namespace std;

#include "Renderer.h"
#include "ScreenHandler.h"

Renderer::Renderer():	mDriverType(D3D10_DRIVER_TYPE_NULL),
						mDevice(NULL),
						mSwapChain(NULL),
						mRenderTargetView(NULL),
						mDepthStencil(NULL),
						mDepthStencilView(NULL)
{
	mScreenHandler = new ScreenHandler();
}

Renderer::~Renderer()
{
	delete mScreenHandler;
	SAFE_RELEASE(mDevice);
}

void Renderer::Update() 
{
	mScreenHandler->Update();
}

void Renderer::Draw() 
{
	mDevice->ClearRenderTargetView( mRenderTargetView, D3DXCOLOR(0.05f,0.5f, 0.8f, 0.0f));
	mDevice->ClearDepthStencilView( mDepthStencilView, D3D10_CLEAR_DEPTH, 1.0f, 0 );

	mScreenHandler->Draw();
	mSwapChain->Present( 1, 0 );
}

void Renderer::Initialize(HWND* lHwnd) 
{
	hWnd = lHwnd;
	RECT rc;
	GetClientRect( *hWnd, &rc );
	mWidth = rc.right - rc.left;
	mHeight = rc.bottom - rc.top;

	CreateSwapChain();
	SetUpViewPort();
	CreateBackBufferAndRenderTarget();

	mScreenHandler->Initialize(mDevice);
}

void Renderer::CreateSwapChain()
{
			UINT createDeviceFlags = 0;
#ifdef _DEBUG
	createDeviceFlags |= D3D10_CREATE_DEVICE_DEBUG;
#endif

	D3D10_DRIVER_TYPE driverTypes[] = 
	{
		D3D10_DRIVER_TYPE_HARDWARE,
	};
	UINT numDriverTypes = sizeof(driverTypes) / sizeof(driverTypes[0]);

	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory( &sd, sizeof(sd) );
	sd.BufferCount = 2;
	sd.BufferDesc.Width = mWidth;
	sd.BufferDesc.Height = mHeight;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = *hWnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;

	//Create D3D Device
	//----------------------------------------------------------------------------------------------------
	for( UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++ )
	{
		mDriverType = driverTypes[driverTypeIndex];
		D3D10CreateDeviceAndSwapChain( NULL, mDriverType, NULL, createDeviceFlags, 
			D3D10_SDK_VERSION, &sd, &mSwapChain, &mDevice );
	}

}

void Renderer::SetUpViewPort() 
{
	D3D10_VIEWPORT vp;
	vp.Width = mWidth;
	vp.Height = mHeight;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	mDevice->RSSetViewports( 1, &vp );

	//set rasterizer state
	//--------------------------------------------------------------
	
	D3D10_RASTERIZER_DESC rasterizerState;
	rasterizerState.CullMode = D3D10_CULL_NONE;
	rasterizerState.FillMode = D3D10_FILL_SOLID;
	rasterizerState.FrontCounterClockwise = false;
    rasterizerState.DepthBias = false;
    rasterizerState.DepthBiasClamp = 0;
    rasterizerState.SlopeScaledDepthBias = 0;
    rasterizerState.DepthClipEnable = true;
    rasterizerState.ScissorEnable = false;
    rasterizerState.MultisampleEnable = false;
    rasterizerState.AntialiasedLineEnable = true;		
	
	mDevice->CreateRasterizerState( &rasterizerState, &mRastState);
	mDevice->RSSetState(mRastState);
}

void Renderer::CreateBackBufferAndRenderTarget() 
{
	ID3D10Texture2D* pBackBuffer;
	mSwapChain->GetBuffer( 0, __uuidof( ID3D10Texture2D ), (LPVOID*)&pBackBuffer );

	mDevice->CreateRenderTargetView( pBackBuffer, NULL, &mRenderTargetView );
	pBackBuffer->Release();

	// Create depth stencil texture
	D3D10_TEXTURE2D_DESC descDepth;
	descDepth.Width = mWidth;
	descDepth.Height = mHeight;
	descDepth.MipLevels = 1;
	descDepth.ArraySize = 1;
	descDepth.Format = DXGI_FORMAT_D32_FLOAT;
	descDepth.SampleDesc.Count = 1;
	descDepth.SampleDesc.Quality = 0;
	descDepth.Usage = D3D10_USAGE_DEFAULT;
	descDepth.BindFlags = D3D10_BIND_DEPTH_STENCIL;
	descDepth.CPUAccessFlags = 0;
	descDepth.MiscFlags = 0;
	mDevice->CreateTexture2D( &descDepth, NULL, &mDepthStencil );

	// Create the depth stencil view
	D3D10_DEPTH_STENCIL_VIEW_DESC descDSV;
	descDSV.Format = descDepth.Format;
	descDSV.ViewDimension = D3D10_DSV_DIMENSION_TEXTURE2D;
	descDSV.Texture2D.MipSlice = 0;
	mDevice->CreateDepthStencilView( mDepthStencil, &descDSV, &mDepthStencilView );
	
	mDevice->OMSetRenderTargets( 1, &mRenderTargetView, mDepthStencilView );
}

