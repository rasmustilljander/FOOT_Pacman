#include <exception>
#include "Utilities.h"
#include "ShaderObject.h"
#include "Vertex.h"
#include <sstream>
using namespace std;

#ifndef __HUD_h__
#define __HUD_h__

class HUD
{
public:
		HUD();
		~HUD();

		void Initialize(ID3D10Device* lDevice);
		void Draw();

		int setScore(int i) { mScore = i; };
		int setLivesLeft(int i) { mLivesLeft = i; };
private:
		void CreateVertexBuffer( ID3D10Buffer** lVB, int lSize );
		void SetValuesToVertexBuffer();

		void CreateTextures();
		float ConvertPixelsToClipSpace( const int lPixelDimension, const int lPixels );
		float ConvertPixelsToClipSpaceDistance( const int lPixelDimension, const int lPixels );
		void DisplayText();

private:
		ID3D10Device* mDevice;

		ID3D10EffectTechnique* mDrawTech;
		ID3D10EffectShaderResourceVariable* mShaderTextureVariable;
		ID3D10ShaderResourceView* mResourceView;
		ID3D10Buffer* mVertexBuffer;
		ID3DX10Font* mFont;

		int mScore;
		int mLivesLeft;

		ShaderObject* mShaderObj;
};

#endif
