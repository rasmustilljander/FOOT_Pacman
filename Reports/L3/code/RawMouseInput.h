#ifndef RAWMOUSEINPUT_H
#define RAWMOUSEINPUT_H

#include "Utilities.h"

class RawMouseInput
{
public:
	RawMouseInput() {}
	~RawMouseInput(){}

	//register keyboard mouse as input devices!
	bool RegisterInputDevices( HWND &hWnd )
	{
		RAWINPUTDEVICE inputDevices[1];
        
		//adds mouse and allow legacy messages
		inputDevices[0].usUsagePage = 0x01; 
		inputDevices[0].usUsage = 0x02; 
		inputDevices[0].dwFlags = 0;   
		inputDevices[0].hwndTarget = 0;

		if ( RegisterRawInputDevices(inputDevices, 1, sizeof(inputDevices[0]) ) == FALSE ) 
		{
			return false;
		}

		return true;
	}
	POINT A;

private:
};


RawMouseInput& GetRawMouseInput();

#endif