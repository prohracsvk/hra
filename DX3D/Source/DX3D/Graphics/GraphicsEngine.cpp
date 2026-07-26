#include "DX3D/Graphics/GraphicsEngine.h"
#include "DX3D/Graphics/RenderSystem.h"
#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/SwapChain.h>
#include <DX3D/Graphics/VertexBuffer.h>
#include <DX3D/Math/Vec3.h>
#include <DX3D/Math/Math.h>
#include <DX3D/Graphics/Mesh.h>
#include <DX3D/Graphics/MeshLoader.h>
#include <fstream>
using namespace dx3d;

dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc) : Base(desc.Base)


{

	m_renderSystem = std::make_shared<RenderSystem>(RenderSystemDesc{ m_logger });
	auto& device = *m_renderSystem;
	m_deviceContext = m_renderSystem->createDeviceContext();

	constexpr char shaderFilePath[] = "DX3D/Assets/Shaders/Basic.hlsl";
	std::ifstream shaderStream(shaderFilePath);
	if (!shaderStream) DX3DLoggerErrors("open shader failed");
	std::string shaderFileData{
		std::istreambuf_iterator<char>(shaderStream),
		std::istreambuf_iterator<char>()
	
	};



     auto shaderSourceCode = shaderFileData.c_str();
	 auto shaderSourceCodeSize = shaderFileData.length();

auto vs = device.compileShader({ shaderFilePath, shaderSourceCode, shaderSourceCodeSize , "VSMain", ShaderType::VertexShader});
auto ps = device.compileShader({ shaderFilePath, shaderSourceCode, shaderSourceCodeSize , "PSMain", ShaderType::PixelShader});

m_Pipeline = device.createGraphicsPipelineState({ *vs, *ps });
m_depthBuffer = m_renderSystem->createDephtBuffer({1920,1080});

GraphicsEngine::MeshData data = LoadOBJ("island_tree_01_4k.obj");




data.vertices;
data.indices;



m_mesh = device.createMesh({ data.vertices.data(), sizeof(Vertex), (ui32)data.vertices.size(), data.indices.data(), (ui32)data.indices.size() });
 m_cb = device.createConstantBuffer({ sizeof(Matrix4x4) });
}



dx3d::GraphicsEngine::~GraphicsEngine()
{
}

RenderSystem& dx3d::GraphicsEngine::getRenderSystem() noexcept
{
	return *m_renderSystem;
	
}

void dx3d::GraphicsEngine::render(SwapChain& swapChain)
{
	auto& context = *m_deviceContext;
	context.clearAndSetBackBuffer(swapChain, { 0.29f, 0.39f, 0.55f, 1 }, m_depthBuffer);
	context.setGraphicsPipelineState(*m_Pipeline);
	context.setViewportSize(swapChain.getSize());


	static float angle = 0.0f;
	angle += 0.001f; 

	Matrix4x4 world;
	world.setRotationY(angle); 
	world.mat = DirectX::XMMatrixTranspose(world.mat);


	context.updateConstantBuffer(m_cb, &world);
	context.setConstantBuffer(m_cb);

	context.setMesh(m_mesh);

	context.drawTriangleList(m_mesh->getIndexCount(), 0u);

	auto& device = *m_renderSystem;
	device.executeCommandList(context);
	swapChain.Present();
	
}

 
