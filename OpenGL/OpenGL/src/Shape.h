#pragma once
#include <string>
#include <iostream>
#include <vector>
#include<vec2.hpp>
#include<vec3.hpp>
#include<mat4x4.hpp>

#include "Texture.h"
#include "material.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ElementBuffer.h"
#include "Vertex.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class Shape
{
	
public:
	Shape();
	void Init(Vertex* vertexArray, const unsigned& num_of_vert, GLuint* indexArray, const unsigned& num_of_indi);
	void Update();
	void Draw();
	void SetScale(glm::vec3 s) { Scale = s; }
	void SetPosition(glm::vec3 p) { Position = p;  }
	void SetRotation(glm::vec3 r) { Rotation = r; }
	void SetTexture(std::string fileName);
	void MoveObject(glm::vec3 p) { Position += p; }
	void RotateObject(glm::vec3 r) { Rotation += r; }
	void setObjName(std::string name) { Object_name = name; }
	std::string getObjName() { return Object_name; }
	Shader* getShader() { return shader; }
	void createShape(std::vector<Vertex> vert, std::vector<GLuint> indi);
private:
	void updateModelMatrix();
	void updateUniforms(Shader* program) { program->setMat4fv(this->Model_matrix, "ModelMatrix"); }
	void ShapeMenu();
	
	

private:
	glm::mat4 Model_matrix;

	glm::vec3 Position;
	glm::vec3 Rotation;
	glm::vec3 Scale = glm::vec3(1.0f, 1.0f, 1.0f);

	
	
	std::string Object_name;
	unsigned number_of_vertices;
	unsigned number_of_indices;
	
	std::vector<Vertex> Vertices_array;
	std::vector<GLuint> Indices_array;

	const char* Texture_file_name;

	Texture Texture_0;
	material Material_0;

	VertexArray VAO;
	VertexBuffer VBO;
	ElementBuffer EBO;

	glm::vec3 Light_position_0;

	float Ambient_amount = 1.1f;
	float Diffuse_amount = 0.1f;
	float Specular_amount = 0.1f;

	Shader* shader;

};


