#pragma once
#include <DX3D/Graphics/GrahpicsResource.h>
namespace dx3d
{
	class Mesh final : public GrahpicsResource
	{
	public:
		Mesh(const MeshDesc& desc , const GrapihicsResourceDesc& gDesc);

		ui32 getIndexCount() const;

	private:
		Microsoft::WRL::ComPtr<ID3D11Buffer> m_vertexBuffer{};
		Microsoft::WRL::ComPtr<ID3D11Buffer> m_indexBuffer{};
		ui32 m_vertexStride = 0; 
		ui32 m_vertexCount = 0;  
		ui32 m_indexCount = 0;
		friend class DeviceContext;
	};


}



