#include "Ghost.h"


Ghost::Ghost( D3DXVECTOR3 lPosition )
{
	mPosition = lPosition;
}

Ghost::~Ghost()
{

}

void Ghost::Update(float lDeltaTime) 
{
	if(CalculateDistance() < gGhostWaypointOffset)
		SetNextWaypoint();
	MoveTowardsWaypoint(lDeltaTime);
}

float Ghost::CalculateDistance()
{
	D3DXVECTOR3 lVector = mPosition - mDestinationWaypoint -> GetPosition();
	return D3DXVec3Length(&lVector);
}

void Ghost::SetNextWaypoint()
{
	mPosition = mDestinationWaypoint -> GetPosition();
	Waypoint* lTemp = mDestinationWaypoint;
	mDestinationWaypoint = mDestinationWaypoint -> GetNextDestinationWaypoint(mPreviousWaypoint);
	mPreviousWaypoint = lTemp;
	delete lTemp;
}

void Ghost::MoveTowardsWaypoint(float lDeltaTime)
{
	D3DXVECTOR3 lVector = mDestinationWaypoint -> GetPosition();
	if(mPosition.x < lVector.x)
		mPosition.x += gGhostMovementSpeed * lDeltaTime;
	else if(mPosition.x > lVector.x)
		mPosition.x -= gGhostMovementSpeed * lDeltaTime;
	else if(mPosition.y < lVector.y)
		mPosition.y += gGhostMovementSpeed * lDeltaTime;
	else if(mPosition.y > lVector.y)
		mPosition.y -= gGhostMovementSpeed * lDeltaTime;
}

void Ghost::SetResources()
{
	mResourceView = GetResourceLoader().GetGhostTexture();
	mResourceView2 = GetResourceLoader().GetGhostEdibleTexture();
}

void Ghost::SetupVertices()
{
	BillboardVertex* data = NULL;

	mVertexBuffer->Map( D3D10_MAP_WRITE_DISCARD, 0, reinterpret_cast< void** > ((void**)&data) );

	data[0].centerW = mPosition;
	data[0].sizeW = D3DXVECTOR2(50, 50);

	mVertexBuffer->Unmap();
}
