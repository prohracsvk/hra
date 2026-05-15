#include <DX3D/Graphics/VertexBuffer.h>

dx3d::VertexBuffer::VertexBuffer(const VertexBufferDesc& desc, const GrapihicsResourceDesc& gDesc) : GrahpicsResource(gDesc) , m_vertexSize(desc.vertexSize) , m_vertexListSize(desc.vertexListSize)
{
	if (!desc.vertexList) DX3DLogThrowInvaligArg("no vertex list");
	if (!desc.vertexListSize) DX3DLogThrowInvaligArg("no vertex list size");
	if (!desc.vertexSize) DX3DLogThrowInvaligArg("no vertex Size");

	
	D3D11_BUFFER_DESC BufferDesc{};
	BufferDesc.ByteWidth = desc.vertexListSize * desc.vertexSize;
	BufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA vertexData{};
	vertexData.pSysMem = desc.vertexList;

DX3DGraphicsLogErrorAndThrow(m_device.CreateBuffer(&BufferDesc, &vertexData, &m_Buffer),"failed CreateBuffer");
}

dx3d::ui32 dx3d::VertexBuffer::getVertexListSize() const noexcept
{
	return m_vertexListSize;
}
