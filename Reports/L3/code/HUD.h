#include <exception>
#include "Utilities.h"
#include "ShaderObject.h"
#include "Vertex.h"
using namespace std;

#ifndef __HUD_h__
#define __HUD_h__

// #include "GameScreen.h"

class HUD
{
public:
		HUD();
		~HUD();

		void Initialize(ID3D10Device* lDevice, ID3D10Effect* lEffect);
		void Draw();
private:
		void CreateVertexBuffer( ID3D10Buffer** lVB, int lSize );

		void CreateTextures();
		float ConvertPixelsToClipSpace( const int lPixelDimenson, const int lPixels );
		float ConvertPixelsToClipSpaceDistance( const int lPixelDimensoin, const int lPixels );
		void DisplayText();
private:
		ID3D10Device* mDevice;

		ID3D10Effect* mEffect;
		ID3D10EffectTechnique* mDrawTech;
		ID3D10EffectShaderResourceVariable* mShaderTextureVariable;
		ID3D10ShaderResourceView* mResourceView2;
		ID3DX10Font* mFont;

};

#endif
