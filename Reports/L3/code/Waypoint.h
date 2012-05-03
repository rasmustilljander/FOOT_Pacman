#ifndef WAYPOINT_H
#define WAYPOINT_H

#include <vector>
#include "Utilities.h"

class Waypoint
{
public:
	Waypoint();
	Waypoint(D3DXVECTOR3 lPosition);
	virtual ~Waypoint();

	void AddAdjecentWaypoint(Waypoint* lWaypoint);

	Waypoint* GetNextDestinationWaypoint(Waypoint* lPreviousWaypoint);
	
	D3DXVECTOR3 GetPosition() const
	{
		return this -> mPosition;
	}

private:
	D3DXVECTOR3 mPosition;
	std::vector<Waypoint*> mAdjecentWaypoints;

};

#endif
