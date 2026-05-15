#pragma once
#include <DX3D/Graphics/GrahpicsResource.h>

namespace dx3d
{
	class ShaderBinary final : public GrahpicsResource
	{
	public:
		ShaderBinary(const ShaderCompileDesc& desc, const GrapihicsResourceDesc& gDesc);
		ShaderBinaryData getData() const noexcept;
		ShaderType getType() const noexcept;
	private:
		Microsoft::WRL::ComPtr<ID3DBlob> m_blobak{};
		ShaderType my_type{};
	};
}


