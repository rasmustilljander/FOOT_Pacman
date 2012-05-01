
#include "ResourceLoader.h"

ResourceLoader::ResourceLoader()
{
}

ResourceLoader::~ResourceLoader()
{
}

ResourceLoader& ResourceLoader::GetResourceLoader()
{

	// hur fan funkar detta? fråga bulten hur vi hade gjort med den gamla kameran
	static ResourceLoader lResourceLoader;
	return lResourceLoader;
}


void ResourceLoader::LoadTextures(ID3D10Device* lDevice)
{
	//Load all textures here when you create the screens in "Screenhandler"
}