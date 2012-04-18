#include <exception>
#include "Utilities.h"
#include <DxErr.h>
using namespace std;

#ifndef __ShaderObject_h__
#define __ShaderObject_h__

class ShaderObject
{
	public:

		ShaderObject();
		~ShaderObject();
	/// <param name="lTechniqueName">                                                                       </param>
		HRESULT Initialize(ID3D10Device* lDevice, char* lFilename, const D3D10_INPUT_ELEMENT_DESC* lInputDesc, UINT lNumberOfElements, char* lTechniqueName, DWORD lShaderFlags);
		void Render(UINT lPass);
		void SetMatrix(char* lVariable, D3DXMATRIX& mD3DXMatrix);
		void SetFloat(char* lVariable, float lFloat);
		void SetFloat4(char* lVariable, D3DXVECTOR4* lVector);
		void Setint(char* lVariable, int lInt);
		void SetBool(char* lVariable);
		void SetRawData(char* lVariable, void* lData, size_t lSize);
		void SetResource(char* lVariable);
		ID3D10EffectTechnique* GetTechnique();
		ID3D10EffectTechnique* GetTechniqueByName(char* lVariable);
		void SetTechniqueByName(char* lVariable);
	private:
		ID3D10Effect* mEffect;
		ID3D10EffectTechnique* mEffectTechnique;
		ID3D10Device* mDevice;
		ID3D10InputLayout* mInputLayout;

};

#endif
