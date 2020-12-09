#include "VertexArray.h"

VertexArray::VertexArray()
{
	
}

void VertexArray::CreateVertexArray(GLsizei i)
{
	glCreateVertexArrays(i, &this->VAO);
	glBindVertexArray(this->VAO);
}
