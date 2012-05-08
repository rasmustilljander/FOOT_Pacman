#include "Waypoint.h"

Waypoint::Waypoint()
{
	mPosition = D3DXVECTOR3(0,0,0);
	mAdjecentWaypoints = std::vector<Waypoint*>();
}

Waypoint::Waypoint(D3DXVECTOR3 lPosition)
{
	mPosition = lPosition;
	mAdjecentWaypoints = std::vector<Waypoint*>();
}

Waypoint::~Waypoint()
{

}

void Waypoint::AddAdjecentWaypoint(Waypoint* lWaypoint)
{
	mAdjecentWaypoints.push_back(lWaypoint);
}


Waypoint* Waypoint::GetNextDestinationWaypoint(Waypoint* lPreviousWaypoint)
{
	int lIndex;
	for(int i = 0; i < 1; i++)
	{	
		lIndex = rand() % mAdjecentWaypoints.size();

		if(mAdjecentWaypoints.at(lIndex) != lPreviousWaypoint && i == 0)
			break;
	}
	return mAdjecentWaypoints.at(lIndex);
}