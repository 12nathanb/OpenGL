#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class VertexArray
{
public:
	VertexArray();
	void CreateVertexArray(GLsizei i);
	GLuint GetVertexArray() { return VAO; }
private:
	GLuint VAO;
};

