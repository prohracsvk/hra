#include <DX3D/Graphics/Mesh.h>


dx3d::Mesh::Mesh(const MeshDesc& desc, const GrapihicsResourceDesc& gDesc) : GrahpicsResource(gDesc)
{
	m_vertexStride = desc.vertexSize;
	m_indexCount = desc.indexListSize;

	D3D11_BUFFER_DESC mesh{};
	mesh.Usage = D3D11_USAGE_DEFAULT;
	mesh.ByteWidth = desc.vertexSize * desc.vertexListSize;
	mesh.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA Data{};
	Data.pSysMem = desc.vertexList;
	
 DX3DGraphicsLogErrorAndThrow(m_device.CreateBuffer(&mesh, &Data, m_vertexBuffer.GetAddressOf()),"CreateBuffer mesh failed");

 if (desc.indexList && desc.indexListSize > 0)
 {
	 D3D11_BUFFER_DESC index{};
	 index.Usage = D3D11_USAGE_DEFAULT;
	 index.ByteWidth = sizeof(unsigned int) * desc.indexListSize;
	 index.BindFlags = D3D11_BIND_INDEX_BUFFER;

	 D3D11_SUBRESOURCE_DATA indexData{};
	 indexData.pSysMem = desc.indexList;

	 DX3DGraphicsLogErrorAndThrow(m_device.CreateBuffer(&index, &indexData, m_indexBuffer.GetAddressOf()), "IndexBuffer failed");
 }

}

dx3d::ui32 dx3d::Mesh::getIndexCount() const
{
	return m_indexCount;
}
