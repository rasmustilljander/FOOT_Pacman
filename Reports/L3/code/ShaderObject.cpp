#include <exception>
using namespace std;

#include "ShaderObject.h"
#include "GameObject.h"

void ShaderObject::Initialize(ID3D10Device* lDevice, char* lFilename, const D3D10_INPUT_ELEMENT_DESC* lInputDesc, UINT lNumberOfElements, char* lTechniqueName, DWORD lShaderFlags) {
	throw "Not yet implemented";
}

void ShaderObject::Render(UINT lPass) {
	throw "Not yet implemented";
}

void ShaderObject::SetMatrix(char* lVariable, D3DXMatrix& mD3DXMatrix) {
	throw "Not yet implemented";
}

void ShaderObject::SetFloat(char* lVariable, float lFloat) {
	throw "Not yet implemented";
}

void ShaderObject::SetFloat4(char* lVariable, D3DXVector4* lVector) {
	throw "Not yet implemented";
}

void ShaderObject::Setint(char* lVariable, int lInt) {
	throw "Not yet implemented";
}

void ShaderObject::SetBool(char* lVariable) {
	throw "Not yet implemented";
}

void ShaderObject::SetRawData(char* lVariable, void* lData, size_t lSize) {
	throw "Not yet implemented";
}

void ShaderObject::SetResource(char* lVariable) {
	throw "Not yet implemented";
}

ID3D10EffectTechnique* ShaderObject::GetTechnique() {
	throw "Not yet implemented";
}

ID3D10EffectTechnique* ShaderObject::GetTechniqueByName(char* lVariable) {
	throw "Not yet implemented";
}

void ShaderObject::SetTechniqueByName(char* lVariable) {
	throw "Not yet implemented";
}

