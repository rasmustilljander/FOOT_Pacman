#ifndef WALLOBJECT_H
#define WALLOBJECT_H

#include "Utilities.h"
#include "Camera2.h"
#include "ShaderObject.h"
#include "Vertex.h"
#include "ResourceLoader.h"

class WallObject
{
public:
	WallObject( D3DXVECTOR3 lPosition, int lWidth, int lHeight, D3DXVECTOR3 lNormal );
	~WallObject();

	void Initialize( ID3D10Device* lDevice );
	void Draw(  Camera2* lCam );

private:
	void CreateVertexBuffer( ID3D10Buffer** lVB, int lSize );
	void SetResources();
	void SetupVertices();

private:
	ID3D10Device* mDevice;
	ShaderObject* mShaderObject;

	int mWidth, mHeight;
	D3DXVECTOR3 mNormal;
	D3DXVECTOR3 mPosition;
	D3DXMATRIX mWorldMatrix;
	D3DXMATRIX mViewProjMatrix;

	ID3D10EffectShaderResourceVariable* mShaderTextureVariable;
	ID3D10ShaderResourceView* mResourceView;
	ID3D10Buffer* mVertexBuffer;

};

#endif
