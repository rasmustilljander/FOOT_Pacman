#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Utilities.h"
#include "ShaderObject.h"
#include "Camera2.h"
#include "Vertex.h"
#include "ResourceLoader.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	void Initialize(ID3D10Device* lDevice, char* lFxFilename);
	void Draw(Camera2* lCam);


protected:
	void CreateVertexBuffer(ID3D10Buffer** lVB, int lSize);
	void SetValuesToVertexBuffer();
	virtual void SetResources() = 0;
	virtual void SetupVertices() = 0;

protected:
	ID3D10Device* mDevice;
	ShaderObject* mShaderObject;

	D3DXVECTOR3 mPosition;
	D3DXMATRIX mWorldMatrix;
	D3DXMATRIX mViewProjMatrix;
	ID3D10EffectShaderResourceVariable* mShaderTextureVariable;
	ID3D10ShaderResourceView* mResourceView;
	ID3D10Buffer* mVertexBuffer;
};

#endif
