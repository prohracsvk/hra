#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <DX3D/Graphics/GraphicsEngine.h> 
namespace dx3d
{
	inline GraphicsEngine::MeshData LoadOBJ(const char* path)
	{
		GraphicsEngine::MeshData meshdata;
		std::vector<Vec3> positions;
		std::ifstream file(path);

		if (!file.is_open()) {
			std::cout << "[DX3D Error]: Nepodarilo sa otvorit subor: " << path << std::endl;
			return meshdata;
		}

		std::string line;
		while (std::getline(file, line))
		{
			std::stringstream ss(line);
			std::string prefix;
			ss >> prefix;

		if (prefix == "v")
		{
			Vec3 pos;
			ss >> pos.x >> pos.y >> pos.z;
			pos.x *= 0.15f;
			pos.y *= 0.15f;
			pos.z *= 0.15f;
			positions.push_back(pos);

		}
		else if (prefix == "f")
		{
			std::string v[3];
			ss >> v[0] >> v[1] >> v[2];

			for (int i = 0; i < 3; i++)
			{
				std::string idxStr = v[i].substr(0, v[i].find('/'));
				int idx = std::stoi(idxStr) - 1;

				meshdata.indices.push_back((ui32)meshdata.vertices.size());
				meshdata.vertices.push_back({ positions[idx], {0.71,0.4,0.5,0.8} });
			}
		}

		}
		return meshdata;
	}

}

