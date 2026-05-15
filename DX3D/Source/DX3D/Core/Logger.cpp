#include "DX3D/Core/Logger.h"
#include <iostream>

dx3d::Logger::Logger(LogLevel logLevel) : m_logLevel(logLevel)
{
	std::clog << "Engine for game" << "\n";
	std::clog << "____________________________" << "\n";
}

void dx3d::Logger::log(LogLevel level, const char* message)
{
	auto logLevelString = [](LogLevel level){
		switch (level)
		{
		case LogLevel::Info: return "info";
		case LogLevel::Warning: return "Warning";
		case LogLevel::Error: return "Error";
		default: return "Unknow";
		}
	};
	if (level > m_logLevel) return;
	std::clog << "[DX3D " << logLevelString(level) << "]:" << message << "\n";
}
