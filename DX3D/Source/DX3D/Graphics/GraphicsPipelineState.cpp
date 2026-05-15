#include <DX3D/Graphics/GraphicsPipelineState.h>
#include <DX3D/Graphics/ShaderBinary.h>

dx3d::GraphicsPipelineState::GraphicsPipelineState(const GraphicsPipelineStateDesc& desc,const GrapihicsResourceDesc& gDesc) : GrahpicsResource(gDesc)
{
	if(desc.vs.getType() != ShaderType::VertexShader)
		DX3DLogThrowInvaligArg("the vs member is not valid vertex shader")
	if(desc.ps.getType() != ShaderType::PixelShader)
		DX3DLogThrowInvaligArg("the ps member is not valid vertex shader")
	auto vs = desc.vs.getData();
	auto ps = desc.ps.getData();

	//float3 postion : POSITION;
	//float4 color : COLOR0;

	constexpr D3D11_INPUT_ELEMENT_DESC element[] =
	{
		{"POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0},
		{"COLOR",0, DXGI_FORMAT_R32G32B32A32_FLOAT,0,12,D3D11_INPUT_PER_VERTEX_DATA,0}
	};
DX3DGraphicsLogErrorAndThrow(m_device.CreateInputLayout(element, std::size(element), vs.data, vs.dataSize, &m_InputLayout),"CreateInputLayout failed");

DX3DGraphicsLogErrorAndThrow(m_device.CreateVertexShader(vs.data, vs.dataSize, nullptr, &m_vs), "CreateVertexShader failed");
DX3DGraphicsLogErrorAndThrow(m_device.CreatePixelShader(ps.data, ps.dataSize, nullptr, &m_ps), "CreatePixelShader failed");
}
