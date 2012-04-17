#include <exception>
using namespace std;

#ifndef __WorldHandler_h__
#define __WorldHandler_h__

// #include "BaseGameScreen.h"
// #include "QuadTree.h"
// #include "Waypoints.h"
// #include "WallObject.h"

class BaseGameScreen;
class QuadTree;
class Waypoints;
class WallObject;
class WorldHandler;

class WorldHandler
{
	public:
		BaseGameScreen* baseGameScreen;
		QuadTree* quadTree;
		Waypoints* waypoints;
		WallObject* wallObject;

		void Initialize(ID3D10Device* lDevice, ID3D10Effect* lEffect);
	private:
		Waypoint mWaypoint[];

};

#endif
