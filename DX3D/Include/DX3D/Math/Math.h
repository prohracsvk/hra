#pragma once
#include <DX3D/Core/Core.h>
#include <DirectXMath.h> 

namespace dx3d
{
	class Matrix4x4
	{
	public:
		Matrix4x4() { setIdentity(); }

		void setIdentity() {
			mat = DirectX::XMMatrixIdentity();
		}

		void setRotationY(float angle)
		{
			
			mat = DirectX::XMMatrixRotationY(angle);
		}

		
		Matrix4x4 operator*(const Matrix4x4& other) const {
			Matrix4x4 res;
			res.mat = DirectX::XMMatrixMultiply(this->mat, other.mat);
			return res;
		}

	public:
	
		DirectX::XMMATRIX mat;
	};
}