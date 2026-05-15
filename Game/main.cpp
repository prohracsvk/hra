#include "DX3D/All.h"
#include <stdexcept>
#include <filesystem>
#include <iostream>


int main() {

	std::cout << "Engine bezi v: " << std::filesystem::current_path() << std::endl;
	try {
		dx3d::Game game({ {1920,1080},dx3d::Logger::LogLevel::Info });
		game.run();
	}
	catch (const std::runtime_error&)
	{
		return EXIT_FAILURE;
	}
	catch (const std::invalid_argument&)
	{
		return EXIT_FAILURE;
	}
	catch (const std::exception&)
	{
		return EXIT_FAILURE;
	}
	catch (...)
	{
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}