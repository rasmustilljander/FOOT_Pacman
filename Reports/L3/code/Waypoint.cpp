#include "Waypoint.h"

Waypoint::Waypoint()
{
	mAdjecentWaypoints = std::vector<Waypoint*>();
}

Waypoint::~Waypoint()
{

}

Waypoint* Waypoint::GetNextDestinationWaypoint(Waypoint* lPreviousWaypoint)
{
	int lIndex;
	for(int i = 0; 0 < 1; i++)
	{	
		lIndex = rand() % mAdjecentWaypoints.size();

		if(mAdjecentWaypoints.at(lIndex) != lPreviousWaypoint && i == 0)
			break;
	}
	return mAdjecentWaypoints.at(lIndex);
}