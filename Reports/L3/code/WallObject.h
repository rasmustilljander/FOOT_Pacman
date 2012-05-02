#ifndef WALLOBJECT_H
#define WALLOBJECT_H

#include "Utilities.h"
#include "Camera.h"
#include "ShaderObject.h"
#include "Vertex.h"
#include "ResourceLoader.h"

class WallObject
{
public:
	WallObject( D3DXVECTOR3 lPosition );
	~WallObject();

	void Initialize( ID3D10Device* lDevice );
	void Draw(  Camera* lCam );

private:
	void CreateVertexBuffer( ID3D10Buffer** lVB, int lSize );
	void SetResources();
	void SetupVertices();

private:
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
