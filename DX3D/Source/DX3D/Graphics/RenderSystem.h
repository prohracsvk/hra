#pragma once
#include <DX3D/Core/Common.h>
#include <DX3D/Graphics/GrahpicsResource.h>
#include <DX3D/Core/Base.h>
#include <d3d11.h>
#include <wrl.h>
namespace dx3d {
	class RenderSystem final : public Base, public std::enable_shared_from_this<RenderSystem>
	{
	public:
		RenderSystem(const RenderSystemDesc& desc);
		virtual ~RenderSystem() override;

		SwapChainPtr createSwapChain(const SwapChainDesc& desc) const;
		DeviceContextPtr createDeviceContext();
		ShaderBinaryPtr compileShader(const ShaderCompileDesc& desc);
		GraphicsPipelineStatePtr createGraphicsPipelineState(const GraphicsPipelineStateDesc& desc);
		VertexBufferPtr createVertexBuffer(const VertexBufferDesc& desc);
		ConstantBufferPtr createConstantBuffer(const ConstantBufferDesc& desc);
		MeshPtr createMesh(const MeshDesc& desc);
		void executeCommandList(DeviceContext& context);
	private:
		GrapihicsResourceDesc getGraphicsResourceDesc() const noexcept;
	private:
		Microsoft::WRL::ComPtr<ID3D11Device> m_device{};
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_deviceContext{};
		Microsoft::WRL::ComPtr<IDXGIDevice> m_IDdevice{};
		Microsoft::WRL::ComPtr<IDXGIAdapter> m_IDadapter{};
		Microsoft::WRL::ComPtr<IDXGIFactory> m_IDfactory{};

	};
}


