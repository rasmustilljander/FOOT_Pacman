
#include "ResourceLoader.h"

ResourceLoader& GetResourceLoader()
{
	static ResourceLoader mResourceLoader; 
	return mResourceLoader;
}

ResourceLoader::ResourceLoader()
{
}

ResourceLoader::~ResourceLoader()
{
}

void ResourceLoader::LoadTextures(ID3D10Device* lDevice)
{
	//Load all textures here when you create the screens in "Screenhandler"
	
	CreateTextureShader(lDevice, "Textures/Candy.png" , &mCandyTexture);
	CreateTextureShader(lDevice, "Textures/SuperCandy.png" , &mSuperCandyTexture);
	CreateTextureShader(lDevice, "Textures/Ghost.png" , &mGhostTexture);
	CreateTextureShader(lDevice, "Textures/GhostEdible.png" , &mGhostEdibleTexture);
	CreateTextureShader(lDevice, "Textures/Wall.jpg" , &mWallTexture);
	CreateTextureShader(lDevice, "Textures/2DPacman.png" , &m2DPacmanTexture);
	CreateTextureShader(lDevice, "Textures/Button.png" , &mButtonTexture);
	CreateTextureShader(lDevice, "Textures/DeathEffect.png" , &mDeathTexture);	
	CreateTextureShader(lDevice, "Textures/Floor.jpg" , &mFloorTexture);	

}

void ResourceLoader::CreateTextureShader(ID3D10Device* lDevice, LPCSTR lTexturePath, ID3D10ShaderResourceView** lShaderResView)
{
	HRESULT h = D3DX10CreateShaderResourceViewFromFile(lDevice, lTexturePath,
														NULL, NULL,
														lShaderResView,
														NULL);
	if (FAILED(h))
	{MessageBox(0, lTexturePath, "Missing Texture", 0);}
}