#pragma once
#include "DX3D/Core/Core.h"
#include "DX3D/Core/Logger.h"
#include <DX3D/Math/Rect.h>
namespace dx3d 
{
	struct BaseDesc
	{
		Logger& logger;
	};
	struct WindowDesc
	{
		BaseDesc Base;
		Math size{};
	};
	struct DisplayDesc
	{
		WindowDesc window;
		RenderSystem& renderSystem;
	};
	struct GraphicsEngineDesc
	{
		BaseDesc Base;
	};
	struct RenderSystemDesc
	{
		BaseDesc Base;
	};
	struct SwapChainDesc
	{
		void* winHandle{};
		Math WinSize{};
	};
	enum class ShaderType
	{
		VertexShader = 0,
		PixelShader
	};
	struct ShaderCompileDesc
	{
		const char* shaderSourceName{};
		const void* shaderSourceCode{};
		size_t shaderSourceCodeSize{};
		const char* shaderEntryPoint{};
		ShaderType shaderType{};
	};
	struct ShaderBinaryData
	{
		const void* data{};
		size_t dataSize{};
	
	};
	struct GraphicsPipelineStateDesc
	{
		const ShaderBinary& vs;
		const ShaderBinary& ps;
	
	};
	struct VertexBufferDesc
	{
		const void* vertexList{};
		ui32 vertexListSize{};
		ui32 vertexSize{};
	};
	struct ConstantBufferDesc
	{
		ui32 bufferSize = 0;
	};
	struct MeshDesc
	{
		const void* vertexList{};
		ui32 vertexSize{};
		ui32 vertexListSize{};

		const void* indexList{};
		ui32 indexListSize{};
	};
	struct GameDesc
	{
		Math windowSize{ 1280,720 };
		Logger::LogLevel logLevel = Logger::LogLevel::Error;
	};
}