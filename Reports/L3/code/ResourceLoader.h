#include "Utilities.h"
//#include <string>
#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H



class ResourceLoader
{
public:

	ResourceLoader();
	~ResourceLoader();
	//static ResourceLoader& GetResourceLoader();
	void LoadTextures(ID3D10Device* lDevice);

#pragma region GetTextureMethods
	ID3D10ShaderResourceView* GetCandyTexture() const 
	{
		return mCandyTexture;
	}
	ID3D10ShaderResourceView* GetSuperCandyTexture() const
	{
		return mSuperCandyTexture;
	}
	ID3D10ShaderResourceView* GetGhostTexture() const
	{
		return mGhostTexture;
	}
	ID3D10ShaderResourceView* GetGhostEdibleTexture() const
	{
		return mGhostEdibleTexture;
	}
	ID3D10ShaderResourceView* GetWallTexture() const
	{
		return mWallTexture;
	}
	ID3D10ShaderResourceView* Get2DPacmanTeture() const
	{
		return m2DPacmanTexture;
	}
	ID3D10ShaderResourceView* GetButtonTexture() const
	{
		return mButtonTexture;
	}
	ID3D10ShaderResourceView* GetDeathTexture() const
	{
		return mDeathTexture;
	}

	ID3D10ShaderResourceView* GetFloorTexture() const
	{
		return mFloorTexture;
	}
#pragma endregion

private:
	
	void CreateTextureShader(ID3D10Device* lDevice, LPCSTR lTexturePath, ID3D10ShaderResourceView** lShaderResView);

private:
	

	ID3D10ShaderResourceView* mCandyTexture;
	ID3D10ShaderResourceView* mSuperCandyTexture;
	ID3D10ShaderResourceView* mGhostTexture;
	ID3D10ShaderResourceView* mGhostEdibleTexture;
	ID3D10ShaderResourceView* mWallTexture;
	ID3D10ShaderResourceView* m2DPacmanTexture;
	ID3D10ShaderResourceView* mButtonTexture;
	ID3D10ShaderResourceView* mDeathTexture;
	ID3D10ShaderResourceView* mFloorTexture;


};
ResourceLoader& GetResourceLoader();

#endif
