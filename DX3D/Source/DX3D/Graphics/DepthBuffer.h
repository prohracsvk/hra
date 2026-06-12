#pragma once
#include <DX3D/Graphics/GrahpicsResource.h>
namespace dx3d
{
	class DepthBuffer final : public GrahpicsResource
	{
	public:
		DepthBuffer(const DepthBufferDesc& desc, const GrapihicsResourceDesc& gDesc);

	private:
		Microsoft::WRL::ComPtr<ID3D11Texture2D> m_Texture2D{};
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> m_DSV{};
		friend class DeviceContext;
		
	};
 
}


