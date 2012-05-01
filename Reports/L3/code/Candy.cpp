#include "Candy.h"


Candy::Candy( int lType ,D3DXVECTOR3 lPosition )
	: GameObject()
{
	//Default Contructor
	mPosition = lPosition;
	mType = lType;
}

Candy::~Candy()
{

}


void Candy::SetResources()
{
	D3DXMatrixIdentity(&mWorldMatrix);
	D3DXMatrixTranslation(&mWorldMatrix, mPosition.x, mPosition.y, mPosition.z);

}

void Candy::SetupVertices()
{
	BillboardVertex* data = NULL;

	mVertexBuffer->Map( D3D10_MAP_WRITE_DISCARD, 0, reinterpret_cast< void** > ((void**)&data) );

	data[0].centerW = mPosition;
	data[0].sizeW = D3DXVECTOR2(10, 10);

	mVertexBuffer->Unmap();
}