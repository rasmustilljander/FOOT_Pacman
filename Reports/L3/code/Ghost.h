#ifndef GHOST_H
#define GHOST_H

#include "NonStaticGameObject.h"
#include "Waypoints.h"

class Ghost: public NonStaticGameObject
{
public:
	Ghost(D3DXVECTOR3 lPosition);
	virtual ~Ghost();

	void Update(float lDT);
	void SetTargetPosition(D3DXVECTOR3 lTargetPosition);

private:
	void SetResources();
	void SetupVertices();

private:
	ID3D10ShaderResourceView* mResourceView2;


};

#endif
