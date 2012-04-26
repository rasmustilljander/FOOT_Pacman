#include <exception>
using namespace std;

#include "HUD.h"

HUD::HUD()
{
	mScore = 0;
	mLivesLeft = 0;
}

HUD::~HUD()
{
}

void HUD::Draw()
{
	mDevice->IASetPrimitiveTopology(D3D10_PRIMITIVE_TOPOLOGY_POINTLIST);

	UINT stride = sizeof(Spritevertex);
    UINT offset = 0;

	mDevice->IASetVertexBuffers(0,1,&mVertexBuffer, &stride, &offset);
	DisplayText();
}

void HUD::Initialize(ID3D10Device* lDevice) 
{
	mDevice = lDevice;

	CreateVertexBuffer( &mVertexBuffer, 4 );
	CreateTextures();
	SetValuesToVertexBuffer();
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

void HUD::SetValuesToVertexBuffer()
{
	Spritevertex* data = NULL;

	mVertexBuffer->Map( D3D10_MAP_WRITE_DISCARD, 0, reinterpret_cast< void** > ((void**)&data) );

	data[0].topLeft[0] = ConvertPixelsToClipSpace(1024, 0);
	data[0].topLeft[1] = -ConvertPixelsToClipSpace(768, 0);
	data[0].dimensions[0] = ConvertPixelsToClipSpaceDistance(1024, 256);
	data[0].dimensions[1] = ConvertPixelsToClipSpaceDistance(768, 192);
	data[0].opacity = 0;

	mVertexBuffer->Unmap();
}

void HUD::CreateTextures()
{
}

void HUD::DisplayText()
{
	D3DXCOLOR fontColor = D3DXCOLOR(255,0,0,255);
	RECT rc;

	rc.left = 800;
	rc.right = 1024;
	rc.top = 10;
	rc.bottom = rc.top + 20;

	stringstream out;
	string temp;

	out << mScore;
	temp = "Score: ";
	temp = temp + out.str();

	mFont->DrawTextA(NULL, temp.c_str(), -1, &rc, 0, fontColor);
}

float HUD::ConvertPixelsToClipSpace(  const int lPixelDimension, const int lPixels )
{
	return (float)lPixels/lPixelDimension * 2 - 1;
}

float HUD::ConvertPixelsToClipSpaceDistance( const int lPixelDimension, const int lPixels )
{
	return (float)lPixels/lPixelDimension * 2;
}

