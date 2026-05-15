#include <DX3D/Graphics/ShaderBinary.h>
#include <d3dcompiler.h>
#include <DX3D/Graphics/GraphicsUtils.h>

dx3d::ShaderBinary::ShaderBinary(const ShaderCompileDesc& desc , const GrapihicsResourceDesc& gDesc) : GrahpicsResource(gDesc), my_type(desc.shaderType)
{
	if (!desc.shaderSourceName) DX3DLogThrowInvaligArg("no shader source name provide");
	if (!desc.shaderSourceCode) DX3DLogThrowInvaligArg("no shader source Code provide");
	if (!desc.shaderSourceCodeSize) DX3DLogThrowInvaligArg("no shader source Size provide");
	if (!desc.shaderEntryPoint) DX3DLogThrowInvaligArg("no shader entrypoint provide");

	UINT compileFlags{};
#ifdef _DEBUG
	compileFlags |= D3DCOMPILE_DEBUG;
#endif 

	Microsoft::WRL::ComPtr<ID3DBlob> m_Error_Blobak{};
   DX3DGraphicsCheckShaderCompile(D3DCompile(
		desc.shaderSourceCode,
		desc.shaderSourceCodeSize,
		desc.shaderSourceName,
		nullptr,
		nullptr,
		desc.shaderEntryPoint,
		dx3d::GraphicsUtils::GetShaderModelTarget(desc.shaderType),
		compileFlags,
		0,
		&m_blobak,
		&m_Error_Blobak
		), 
	       m_Error_Blobak.Get());
}

dx3d::ShaderBinaryData dx3d::ShaderBinary::getData() const noexcept
{
	return
	{
		m_blobak->GetBufferPointer(),
		m_blobak->GetBufferSize()
	};
}

dx3d::ShaderType dx3d::ShaderBinary::getType() const noexcept
{
	return my_type;
}
