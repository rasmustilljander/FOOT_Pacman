#include "Ghost.h"


Ghost::Ghost( D3DXVECTOR3 lPosition )
{
	mPosition = lPosition;
}

Ghost::~Ghost()
{

}

void Ghost::Update(float lDT) 
{

}

void Ghost::SetTargetPosition(D3DXVECTOR3 lTargetPosition) 
{

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
