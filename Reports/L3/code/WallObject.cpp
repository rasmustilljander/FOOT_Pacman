#include "WallObject.h"

WallObject::WallObject( D3DXVECTOR3 lPosition )
{
	mPosition = lPosition;
}

WallObject::~WallObject()
{

}

void WallObject::Initialize( ID3D10Device* lDevice )
{
	mDevice = lDevice;

	mShaderObject->Initialize( mDevice, "wall.fx", VertexLayout, vertexInputLayoutNumElements, "drawTech", NULL );
	CreateVertexBuffer( &mVertexBuffer, 4 );
	SetResources();
}

void WallObject::CreateVertexBuffer( ID3D10Buffer** lVB, int lSize )
{
	D3D10_BUFFER_DESC bd;
	bd.Usage = D3D10_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof( Vertex ) * lSize;
	bd.BindFlags = D3D10_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D10_CPU_ACCESS_WRITE;
	bd.MiscFlags = 0;

	mDevice->CreateBuffer( &bd, 0, lVB );
}

void WallObject::SetResources()
{
	D3DXMatrixIdentity(&mWorldMatrix);
	D3DXMatrixTranslation(&mWorldMatrix, mPosition.x, mPosition.y, mPosition.z);

	mShaderObject->SetMatrix("worldMatrix", mWorldMatrix);
	mShaderObject->SetResource("tex2D", GetResourceLoader().GetWallTexture());
}

void WallObject::SetupVertices()
{

}

void WallObject::Draw( Camera* lCam )
{
	mShaderObject->SetMatrix("viewMatrix", lCam->GetView());
	mShaderObject->SetMatrix("projMatrix", lCam->GetProjection());

	mDevice->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	UINT stride = sizeof(Vertex);
	UINT offset= 0;

	mDevice->IASetVertexBuffers(0,1,&mVertexBuffer, &stride, &offset);

	mShaderObject->Render(0);
}

