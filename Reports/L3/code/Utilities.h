#ifndef UTILITIES_H
#define UTILITIES_H

#include <D3D10.h>
#include <D3DX10.h>
#define SAFE_RELEASE(x) if( x ) { (x)->Release(); (x) = NULL; }
#define SAFE_DELETE(x) if( x ) { delete(x); (x) = NULL; }
#define PI (3.14159265358979323846f)
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.01745329251994329576923690768489

//Game Specific Things
#define gPlayerMovementSpeed 50
#define gPlayerYPosition 50
#define gGhostMovementSpeed 2
#define gCursorSensitivity 0.0087266f
#define gGhostWaypointOffset 10

static POINT gLockedCursorPoint;

template<typename T>
D3DX10INLINE T Min(const T& a, const T& b)
{
	return a < b ? a : b;
};

#endif
