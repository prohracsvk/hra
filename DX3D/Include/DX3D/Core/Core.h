#pragma once
#include <memory>
#include <stdexcept>

namespace dx3d {
	class Base;
	class Game;
	class Window;

	class GraphicsEngine;
	class RenderSystem;
	class DeviceContext;

	class Logger;
	class SwapChain;
	class Display;

	class ShaderBinary;
	class GraphicsPipelineState;

	class VertexBuffer;
	class ConstantBuffer;
	class Mesh;

	using i32 = int;
	using ui32 = unsigned int;
	using f32 = float;
	using d64 = double;

	using SwapChainPtr = std::shared_ptr<SwapChain>;
	using DeviceContextPtr = std::shared_ptr<DeviceContext>;
	using ShaderBinaryPtr = std::shared_ptr<ShaderBinary>;
	using GraphicsPipelineStatePtr = std::shared_ptr<GraphicsPipelineState>;
	using VertexBufferPtr = std::shared_ptr<VertexBuffer>;
	using ConstantBufferPtr = std::shared_ptr<ConstantBuffer>;
	using MeshPtr = std::shared_ptr<Mesh>;
}
