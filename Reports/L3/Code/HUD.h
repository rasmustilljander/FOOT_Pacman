#include <exception>
using namespace std;

#ifndef __HUD_h__
#define __HUD_h__

// #include "GameScreen.h"

class GameScreen;
class HUD;

class HUD
{
	public:
		GameScreen* gameScreen;

		void Initialize(ID3D10Device* lDevice, ID3D10Effect* lEffect);
	private:
		ID3D10EffectShaderResourceVariable* mShaderTextureVariable2;
		ID3D10ShaderResourceView* mResourceView2;
		ID3DX10Font mFont;

		void CreateVertexBuffer();
};

#endif
