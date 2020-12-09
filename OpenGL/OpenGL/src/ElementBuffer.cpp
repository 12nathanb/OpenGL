#include "ElementBuffer.h"

void ElementBuffer::GenerateBuffers(GLsizei i)
{
	glGenBuffers(i, &this->EBO);
}

void ElementBuffer::BindBuffer(unsigned& number_indices, GLuint* inidices, GLenum type)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, number_indices * sizeof(GLuint), inidices, type);
}
