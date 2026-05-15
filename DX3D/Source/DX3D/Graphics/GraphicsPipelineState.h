#pragma once
#include <DX3D/Graphics/GrahpicsResource.h>
#include <DX3D/Graphics/DeviceContext.h>
namespace dx3d
{
	class GraphicsPipelineState final : public GrahpicsResource
	{ 
	public:
		GraphicsPipelineState(const GraphicsPipelineStateDesc& desc, const GrapihicsResourceDesc& gDesc);

	private:
		Microsoft::WRL::ComPtr<ID3D11VertexShader> m_vs{};
		Microsoft::WRL::ComPtr<ID3D11PixelShader> m_ps{};
		Microsoft::WRL::ComPtr<ID3D11InputLayout> m_InputLayout{};
		friend class DeviceContext;
	};
}


