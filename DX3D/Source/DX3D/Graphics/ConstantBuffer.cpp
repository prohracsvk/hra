#include <DX3D/Graphics/ConstantBuffer.h>

dx3d::ConstantBuffer::ConstantBuffer(const ConstantBufferDesc& desc, const GrapihicsResourceDesc& gDesc) : GrahpicsResource(gDesc)
{
	D3D11_BUFFER_DESC buffer{};
	buffer.Usage = D3D11_USAGE_DEFAULT;
	buffer.ByteWidth = desc.bufferSize;
	buffer.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	buffer.CPUAccessFlags = 0;
	buffer.MiscFlags = 0;
	buffer.StructureByteStride = 0;

	HRESULT hr = m_device.CreateBuffer(&buffer, nullptr, m_buffer.ReleaseAndGetAddressOf());

	if (FAILED(hr))
	{
		throw std::runtime_error("ConstantBuffer failed");
	}

}
