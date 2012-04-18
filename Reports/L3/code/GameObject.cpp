#include "GameObject.h"

GameObject::GameObject(): 
	mShaderObject(NULL),
	mPosition(NULL),
	mWorldMatrix(NULL),
	mShaderTextureVariable(NULL),
	mResourceView(NULL),
	mVertexBuffer(NULL)
{
	//Default Constructor
}

GameObject::~GameObject()
{
	delete mShaderObject;
	//Release Com instead
	//delete mShaderTextureVariable;
	//delete mResourceView;
	//delete mVertexBuffer;	
}



void GameObject::Initialize(ID3D10Device* lDevice, ID3D10Effect* lEffect) {
	throw "Not yet implemented";
}

void GameObject::Draw() {
	throw "Not yet implemented";
}

void GameObject::CreateVertexBuffer() {
	throw "Not yet implemented";
}

