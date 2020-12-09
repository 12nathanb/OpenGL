#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Vertex.h"

class ElementBuffer
{
public:
	void GenerateBuffers(GLsizei i);
	void BindBuffer(unsigned& number_indices, GLuint* inidices, GLenum type);
	GLuint GetVertexBuffer() { return EBO; }
private:
	GLuint EBO;

};

