#include <DX3D/Graphics/GrahpicsResource.h>
#include <DirectXMath.h> 
#pragma once
namespace dx3d
{
	class Camera final : public GrahpicsResource
	{
		Camera(const CameraDesc& desc, const GrapihicsResourceDesc& gDesc);
	};

}


