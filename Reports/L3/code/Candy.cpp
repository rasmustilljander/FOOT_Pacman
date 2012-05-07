#include "Candy.h"


Candy::Candy()
{
	mType = 0;
}

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

	if (mType == 0)
		mShaderObject->SetResource("tex2D", GetResourceLoader().GetCandyTexture());
	else
		mShaderObject->SetResource("tex2D", GetResourceLoader().GetSuperCandyTexture());
}

void Candy::SetupVertices()
{
	BillboardVertex* data = NULL;

	data[0].centerW = mPosition;
	data[0].sizeW = D3DXVECTOR2(10, 10);

	D3D10_BUFFER_DESC vbd;
    vbd.Usage = D3D10_USAGE_IMMUTABLE;
    vbd.ByteWidth = sizeof(BillboardVertex) * 1;
    vbd.BindFlags = D3D10_BIND_VERTEX_BUFFER;
    vbd.CPUAccessFlags = 0;
    vbd.MiscFlags = 0;
    D3D10_SUBRESOURCE_DATA vinitData;
    vinitData.pSysMem = data;
    mDevice->CreateBuffer(&vbd, &vinitData, &mVertexBuffer);

	delete[] data;
}