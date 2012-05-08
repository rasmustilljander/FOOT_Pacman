#ifndef KEYBOARDINPUTHANDLER_H
#define KEYBOARDINPUTHANDLER_H

#include <Windows.h>

enum Key { Esc, W, A, S, D, Up, Left, Down, Right, M };

class KeyboardInputHandler
{
public:
	KeyboardInputHandler(void);
	~KeyboardInputHandler(void);

	bool CheckPressedKey(Key lKey);

private:
	bool CheckEscape();

private:
	bool mEscPressed;
};

#endif