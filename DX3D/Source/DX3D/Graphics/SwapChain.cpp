#include <DX3D/Graphics/SwapChain.h>
#include <DX3D/Graphics/RenderSystem.h>
#include <DX3D/Graphics/GrahpicsResource.h>



dx3d::SwapChain::SwapChain(const SwapChainDesc& desc, const GrapihicsResourceDesc& gDesc) : GrahpicsResource(gDesc) , m_size(desc.WinSize)
{
	if(!desc.winHandle) DX3DLogThrowInvaligArg("no windows handle")
		DXGI_SWAP_CHAIN_DESC dxgiDesc{};
		dxgiDesc.BufferDesc.Width = std::max(1, desc.WinSize.width);
		dxgiDesc.BufferDesc.Height = std::max(1, desc.WinSize.height);
		dxgiDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		dxgiDesc.BufferCount = 2;
		dxgiDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;

		dxgiDesc.OutputWindow = static_cast<HWND>(desc.winHandle);
		dxgiDesc.SampleDesc.Count = 1;
		dxgiDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		dxgiDesc.Windowed = TRUE;
	

		DX3DGraphicsLogErrorAndThrow(m_factory.CreateSwapChain(&m_device, &dxgiDesc, &m_IdSwapChain), " failed CreateSwapChain");

		realodBuffers();
}

dx3d::Math dx3d::SwapChain::getSize() const noexcept
{
	return m_size;
}

void dx3d::SwapChain::Present(bool vsync)
{
DX3DGraphicsLogErrorAndThrow(m_IdSwapChain->Present(vsync, 0), "Present failed");
}

void dx3d::SwapChain::realodBuffers()
{
	Microsoft::WRL::ComPtr<ID3D11Texture2D> Buffer{};
DX3DGraphicsLogErrorAndThrow(m_IdSwapChain->GetBuffer(0, IID_PPV_ARGS(&Buffer)),
	"GetBuffer failed");
DX3DGraphicsLogErrorAndThrow(m_device.CreateRenderTargetView(Buffer.Get(), nullptr, &m_RenderSystemWiew),"CreateRenderTargetView failed");
}


