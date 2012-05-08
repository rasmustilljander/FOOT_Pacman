#include "RawMouseInput.h"

RawMouseInput& GetRawMouseInput()
{
	static RawMouseInput mRawMouseInput; 
	return mRawMouseInput;
}