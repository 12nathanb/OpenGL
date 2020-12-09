#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Texture.h"
#include "material.h"
#include<vec2.hpp>
#include<vec3.hpp>
#include<mat4x4.hpp>
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"
#include "Vertex.h"


class Shape
{
	
public:
	Shape();
	void Init(Vertex* vertexArray, const unsigned& num_of_vert, GLuint* indexArray, const unsigned& num_of_indi);
	void Update(Shader* program);
	void Draw(Shader* program);
	void SetScale(glm::vec3 s) { Scale = s; }
	void SetPosition(glm::vec3 p) { Position = p;  }
	void SetRotation(glm::vec3 r) { Rotation = r; }
	void SetTexture(std::string fileName);
	void MoveObject(glm::vec3 p) { Position += p; }
	void RotateObject(glm::vec3 r) { Rotation += r; }
private:
	void updateModelMatrix();
	void updateUniforms(Shader* program) { program->setMat4fv(this->ModelMatrix, "ModelMatrix"); }

private:
	glm::mat4 ModelMatrix;

	glm::vec3 Position;
	glm::vec3 Rotation;
	glm::vec3 Scale = glm::vec3(1.0f, 1.0f, 1.0f);

	
	

	unsigned number_of_vertices;
	unsigned number_of_indices;
	
	std::vector<Vertex> vertArray;
	std::vector<GLuint> indiArray;

	const char* texture_file_name;

	Texture texture0;
	material material0;

	VertexArray VAO;
	VertexBuffer VBO;
	ElementBuffer EBO;

};


