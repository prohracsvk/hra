cbuffer ConstantBuffer : register(b0)
{
   
    row_major float4x4 worldMatrix;
};

struct VSInput
{
    float3 postion : POSITION;
    float4 color : COLOR0;
};

struct VSOutput
{
    float4 postion : SV_Position;
    float4 color : COLOR0;
};

VSOutput VSMain(VSInput input)
{
    VSOutput output;


    output.postion = mul(float4(input.postion, 1.0f), worldMatrix);
    
    output.color = input.color;
    return output;
}

float4 PSMain(VSOutput input) : SV_Target
{
    return input.color;
}