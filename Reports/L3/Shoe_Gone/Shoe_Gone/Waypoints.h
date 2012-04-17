
#ifndef __Waypoints_h__
#define __Waypoints_h__

// #include "WorldHandler.h"

class WorldHandler;
class Waypoints;

class Waypoints
{
	public:
		WorldHandler* worldHandler;

	private:
		D3DXVector3 mPosition;
		Waypoint mAdjecentWaypoints[];

};

#endif
