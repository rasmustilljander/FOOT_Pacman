#include "Ghost.h"

Ghost::Ghost()
{
	mDestinationWaypoint = NULL;
	mPreviousWaypoint = NULL;
	mStartWaypoint = NULL;
	mSpawnPosition = D3DXVECTOR3(0,0,0);
}
Ghost::Ghost(D3DXVECTOR3 lPosition, Waypoint* lWaypoint)
{
	mPosition = lPosition;
	mDestinationWaypoint = lWaypoint;
	mStartWaypoint = mDestinationWaypoint;
	mSpawnPosition = mPosition;
}

Ghost::~Ghost()
{
	delete mResourceView2;
	delete mDestinationWaypoint;
	delete mPreviousWaypoint;
	delete mStartWaypoint;
}

void Ghost::Update(float lDeltaTime) 
{		
	if(CalculateDistance() < gGhostWaypointOffset)
		SetNextWaypoint();
	MoveTowardsWaypoint(lDeltaTime);

	//IsEdible(bool(rand() % 2)); //TODO get the real isedible bool and insert it here m8
}

float Ghost::CalculateDistance()
{
	D3DXVECTOR3 lVector = mPosition - mDestinationWaypoint -> GetPosition();
	float lDistance = D3DXVec3Length(&lVector);
	if(lDistance < 30)
		int lol = 2;
	return lDistance;
}

void Ghost::SetNextWaypoint()
{
	mPosition = mDestinationWaypoint -> GetPosition();
	Waypoint* lTemp = mDestinationWaypoint;
	mDestinationWaypoint = mDestinationWaypoint -> GetNextDestinationWaypoint(mPreviousWaypoint);
	mPreviousWaypoint = lTemp;
}

void Ghost::MoveTowardsWaypoint(float lDeltaTime)
{
	D3DXVECTOR3 lVector = mDestinationWaypoint -> GetPosition();
	if(mPosition.x < lVector.x)
		mPosition.x += gGhostMovementSpeed * 6  * lDeltaTime;
	else if(mPosition.x > lVector.x)
		mPosition.x -= gGhostMovementSpeed * 6  * lDeltaTime;
	else if(mPosition.z < lVector.z)
		mPosition.z += gGhostMovementSpeed * 6  * lDeltaTime;
	else if(mPosition.z > lVector.z)
		mPosition.z -= gGhostMovementSpeed * 6  * lDeltaTime;
}

void Ghost::Eaten()
{
	mPosition = mSpawnPosition;
	mDestinationWaypoint = mStartWaypoint;
}

void Ghost::IsEdible(bool lIsEdible)
{
	if (!lIsEdible)
		mShaderObject->SetResource("tex2D", mResourceView);
	else
		mShaderObject->SetResource("tex2D", mResourceView2);	
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

	data[0].centerW = D3DXVECTOR4(mPosition, 1.0f);
    data[0].sizeW = D3DXVECTOR2(50, 50);

	mVertexBuffer->Unmap();
}
