#include <DX3D/Game/Display.h>
#include <DX3D/Graphics/RenderSystem.h>
#include <DX3D/Graphics/SwapChain.h>


dx3d::Display::Display(const DisplayDesc& desc) : Window(desc.window)
{
	m_swapChain = desc.renderSystem.createSwapChain({ m_handle, m_size });
}

dx3d::SwapChain& dx3d::Display::getSwapChain() noexcept
{
	return *m_swapChain;
}
