#include <DX3D/Graphics/DeviceContext.h>
#include <DX3D/Graphics/SwapChain.h>
#include <DX3D/Graphics/GraphicsPipelineState.h>
#include <DX3D/Graphics/VertexBuffer.h>
#include <DX3D/Graphics/ConstantBuffer.h>
#include <DX3D/Graphics/Mesh.h>
#include <DX3D/Graphics/DepthBuffer.h>
#include <iostream>

using namespace dx3d;
dx3d::DeviceContext::DeviceContext(const GrapihicsResourceDesc& gDesc) : GrahpicsResource(gDesc)
{
	DX3DGraphicsLogErrorAndThrow(m_device.CreateDeferredContext(0, &m_context),
		"CreateDeferredContext failed");

}

void dx3d::DeviceContext::clearAndSetBackBuffer(const SwapChain& swapChain, const Vec4& color, const DepthBufferPtr& DepthBuffer)
{
	f32 fColor[] = { color.x,color.y,color.z,color.w };
	auto rtv = swapChain.m_RenderSystemWiew.Get();
	auto dsv = DepthBuffer->m_DSV.Get();
	
	m_context->OMSetRenderTargets(1, &rtv, dsv);
	m_context->ClearRenderTargetView(rtv ,fColor);
	m_context->ClearDepthStencilView(DepthBuffer->m_DSV.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);


	if (dsv == nullptr)
	{
		std::cout << "je to null";
	}
	if (rtv == nullptr)
	{
		std::cout << "je to null rtv";
	}

}

void dx3d::DeviceContext::setGraphicsPipelineState(const GraphicsPipelineState& pipeline)
{
	m_context->IASetInputLayout(pipeline.m_InputLayout.Get());
	m_context->VSSetShader(pipeline.m_vs.Get(), nullptr, 0);
	m_context->PSSetShader(pipeline.m_ps.Get(), nullptr, 0);
	m_context->GetDevice(&m_Device);

	D3D11_RASTERIZER_DESC rasterDesc = {};
	rasterDesc.CullMode = D3D11_CULL_NONE; 
	rasterDesc.FillMode = D3D11_FILL_SOLID; 
	rasterDesc.DepthClipEnable = true;
	rasterDesc.ScissorEnable = false;
	rasterDesc.MultisampleEnable = false;

	m_Device->CreateRasterizerState(&rasterDesc, &m_rasterState);
	
	
	m_context->RSSetState(m_rasterState.Get());
}

void dx3d::DeviceContext::setVertexBuffer(const VertexBuffer& desc)
{
	auto stride = desc.m_vertexSize;
	auto buffer = desc.m_Buffer.Get();
	auto offset = 0u;
	m_context->IASetVertexBuffers(0, 1, &buffer, &stride, &offset);
}

void dx3d::DeviceContext::setViewportSize(const Math& size)
{
	D3D11_VIEWPORT vp{};
	vp.Width = static_cast<f32>(size.width);
	vp.Height = static_cast<f32>(size.height);
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	m_context->RSSetViewports(1, &vp);
}

void dx3d::DeviceContext::drawTriangleList(ui32 vertexCount, ui32 startVertexLocation)
{
	m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	m_context->Draw(vertexCount, startVertexLocation);
}

void dx3d::DeviceContext::updateConstantBuffer(const ConstantBufferPtr& buffer, const void* data)
{
	m_context->UpdateSubresource(buffer->m_buffer.Get(), 0, nullptr, data, 0, 0);
}

void dx3d::DeviceContext::setConstantBuffer(const ConstantBufferPtr& buffer)
{
	m_context->VSSetConstantBuffers(0, 1, buffer->m_buffer.GetAddressOf());
}

void dx3d::DeviceContext::setMesh(const MeshPtr& mesh)
{
	if (!mesh) return;
	ui32 stride = mesh->m_vertexStride;
	ui32 offset = 0;
	ID3D11Buffer* vBuffer = mesh->m_vertexBuffer.Get();
	m_context->IASetVertexBuffers(0, 1, &vBuffer, &stride, &offset);

	if (mesh->m_indexBuffer)
	{
		m_context->IASetIndexBuffer(mesh->m_indexBuffer.Get(), DXGI_FORMAT_R32_UINT, 0);
	}
}

void dx3d::DeviceContext::drawIndexed(ui32 indexCount, ui32 startIndexLocation)
{
	m_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	m_context->DrawIndexed(indexCount, startIndexLocation, 0);
}




