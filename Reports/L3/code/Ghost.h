#ifndef GHOST_H
#define GHOST_H

#include "NonStaticGameObject.h"
#include "Waypoint.h"

class Ghost: public NonStaticGameObject
{
public:
	Ghost();
	Ghost(D3DXVECTOR3 lPosition, Waypoint* lWaypoint);
	virtual ~Ghost();

	void Update(float lDeltaTime);
	void Eaten();

private:
	float	CalculateDistance();
	void	SetNextWaypoint();
	void	MoveTowardsWaypoint(float lDeltaTime);
	void	IsEdible(bool lIsEdible);
	void	SetResources();
	void	SetupVertices();

private:
	ID3D10ShaderResourceView* mResourceView2;
	Waypoint* mDestinationWaypoint;
	Waypoint* mPreviousWaypoint;
	Waypoint* mStartWaypoint;
	D3DXVECTOR3 mSpawnPosition;

};

#endif
