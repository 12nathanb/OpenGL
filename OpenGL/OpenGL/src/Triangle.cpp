#include "Triangle.h"

Vertex tri_vertices[] =
{
	glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2(0.0f, 1.0f),  glm::vec3(0.0f, 0.0f,1.0f),
	glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f),
	glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)
};


GLuint tri_indices[] =
{
	0, 1, 2
};

unsigned numVT = sizeof(tri_vertices) / sizeof(Vertex);
unsigned numIT = sizeof(tri_indices) / sizeof(GLuint);

Triangle::Triangle()
{
	Init(tri_vertices, numVT, tri_indices, numIT);
}



