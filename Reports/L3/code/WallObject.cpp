#include "WallObject.h"

WallObject::WallObject( D3DXVECTOR3 lPosition, int lWidth, int lHeight, D3DXVECTOR3 lNormal )
{
	mPosition = lPosition;
	mWidth = lWidth;
	mHeight = lHeight;
	mNormal = lNormal;
}

WallObject::~WallObject()
{

}

void WallObject::Initialize( ID3D10Device* lDevice )
{
	mDevice = lDevice;

	mShaderObject->Initialize( lDevice, "wall.fx", VertexLayout, vertexInputLayoutNumElements, "drawTech", D3D10_SHADER_ENABLE_STRICTNESS );
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
	Vertex* data = NULL;

	mVertexBuffer->Map( D3D10_MAP_WRITE_DISCARD, 0, reinterpret_cast< void** > ((void**)&data) );

	data[0].pos = mPosition;
	data[0].texC = D3DXVECTOR2(0,0);

	data[1].pos = D3DXVECTOR3( mPosition.x, mPosition.y + mHeight, mPosition.z );
	data[1].texC = D3DXVECTOR2(1,0);

	data[2].pos = D3DXVECTOR3( mPosition.x + mWidth, mPosition.y , mPosition.z );
	data[2].texC = D3DXVECTOR2(0,1);

	data[3].pos = D3DXVECTOR3( mPosition.x + mWidth, mPosition.y + mHeight, mPosition.z );
	data[3].texC = D3DXVECTOR2(1,1);

	D3DXVec3Normalize(&mNormal, &mNormal);
	for (int i = 0; i < 4; i++)
	{
		data[i].normal = mNormal;
		
	}

	mVertexBuffer->Unmap();
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

