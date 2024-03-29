
Texture2D tex2D;


matrix worldMatrix;
matrix viewMatrix;
matrix projMatrix;

//Wall structs

struct VSSceneIn
{
	float4 Pos	: POSITION;
	float2 Tex : TEXCOORD;
	float3 n : NORMAL;
};

struct PSSceneIn
{
	float4 Pos  : SV_Position;
	float2 Tex : TEXCOORD;
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
	AddressU = Wrap;
	AddressV = Wrap;
};

//-----------------------------------------------------------------------------------------
// VertexShader: VSScene
//-----------------------------------------------------------------------------------------
PSSceneIn VSScene(VSSceneIn input)
{
	PSSceneIn output;
	
		input.Pos = mul( input.Pos, worldMatrix );
	    output.Pos = mul( input.Pos, viewMatrix );
	    output.Pos = mul( output.Pos, projMatrix );

		output.Tex = input.Tex;
		
	return output;
}

//-----------------------------------------------------------------------------------------
// PixelShader: PSSceneMain
//-----------------------------------------------------------------------------------------


float4 PSScene( PSSceneIn input ) : SV_Target
{
	return tex2D.Sample( linearSampler, input.Tex );
	//return float4(1,1,1,1);
}


//-----------------------------------------------------------------------------------------
// Technique: RenderTextured  
//-----------------------------------------------------------------------------------------
technique10 drawTech
{
    pass p0
    {
		// Set VS, GS, and PS
        SetVertexShader( CompileShader( vs_4_0, VSScene() ) );
        SetGeometryShader( NULL );
        SetPixelShader( CompileShader( ps_4_0, PSScene() ) );
	    
	    SetRasterizerState( NoCulling );

	    SetDepthStencilState( EnableDepth, 0 );
	    //SetDepthStencilState( DisableDepth, 0 );
	    //SetDepthStencilState( EnableDepthTestOnly, 0 );
    }  
}
