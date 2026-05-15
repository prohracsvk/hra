#pragma once
#include <DX3D/Core/Common.h>
#include <DX3D/Graphics/GrahpicsResource.h>
namespace dx3d
{
	class ConstantBuffer final : public GrahpicsResource
	{
	public:
		ConstantBuffer(const ConstantBufferDesc& desc , const GrapihicsResourceDesc& gDesc);


	private:
		Microsoft::WRL::ComPtr<ID3D11Buffer> m_buffer{};
		ui32 m_bufferSize{};
		friend class DeviceContext;
		

	};
}

