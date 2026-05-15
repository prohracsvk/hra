#include "DX3D/Game/Game.h"
#include "DX3D/Window/Window.h"
#include "DX3D/Graphics/GraphicsEngine.h"
#include "DX3D/Core/Logger.h"
#include <DX3D/Game/Display.h>


dx3d::Game::Game(const GameDesc& desc):
Base({*std::make_unique<Logger>(desc.logLevel).release()}),
m_loggerPtr(&m_logger)
{
    
	m_graphicpsEngine = std::make_unique<GraphicsEngine>(GraphicsEngineDesc{m_logger});
	m_display = std::make_unique<Display>(DisplayDesc{ {m_logger,desc.windowSize}, m_graphicpsEngine->getRenderSystem()});
	
	DX3DLoggerInfo("Game initialized");
	
}


dx3d::Game::~Game()
{
	DX3DLoggerInfo("Game dellecoted");
}
void dx3d::Game::InternalUpdate()
{
	m_graphicpsEngine->render(m_display->getSwapChain());
}

