#pragma once
#include <DX3D/Graphics/GrahpicsResource.h>
#include <DX3D/Graphics/DeviceContext.h>
namespace dx3d
{
	class VertexBuffer final : public GrahpicsResource
	{
	public:
		VertexBuffer(const VertexBufferDesc& desc, const GrapihicsResourceDesc& gDesc);
		ui32 getVertexListSize() const noexcept;
	private:
		Microsoft::WRL::ComPtr<ID3D11Buffer> m_Buffer{};
		ui32 m_vertexSize{};
		ui32 m_vertexListSize{};
		friend class DeviceContext;
	};
}