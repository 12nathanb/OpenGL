#include "VertexBuffer.h"

void VertexBuffer::GenerateBuffers(GLsizei i)
{
	glGenBuffers(i, &this->VBO);
}

void VertexBuffer::BindBuffer(unsigned& number_vertices, Vertex* vertex, GLenum type)
{
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, number_vertices * sizeof(Vertex), vertex, GL_STATIC_DRAW);
}
