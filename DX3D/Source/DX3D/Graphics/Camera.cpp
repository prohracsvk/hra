#include "Camera.h"

dx3d::Camera::Camera(const CameraDesc& desc, const GrapihicsResourceDesc& gDesc) : GrahpicsResource(gDesc)
{
	DirectX::XMVECTOR pos = desc.m_position;
	DirectX::XMVECTOR target = desc.m_taget;
	DirectX::XMVECTOR up = desc.m_up;

	m_ViewMatrix = DirectX::XMMatrixLookAtLH(pos, target, up);
}

void dx3d::Camera::Move(CameraDesc& desc)
{
	desc.m_position = DirectX::XMVectorAdd(desc.m_position, DirectX::XMVectorScale(desc.direction, speed));

}


