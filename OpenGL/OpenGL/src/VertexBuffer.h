#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Vertex.h"

class VertexBuffer
{
public:
	void GenerateBuffers(GLsizei i);
	void BindBuffer(unsigned& number_vertices, Vertex* vertex, GLenum type);
	GLuint GetVertexBuffer() { return VBO;  }
private:
	GLuint VBO;
};

