#include <exception>
using namespace std;

#include "HUD.h"

HUD::HUD()
{
}

HUD::~HUD()
{
}

void HUD::Draw()
{
}

void HUD::Initialize(ID3D10Device* lDevice) 
{
	mDevice = lDevice;

	//CreateVertexBuffer();
	CreateTextures();
}

void HUD::CreateVertexBuffer( ID3D10Buffer** lVB, int lSize  ) 
{
	D3D10_BUFFER_DESC bd;
	bd.Usage = D3D10_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof( Spritevertex ) * lSize;
	bd.BindFlags = D3D10_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D10_CPU_ACCESS_WRITE;
	bd.MiscFlags = 0;

	mDevice->CreateBuffer( &bd, 0, lVB );
}

void HUD::CreateTextures()
{
}

void HUD::DisplayText()
{
}

float HUD::ConvertPixelsToClipSpace(  const int lPixelDimension, const int lPixels )
{
	return (float)lPixels/lPixelDimension * 2 - 1;
}

float HUD::ConvertPixelsToClipSpaceDistance( const int lPixelDimension, const int lPixels )
{
	return (float)lPixels/lPixelDimension * 2;
}

