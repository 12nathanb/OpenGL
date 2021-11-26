#include "LoadObjModel.h"

std::vector<Vertex> LoadObjModel::loadModel(const char* filename)
{
	std::vector<glm::fvec3> vertex_positions;
	std::vector<glm::fvec2> vertex_texcoord;
	std::vector<glm::fvec3> vertex_normal;

	std::vector<GLint> vertex_position_indicies;
	std::vector<GLint> vertex_texcoord_indicies;
	std::vector<GLint> vertex_normal_indicies;

	std::vector<Vertex> verticies;

	glm::vec3 tempVec3;
	glm::vec2 tempVec2;

	GLint TempGlint = 0;

	std::stringstream ss;
	std::ifstream in_file(filename);
	std::string line = "";
	std::string prefix = "";


	if (!in_file.is_open())
	{
		throw "obj cannot load file";
	}

	while (std::getline(in_file, line))
	{
		ss.clear();
		ss.str(line);
		ss >> prefix;

		if (prefix == "#")
		{

		}
		else if (prefix == "o")
		{

		}
		else if (prefix == "s")
		{

		}
		else if (prefix == "use_mtl")
		{

		}
		else if (prefix == "v")
		{
			ss >> tempVec3.x >> tempVec3.y >> tempVec3.z;
			vertex_positions.push_back(tempVec3);
		}

		else if (prefix == "vn")
		{
			ss >> tempVec3.x >> tempVec3.y >> tempVec3.z;
			vertex_normal.push_back(tempVec3);
		}

		else if (prefix == "vt")
		{
			ss >> tempVec2.x >> tempVec2.y;
			vertex_texcoord.push_back(tempVec2);
		}

		else if (prefix == "f")
		{
			int counter = 0;
			
			while (ss >> TempGlint)
			{
				if (counter == 0)
					vertex_position_indicies.push_back(TempGlint);
				else if (counter == 1)
					vertex_texcoord_indicies.push_back(TempGlint);
				else if (counter == 2)
					vertex_normal_indicies.push_back(TempGlint);

				if (ss.peek() == '/')
				{
					++counter;
					ss.ignore(1, '/');
				}
				else if (ss.peek() == ' ')
				{
					++counter;
					ss.ignore(1, ' ');
				}

				if (counter > 2)
				{
					counter = 0;
				}
			}

		}
		else
		{

		}
	}

		verticies.resize(vertex_position_indicies.size(), Vertex());

		for (size_t i = 0; i < verticies.size(); ++i)
		{
			verticies[i].position = vertex_positions[vertex_position_indicies[i] - 1];
			verticies[i].texcoord = vertex_texcoord[vertex_texcoord_indicies[i] - 1];
			verticies[i].normal = vertex_normal[vertex_normal_indicies[i] - 1];
			verticies[i].color = glm::vec3(1.f, 1.f, 1.f);
		}

		std::cout << "number of vertices: " << verticies.size() << "\n";
		std::cout << "OBJ file loaded!" << "\n";
	
	return verticies;
}
