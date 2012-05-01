#include "Ghost.h"


Ghost::Ghost()
{

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

}

void Ghost::SetupVertices()
{
	BillboardVertex* data = NULL;

	mVertexBuffer->Map( D3D10_MAP_WRITE_DISCARD, 0, reinterpret_cast< void** > ((void**)&data) );

	data[0].centerW = mPosition;
	data[0].sizeW = D3DXVECTOR2(10, 10);

	mVertexBuffer->Unmap();
}
