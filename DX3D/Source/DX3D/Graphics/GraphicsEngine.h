#pragma once
#include "DX3D/Core/Common.h"
#include "DX3D/Core/Base.h"
#include <DX3D/Math/Vec3.h>
#include <DX3D/Math/Vec4.h>
#include <vector>

namespace dx3d { 
	class GraphicsEngine final : public Base
	{
	public:
		explicit GraphicsEngine(const GraphicsEngineDesc& desc);
		virtual ~GraphicsEngine() override;


		RenderSystem& getRenderSystem() noexcept;
		void render(SwapChain& swapChain);
	public:
		struct Vertex
		{
			Vec3 postion;
			Vec4 color;
		};
		struct MeshData {
			std::vector<Vertex> vertices;
			std::vector<ui32> indices;
		};
	private:
		std::shared_ptr<RenderSystem> m_renderSystem{};
		DeviceContextPtr m_deviceContext{};
		GraphicsPipelineStatePtr m_Pipeline{};
		VertexBufferPtr m_vertexPtr{};
		ConstantBufferPtr m_cb;
		MeshPtr m_mesh;

	
	};  
}


