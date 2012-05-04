#include "WorldHandler.h"

WorldHandler::WorldHandler()
{
	mShaderObject = new ShaderObject();
}

WorldHandler::~WorldHandler()
{
}

void WorldHandler::Initialize(ID3D10Device* lDevice) 
{
	mDevice = lDevice;

	mShaderObject->Initialize( mDevice, "wall.fx", VertexLayout, vertexInputLayoutNumElements, "drawTech", D3D10_SHADER_ENABLE_BACKWARDS_COMPATIBILITY );
	CreateVertexBuffer( &mVertexBuffer, 4 );
	SetResources();
	SetupVertices();
}

void WorldHandler::CreateVertexBuffer( ID3D10Buffer** lVB, int lSize  )
{
	D3D10_BUFFER_DESC bd;
	bd.Usage = D3D10_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof( Vertex ) * lSize;
	bd.BindFlags = D3D10_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D10_CPU_ACCESS_WRITE;
	bd.MiscFlags = 0;

	mDevice->CreateBuffer( &bd, 0, lVB );
}

void WorldHandler::SetResources()
{
	D3DXMatrixIdentity(&mWorldMatrix);
	mShaderObject->SetMatrix("worldMatrix", mWorldMatrix);
}

void WorldHandler::SetupVertices()
{
	Vertex* data = NULL;

	mVertexBuffer->Map( D3D10_MAP_WRITE_DISCARD, 0, reinterpret_cast< void** > ((void**)&data) );

	data[0].pos = D3DXVECTOR3(0,10,0);
	data[0].texC = D3DXVECTOR2(0,0);
	data[0].normal = D3DXVECTOR3(0,1,0);

	data[1].pos = D3DXVECTOR3(10,0,0);
	data[1].texC = D3DXVECTOR2(1,0);
	data[1].normal = D3DXVECTOR3(0,1,0);

	data[2].pos = D3DXVECTOR3(0,10,10);
	data[2].texC = D3DXVECTOR2(0,1);
	data[2].normal = D3DXVECTOR3(0,1,0);

	data[3].pos = D3DXVECTOR3(10,0,10);
	data[3].texC = D3DXVECTOR2(1,1);
	data[3].normal = D3DXVECTOR3(0,1,0);

	mVertexBuffer->Unmap();
}

void WorldHandler::CreateLevel()
{

}

void WorldHandler::Draw( Camera* lCam )
{
	mShaderObject->SetMatrix("viewMatrix", lCam->GetView());
	mShaderObject->SetMatrix("projMatrix", lCam->GetProjection());

	mDevice->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	UINT stride = sizeof(Vertex);
	UINT offset= 0;

	mDevice->IASetVertexBuffers(0,1,&mVertexBuffer, &stride, &offset);

	D3D10_TECHNIQUE_DESC techDesc;
	mShaderObject->GetTechnique()->GetDesc( &techDesc );

	for( UINT p = 0; p < techDesc.Passes; p++ )
	{
	mShaderObject->Render(p);
	mDevice->Draw(4,0);
	}
}