#pragma once

struct Vertex
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 normal;
	D3DXVECTOR2 texC;

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
	{ "POS", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0 },
	{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0},
	{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0,24,D3D10_INPUT_PER_VERTEX_DATA, 0}
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