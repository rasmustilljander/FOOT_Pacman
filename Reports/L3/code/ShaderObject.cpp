#include <exception>
using namespace std;

#include "ShaderObject.h"


ShaderObject::ShaderObject():	mEffect(NULL),
								mEffectTechnique(NULL),
								mInputLayout(NULL)
{
}

ShaderObject::~ShaderObject()
{
	SAFE_RELEASE(mInputLayout);

	if(mEffect)
	{
		while(mEffect->Release());
		mEffect = NULL;
	}
}

HRESULT ShaderObject::Initialize(ID3D10Device* lDevice, char* lFilename, const D3D10_INPUT_ELEMENT_DESC* lInputDesc, UINT lNumberOfElements, char* lTechniqueName, DWORD lShaderFlags) 
{
	mDevice = lDevice;

	HRESULT hr = S_OK;

	ID3DBlob*	pBlobEffect = NULL;
	ID3DBlob*	pBlobErrors = NULL;
	ID3D10Blob* compilationErrors = 0;
	
	//DWORD dwShaderFlags = D3D10_SHADER_ENABLE_BACKWARDS_COMPATIBILITY;

#if defined(DEBUG) || defined(_DEBUG)
	//dwShaderFlags |= D3D10_SHADER_DEBUG;
	lShaderFlags |= D3D10_SHADER_DEBUG;
	//shaderFlags |= D3D10_SHADER_SKIP_OPTIMIZATION;
#endif
	
	if(FAILED(D3DX10CreateEffectFromFile(	lFilename,
											NULL,
											NULL,
											"fx_4_0",
											lShaderFlags,
											0,
											mDevice,
											NULL,
											NULL,
											&mEffect,
											&compilationErrors,
											NULL)))
	{
		if( compilationErrors )
		{
			MessageBoxA(0, (char*)compilationErrors->GetBufferPointer(), 0, 0);
			compilationErrors->Release();
		}
		//DXTrace(__FILE__, (DWORD)__LINE__, hr, "D3DX10CreateEffectFromFile", true);
	}

	mEffectTechnique = mEffect->GetTechniqueByName(lTechniqueName);


	if(lInputDesc)
	{
		D3D10_PASS_DESC PassDesc;
		mEffectTechnique->GetPassByIndex(0)->GetDesc(&PassDesc);
		if(FAILED(hr = mDevice->CreateInputLayout(
			lInputDesc,
			lNumberOfElements,
			PassDesc.pIAInputSignature,
			PassDesc.IAInputSignatureSize,
			&mInputLayout
			)))
		{
			MessageBox(0, "Cannot create input layout.", "CreateInputLayout error", MB_OK | MB_ICONERROR);
			return hr;
		}
	}

	return hr;
}

void ShaderObject::Render(UINT lPass) 
{
	ID3D10EffectPass* p = mEffectTechnique->GetPassByIndex(lPass);
	if(p)
	{
		 mEffectTechnique->GetPassByIndex(lPass)->Apply(0);

		if(mInputLayout)
		{
			mDevice->IASetInputLayout(mInputLayout);
		}
	}
}

void ShaderObject::SetMatrix(char* lVariable, D3DXMATRIX& mD3DXMatrix) 
{
	mEffect->GetVariableByName(lVariable)->AsMatrix()->SetMatrix((float*)&mD3DXMatrix);
}

void ShaderObject::SetFloat(char* lVariable, float lFloat) 
{
	mEffect->GetVariableByName(lVariable)->AsScalar()->SetFloat(lFloat);
}

void ShaderObject::SetFloat4(char* lVariable, D3DXVECTOR4* lVector) 
{
	mEffect->GetVariableByName(lVariable)->AsVector()->SetFloatVector((float*)&lVector);
}

void ShaderObject::Setint(char* lVariable, int lInt) 
{
	mEffect->GetVariableByName(lVariable)->AsScalar()->SetInt(lInt);
}

void ShaderObject::SetBool(char* lVariable, bool lBool) 
{
	mEffect->GetVariableByName(lVariable)->AsScalar()->SetBool(lBool);
}

void ShaderObject::SetRawData(char* lVariable, void* lData, size_t lSize) 
{
	mEffect->GetVariableByName(lVariable)->SetRawValue(lData, 0, (UINT)lSize);
}

void ShaderObject::SetResource(char* lVariable, ID3D10ShaderResourceView* lShaderResourceView) 
{
	mEffect->GetVariableByName(lVariable)->AsShaderResource()->SetResource(lShaderResourceView);
}

ID3D10EffectTechnique* ShaderObject::GetTechnique() 
{
	return mEffectTechnique;
}

ID3D10EffectTechnique* ShaderObject::GetTechniqueByName(char* lVariable) 
{
	return mEffect->GetTechniqueByName(lVariable);
}

void ShaderObject::SetTechniqueByName(char* lVariable) 
{
	mEffectTechnique = mEffect->GetTechniqueByName(lVariable);
}

