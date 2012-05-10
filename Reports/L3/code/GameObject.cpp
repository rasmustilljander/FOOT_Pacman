#include "GameObject.h"

GameObject::GameObject(): 
	mShaderTextureVariable(NULL),
	mResourceView(NULL),
	mVertexBuffer(NULL)
{
	mShaderObject = new ShaderObject();
}

GameObject::~GameObject()
{
	delete mShaderObject;

	//Release?
	delete mShaderTextureVariable;
	delete mResourceView;
	mVertexBuffer;	
}

void GameObject::Initialize(ID3D10Device* lDevice, char* FxFileName) 
{
	mDevice = lDevice;

	mShaderObject->Initialize( mDevice, FxFileName, BillboardVertexLayout, BillboardLayoutNumElements, "drawTech", D3D10_SHADER_ENABLE_BACKWARDS_COMPATIBILITY);
	CreateVertexBuffer( &mVertexBuffer, 1 );
	SetupVertices();
	SetResources();
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


void GameObject::Draw( Camera2* lCam ) 
{
	SetupVertices();
	D3DXMatrixIdentity(&mViewProjMatrix);
	mViewProjMatrix = lCam->getViewMatrix() * lCam->getProjectionMatrix();
	mShaderObject->SetMatrix("viewProj", mViewProjMatrix);
	mShaderObject->SetFloat3("eyePosW", &lCam->getCameraPosition());

	mDevice->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_POINTLIST);

	UINT stride = sizeof(BillboardVertex);
	UINT offset= 0;

	mDevice->IASetVertexBuffers(0,1,&mVertexBuffer, &stride, &offset);

	mShaderObject->Render(0);
	mDevice->Draw(1,0);
}


