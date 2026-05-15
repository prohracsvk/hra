#pragma once
#include <DX3D/Core/Base.h>
#include <DX3D/Graphics/GrahpicsResource.h>
namespace dx3d {
	class SwapChain final : public GrahpicsResource
	{
	public:
		SwapChain(const SwapChainDesc& desc ,const GrapihicsResourceDesc& gDesc);
		Math getSize() const noexcept;
		void Present(bool vsync = false);
	private:
		void realodBuffers();
	private:
		Microsoft::WRL::ComPtr<IDXGISwapChain> m_IdSwapChain{};
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_RenderSystemWiew{};
		Math m_size{};
		friend class DeviceContext;

	};
}


