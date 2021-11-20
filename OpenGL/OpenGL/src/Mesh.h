#pragma once
#include <string>

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Camera.h"
#include "Texture.h"
#include "Vertex.h"
#include <vector>

class Mesh
{
public:
	std::vector <Vertex> vertices;
	std::vector <GLuint> indicies;
	std::vector <Texture> textures;

	VertexArray VAO;

	Mesh(std::vector <Vertex>& vertices, std::vector <GLuint>& indices, std::vector <Texture>& textures);

	void Draw(Shader& shader, Camera& camera);
};

