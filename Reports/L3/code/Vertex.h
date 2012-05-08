#pragma once

struct Vertex
{
	D3DXVECTOR3 pos;
	D3DXVECTOR2 texC;
	D3DXVECTOR3 normal;

	Vertex () : normal( D3DXVECTOR3(0,0,0) )
	{			
	}
	
	Vertex( D3DXVECTOR3 p, D3DXVECTOR3 n ) : pos(p), normal(n)
	{		
	}	

	Vertex( D3DXVECTOR3 p, D3DXVECTOR2 t, D3DXVECTOR3 n ) : pos(p), normal(n), texC(t)
	{
	}	
};

const D3D10_INPUT_ELEMENT_DESC VertexLayout[] =
{
	{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0 },
	{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0 },
	{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 20, D3D10_INPUT_PER_VERTEX_DATA, 0 }
};

const int vertexInputLayoutNumElements = sizeof(VertexLayout)/sizeof(VertexLayout[0]);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Spritevertex
{
	float topLeft[2];
	float dimensions[2];
	float opacity;
};

const D3D10_INPUT_ELEMENT_DESC spriteVertexLayout[] = 
{	
	{ "ANCHOR", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0 },
	{ "DIMENSIONS", 0, DXGI_FORMAT_R32G32_FLOAT, 0, 8, D3D10_INPUT_PER_VERTEX_DATA, 0 },
	{ "OPACITY", 0, DXGI_FORMAT_R32_FLOAT, 0, 16, D3D10_INPUT_PER_VERTEX_DATA, 0 }
};

const int spriteVertexLayoutNumElements = sizeof(spriteVertexLayout)/sizeof(spriteVertexLayout[0]);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct BillboardVertex
{
	D3DXVECTOR4 centerW;
	D3DXVECTOR2 sizeW;
};

const D3D10_INPUT_ELEMENT_DESC BillboardVertexLayout[] =
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0},
		{"SIZE",     0, DXGI_FORMAT_R32G32_FLOAT,    0, 16, D3D10_INPUT_PER_VERTEX_DATA, 0},
	};

const int BillboardLayoutNumElements = sizeof(BillboardVertexLayout)/sizeof(BillboardVertexLayout[0]);

