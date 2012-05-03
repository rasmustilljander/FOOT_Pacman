#ifndef GHOST_H
#define GHOST_H

#include "NonStaticGameObject.h"
#include "Waypoint.h"

int main()
	{
		return 0;
}

class Ghost: public NonStaticGameObject
{
public:
	Ghost(D3DXVECTOR3 lPosition);
	virtual ~Ghost();

	void Update(float lDeltaTime);

private:
	float	CalculateDistance();
	void	SetNextWaypoint();
	void	MoveTowardsWaypoint(float lDeltaTime);
	void	SetResources();
	void	SetupVertices();

private:
	ID3D10ShaderResourceView* mResourceView2;
	Waypoint* mDestinationWaypoint;
	Waypoint* mPreviousWaypoint;



};

#endif
