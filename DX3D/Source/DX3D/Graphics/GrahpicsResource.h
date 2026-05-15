#pragma once
#include <DX3D/Core/Common.h>
#include <DX3D/Graphics/GraphicsLogUtils.h>
#include <DX3D/Core/Base.h>
#include <d3d11.h>
#include <wrl.h>
namespace dx3d 
{
	struct GrapihicsResourceDesc 
	{
		BaseDesc Base;
		std::shared_ptr<const RenderSystem> renderSystem;
		ID3D11Device& device;
		IDXGIFactory& factory;
	};
	class GrahpicsResource : public Base
	{
	public:
		explicit GrahpicsResource(const GrapihicsResourceDesc& desc) :
			Base(desc.Base),
			m_renderSystem(desc.renderSystem),
			m_device(desc.device),
			m_factory(desc.factory)
		{

		}

	protected:
		std::shared_ptr<const RenderSystem> m_renderSystem;
		ID3D11Device& m_device;
		IDXGIFactory& m_factory;
	};
}
