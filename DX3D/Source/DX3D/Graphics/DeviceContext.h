#pragma once
#include <DX3D/Graphics/GrahpicsResource.h>
#include <DX3D/Math/Vec4.h>
namespace dx3d {

class DeviceContext final : public GrahpicsResource
{
public: 
	explicit DeviceContext(const GrapihicsResourceDesc& gDesc);
	void clearAndSetBackBuffer(const SwapChain& swapChain, const Vec4& color);
	void setGraphicsPipelineState(const GraphicsPipelineState& pipeline);
	void setVertexBuffer(const VertexBuffer& desc);
	void setViewportSize(const Math& size);
	void drawTriangleList(ui32 vertexCount, ui32 startVertexLocation);
	void updateConstantBuffer(const ConstantBufferPtr& buffer, const void* data);
	void setConstantBuffer(const ConstantBufferPtr& buffer);
	void setMesh(const MeshPtr& mesh);
	void drawIndexed(ui32 indexCount, ui32 startIndexLocation);
	
	
private:
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_context{};
	Microsoft::WRL::ComPtr<ID3D11Device> m_Device{};
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> m_rasterState{};
	friend class RenderSystem;
};


}
