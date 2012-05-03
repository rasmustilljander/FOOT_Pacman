#include "GameObject.h"

GameObject::GameObject(): 
	mShaderTextureVariable(NULL),
	mResourceView(NULL),
	mVertexBuffer(NULL)
{
	//Default Constructor
}

GameObject::~GameObject()
{
	//delete mShaderObject;
	//Release Com instead
	//delete mShaderTextureVariable;
	//delete mResourceView;
	//delete mVertexBuffer;	
}

void GameObject::Initialize(ID3D10Device* lDevice, char* FxFileName) 
{
	mDevice = lDevice;

	mShaderObject->Initialize( mDevice, FxFileName, BillboardVertexLayout, BillboardLayoutNumElements, "drawTech", D3D10_SHADER_ENABLE_STRICTNESS);
	CreateVertexBuffer( &mVertexBuffer, 4 );
}

void GameObject::CreateVertexBuffer( ID3D10Buffer** lVB, int lSize ) 
{
	D3D10_BUFFER_DESC bd;
	bd.Usage = D3D10_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof( BillboardVertex ) * lSize;
	bd.BindFlags = D3D10_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D10_CPU_ACCESS_WRITE;
	bd.MiscFlags = 0;

	mDevice->CreateBuffer( &bd, 0, lVB );
}


void GameObject::Draw( Camera* lCam ) 
{
	D3DXMatrixIdentity(&mViewProjMatrix);
	mViewProjMatrix = lCam->GetView() * lCam->GetProjection();
	mShaderObject->SetMatrix("viewProj", mViewProjMatrix);
	mShaderObject->SetFloat3("eyePos", &lCam->GetPosition());

	mDevice->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	UINT stride = sizeof(BillboardVertex);
	UINT offset= 0;

	mDevice->IASetVertexBuffers(0,1,&mVertexBuffer, &stride, &offset);

	mShaderObject->Render(0);
}


