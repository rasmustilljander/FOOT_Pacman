
#include "ResourceLoader.h"

ResourceLoader::ResourceLoader()
{
}

ResourceLoader::~ResourceLoader()
{
}

ResourceLoader& ResourceLoader::GetResourceLoader()
{
	static ResourceLoader lResourceLoader;
	return lResourceLoader;
}


void ResourceLoader::LoadTextures(ID3D10Device* lDevice)
{
	//Load all textures here when you create the screens in "Screenhandler"
}