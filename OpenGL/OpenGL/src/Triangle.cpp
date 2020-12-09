#include "Triangle.h"

Triangle::Triangle()
{
	Vertex vertices[] =
	{
		glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f),  glm::vec3(0.0f, 0.0f,1.0f),
		glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f),
		glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)
	};


	GLuint indices[] =
	{
		0, 1, 2
	};

	unsigned numV = sizeof(vertices) / sizeof(Vertex);
	unsigned numI = sizeof(indices) / sizeof(GLuint);

	Init(vertices, numV, indices, numI);
}



