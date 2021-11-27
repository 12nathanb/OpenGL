#include "Cube.h"

Cube::Cube(std::string name, std::string filename)
{
	this->setObjName(name);
	Vertex vertices2[] =
	{
		//Position								//Color							//Texcoords					//Normals
		glm::vec3(-0.5f, 0.5f, 0.5f),			glm::vec3(1.f, 1.f, 1.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
		glm::vec3(-0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
		glm::vec3(0.5f, -0.5f, 0.5f),			glm::vec3(1.f, 1.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
		glm::vec3(0.5f, 0.5f, 0.5f),			glm::vec3(1.f, 1.f, 1.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),

		glm::vec3(0.5f, 0.5f, -0.5f),			glm::vec3(1.f, 1.f, 1.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
		glm::vec3(0.5f, -0.5f, -0.5f),			glm::vec3(1.f, 1.f, 1.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
		glm::vec3(-0.5f, -0.5f, -0.5f),			glm::vec3(1.f, 1.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
		glm::vec3(-0.5f, 0.5f, -0.5f),			glm::vec3(1.f, 1.f, 1.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)
	};

	unsigned nrOfVertices = sizeof(vertices2) / sizeof(Vertex);

	GLuint indices[] =
	{
		// Front
		0, 1, 2,
	    2, 3, 0,
		//Left
		0, 3, 7,
		7, 3, 4,
		//Back
		4, 5, 6,
		6, 7, 4,
		//Top
		4, 3, 5,
		5, 3, 2,
		//Right
		2, 1, 5,
		5, 1, 6,
		//Bottom
		6, 1, 7,
		7, 1, 0
	};
	unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

	Init(vertices2, nrOfVertices, indices, nrOfIndices);
	this->SetTexture(filename);
}
