#include <Windows.h>
#include "Renderer.h"
#include "RawMouseInput.h"

HWND		g_hWnd;
HINSTANCE	g_hInst;

HRESULT             InitWindow( HINSTANCE hInstance, int nCmdShow );
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);



//--------------------------------------------------------------------------------------
// Entry point to the program. Initializes everything and goes into a message processing 
// loop. Idle time is used to render the scene.
//--------------------------------------------------------------------------------------
int WINAPI wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow )
{
	Renderer renderer;
	
	if( FAILED( InitWindow( hInstance, nCmdShow ) ) )
		return 0;

	renderer.Initialize(&g_hWnd);

	// Main message loop
	MSG msg = {0};
	while(WM_QUIT != msg.message)
	{
		while( PeekMessage( &msg, NULL, 0, 0, PM_REMOVE) == TRUE )
		{
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
		renderer.Update();
		renderer.Draw();
	}
	return (int) msg.wParam;
}


//--------------------------------------------------------------------------------------
// Register class and create window
//--------------------------------------------------------------------------------------
HRESULT InitWindow( HINSTANCE hInstance, int nCmdShow )
{
	// Register class
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX); 
	wcex.style          = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc    = WndProc;
	wcex.cbClsExtra     = 0;
	wcex.cbWndExtra     = 0;
	wcex.hInstance      = hInstance;
	wcex.hIcon          = 0;
	wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName   = NULL;
	wcex.lpszClassName  = "Shoe-gone";
	wcex.hIconSm        = 0;
	if( !RegisterClassEx(&wcex) )
		return E_FAIL;

	// Create window
	g_hInst = hInstance; 
	RECT rc = { 0, 0, 1024, 768 };


	AdjustWindowRect( &rc, WS_OVERLAPPEDWINDOW, FALSE );
	
	if(!(g_hWnd = CreateWindow(	"Shoe-gone",
							"Shoe-gone",
							WS_OVERLAPPEDWINDOW,
							CW_USEDEFAULT,
							CW_USEDEFAULT,
							rc.right - rc.left,
							rc.bottom - rc.top,
							NULL,
							NULL,
							hInstance,
							NULL)))
	{
		return E_FAIL;
	}
	GetRawMouseInput().RegisterInputDevices(g_hWnd);

	
	ShowWindow( g_hWnd, nCmdShow );
	return S_OK;
}

//--------------------------------------------------------------------------------------
// Called every time the application receives a message
//--------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message) 
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_INPUT: 
    {
        UINT dwSize = 40;
        static BYTE lpb[40];
    
        GetRawInputData((HRAWINPUT)lParam, RID_INPUT, 
                        lpb, &dwSize, sizeof(RAWINPUTHEADER));
    
        RAWINPUT* raw = (RAWINPUT*)lpb;
    
        if (raw->header.dwType == RIM_TYPEMOUSE) 
        {
            
			GetRawMouseInput().A.x = raw->data.mouse.lLastX;
			GetRawMouseInput().A.y = raw->data.mouse.lLastY;

			int a = GetRawMouseInput().A.x;
			int b = GetRawMouseInput().A.y;
			int c = 5;
			//int xPosRelative = raw->data.mouse.lLastX;
            //int yPosRelative = raw->data.mouse.lLastY;
        }
        break;
    }

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}
