#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
	public:
		//ShaderObject* shaderObject;

		void Initialize(ID3D10Device* lDevice, ID3D10Effect* lEffect);
		void Draw();
	protected:
		/*D3DXVECTOR3 mPosition;
		D3DXMATRIX mWorldMatrix;
		ID3D10EffectShaderResourceVariable* mShaderTextureVariable;
		ID3D10ShaderResourceView* mResourceView;
		ID3D10Buffer mVertexBuffer;
		ShaderObject* mShaderObject;*/

protected:
	void CreateVertexBuffer();

protected:
	ShaderObject* mShaderObject;
	D3DXVECTOR3 mPosition;
	D3DXMATRIX mWorldMatrix;
	ID3D10EffectShaderResourceVariable* mShaderTextureVariable;
	ID3D10ShaderResourceView* mResourceView;
	ID3D10Buffer mVertexBuffer;

};

#endif