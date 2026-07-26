#include <DX3D/Graphics/GrahpicsResource.h>
#include <DirectXMath.h> 
#pragma once
namespace dx3d
{
	class Camera final : public GrahpicsResource
	{
	public:
		Camera(const CameraDesc& desc, const GrapihicsResourceDesc& gDesc);
		void Move(CameraDesc& desc);
	private:
		f32 speed;

		DirectX::XMMATRIX m_ViewMatrix;

	};

}


