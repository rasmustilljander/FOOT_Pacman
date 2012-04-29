
Texture2D tex2D;

//Sprite structs

struct SPRITE_INPUT
{
	float2 topLeft : ANCHOR;
	float2 dimensions : DIMENSIONS;
	float opacity: OPACITY;
};

struct PS_HUD
{
	float4 p : SV_POSITION;
	float2 t : TEXC;
	float opacity : OPACITY;
};

//-----------------------------------------------------------------------------------------
// Constant Buffers (where we store variables by frequency of update)
//-----------------------------------------------------------------------------------------
cbuffer cbEveryFrame
{
};

//-----------------------------------------------------------------------------------------
// State Structures
//-----------------------------------------------------------------------------------------
DepthStencilState DisableDepth
{
    DepthEnable = FALSE;
    DepthWriteMask = ZERO;
};

DepthStencilState EnableDepthTestOnly
{
    DepthEnable = TRUE;
    DepthWriteMask = ZERO;
};

DepthStencilState EnableDepth
{
    DepthEnable = TRUE;
    DepthWriteMask = ALL;
};

RasterizerState NoCulling
{
	CullMode = NONE;
};

SamplerState linearSampler
{
	Filter = MIN_MAG_MIP_LINEAR;
	AddressU = Clamp;
    AddressV = Clamp;
    MaxAnisotropy = 16;
};

BlendState SrcAlphaBlending
{
	BlendEnable[0] = TRUE;
	SrcBlend = SRC_ALPHA;
	DestBlend = INV_SRC_ALPHA;
	BlendOp = ADD;
	SrcBlendAlpha = ZERO;
	DestBlendAlpha = ZERO;
	BlendOpAlpha = ADD;
	RenderTargetWriteMask[0] = 0x0F;
};


//-----------------------------------------------------------------------------------------
// VertexShader: VSScene
//-----------------------------------------------------------------------------------------
SPRITE_INPUT VS( SPRITE_INPUT input )
{
	return input;
}

//--------------------------------------------------------------------------------------
// Geometry Shader - Billboard
//--------------------------------------------------------------------------------------

[maxvertexcount(4)]
void GS( point SPRITE_INPUT sprite[1] : SV_POSITION, inout TriangleStream<PS_HUD> triStream )
{
	PS_BILLBOARD p;
	p.opacity = sprite[0].opacity;

	//bottom left
	p.p = float4( sprite[0].topLeft[0], sprite[0].topLeft[1] - sprite[0].dimensions[1], 0, 1 );
	p.t = float2( 0, 1 );
	triStream.Append(p);


	//top left
	p.p = float4( sprite[0].topLeft[0], sprite[0].topLeft[1], 0, 1 );
	p.t = float2( 0, 0 );
	triStream.Append(p);

	//bottom right
	p.p = float4( sprite[0].topLeft[0] + sprite[0].dimensions[0], sprite[0].topLeft[1] - sprite[0].dimensions[1], 0, 1 );
	p.t = float2( 1, 1 );
	triStream.Append(p);

	//top right
	p.p = float4( sprite[0].topLeft[0] + sprite[0].dimensions[0], sprite[0].topLeft[1], 0, 1 );
	p.t = float2( 1, 0 );
	triStream.Append(p);

}

//-----------------------------------------------------------------------------------------
// PixelShader: PSSceneMain
//-----------------------------------------------------------------------------------------

float4 PSHUD( PS_HUD input ) : SV_Target
{
	return tex2D.Sample( linearSampler, input.t );
}

//-----------------------------------------------------------------------------------------
// Technique: RenderTextured  
//-----------------------------------------------------------------------------------------

technique10 drawHUD
{
    pass P0
    {
        SetVertexShader( CompileShader( vs_4_0, VS() ) );
        SetGeometryShader( CompileShader( gs_4_0, GS() ) );
        SetPixelShader( CompileShader( ps_4_0, PSHUD() ) );	

		SetBlendState( SrcAlphaBlending, float4( 0.0f, 0.0f, 0.0f, 0.0f ), 0xFFFFFFFF );		
    }
}
