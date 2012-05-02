#include "KeyboardInputHandler.h"


KeyboardInputHandler::KeyboardInputHandler(void)
{
	mEscPressed = false;
}


KeyboardInputHandler::~KeyboardInputHandler(void)
{
}

bool KeyboardInputHandler::CheckPressedKey(Key lKey)
{
	switch (lKey)
	{
		case Esc :
			if (GetAsyncKeyState(VK_ESCAPE))
			{
				return CheckEscape();
			}
			else
				mEscPressed = false;

			break;
		case W :
			if (GetAsyncKeyState('W'))
				return true;
			break;
		case A:
			if (GetAsyncKeyState('A'))
				return true;
			break;
		case S:
			if (GetAsyncKeyState('S'))
				return true;
			break;
		case D:
			if (GetAsyncKeyState('D'))
				return true;
			break;
		case Up:
			if (GetAsyncKeyState(VK_UP))
				return true;
			break;
		case Left:
			if (GetAsyncKeyState(VK_LEFT))
				return true;
			break;
		case Down:
			if (GetAsyncKeyState(VK_DOWN))
				return true;
			break;
		case Right:
			if (GetAsyncKeyState(VK_RIGHT))
				return true;
			break;
		case M:
			if (GetAsyncKeyState('M'))
				return true;
			break;
	}

	return false;
}

bool KeyboardInputHandler::CheckEscape()
{
	if (mEscPressed)
		return false;
	mEscPressed = true;
	return true;
}