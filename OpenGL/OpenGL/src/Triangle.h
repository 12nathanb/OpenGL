#pragma once
#include "libs.h"
class Triangle
{
public:
	Triangle();

	void Draw(GLuint& program);
private:
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;
};

