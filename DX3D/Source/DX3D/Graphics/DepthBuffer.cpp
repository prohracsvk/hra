#include <DX3D/Graphics/DepthBuffer.h>

dx3d::DepthBuffer::DepthBuffer(const DepthBufferDesc& desc, const GrapihicsResourceDesc& gDesc) : GrahpicsResource(gDesc)
{
	D3D11_TEXTURE2D_DESC Depth{};
	Depth.Width = desc.width;
	Depth.Height = desc.height;
	Depth.MipLevels = 1;
	Depth.ArraySize = 1;
	Depth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	Depth.SampleDesc.Count = 1;
	Depth.SampleDesc.Quality = 0;
	Depth.Usage = D3D11_USAGE_DEFAULT;
	Depth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	Depth.CPUAccessFlags = 0;
	Depth.MiscFlags = 0;

	
DX3DGraphicsLogErrorAndThrow(m_device.CreateTexture2D(&Depth, nullptr, &m_Texture2D), "failed Create texture2D");

D3D11_DEPTH_STENCIL_VIEW_DESC dsvDesc{};
dsvDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
dsvDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;

DX3DGraphicsLogErrorAndThrow(m_device.CreateDepthStencilView(m_Texture2D.Get(), &dsvDesc, &m_DSV),"failed create DepthStencilView");
	
}
