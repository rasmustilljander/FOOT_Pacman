#ifndef Utilities_h
#define Utilities_h

// #include "Renderer.h"
#include <D3D10.h>
#include <D3DX10.h>
#define SAFE_RELEASE(x) if( x ) { (x)->Release(); (x) = NULL; }
#define SAFE_DELETE(x) if( x ) { delete(x); (x) = NULL; }
#define PI (3.14159265358979323846f)
#define TWO_PI 6.283185307179586476925286766559

static POINT gLockedCursorPoint;
const float gMovementSpeed = 20;
const float gCursosSensitivity = 0.0087266f;



#endif
