#include "Shape.h"


Shape::Shape()
{

	
}

void Shape::Init(Vertex* vertexArray, const unsigned& num_of_vert, GLuint* indexArray, const unsigned& num_of_indi)
{
	for (size_t i = 0; i < num_of_vert; i++)
	{
		this->vertArray.push_back(vertexArray[i]);
	}

	for (size_t i = 0; i < num_of_indi; i++)
	{
		this->indiArray.push_back(indexArray[i]);
	}

	quad_number_of_vertices = num_of_vert;
	quad_number_of_indices = num_of_indi;

	glCreateVertexArrays(1, &this->VAO);
	glBindVertexArray(this->VAO);


	glGenBuffers(1, &this->VBO);
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, this->quad_number_of_vertices * sizeof(Vertex), this->vertArray.data(), GL_STATIC_DRAW);

	if (this->quad_number_of_indices > 0)
	{
		glGenBuffers(1, &this->EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indiArray.size() * sizeof(GLuint), this->indiArray.data(), GL_STATIC_DRAW);

	}
	

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texcoord));
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
	glEnableVertexAttribArray(3);

	glBindVertexArray(0);

}

void Shape::Update(Shader* program)
{
	
	
	glm::vec3 lightPos0(0.0f, 0.0f, 2.0f);

	
	program->setVec3f(lightPos0, "lightPos0");
	

}

void Shape::Draw(Shader* program)
{
	this->updateModelMatrix();
	this->updateUniforms(program);

	program->use();
	
	glBindVertexArray(this->VAO);

	if (this->quad_number_of_indices == 0)
	{
		glDrawArrays(GL_TRIANGLES, 0, this->quad_number_of_vertices);

	}
	else
	{
		glDrawElements(GL_TRIANGLES, quad_number_of_indices, GL_UNSIGNED_INT, 0);

	}
	
	
}

void Shape::SetTexture(std::string fileName)
{
	const char* test = fileName.c_str(); 

	
	
	//texture0.init(fileName.c_str(), GL_TEXTURE_2D, 0);

	
	//material0.init(glm::vec3(0.1f), glm::vec3(0.1f), glm::vec3(0.1f), texture0.getID(), texture0.getID());
	
}

void Shape::updateModelMatrix()
{
	this->ModelMatrix = glm::mat4(1.f);
	this->ModelMatrix = glm::translate(this->ModelMatrix, this->Position);
	this->ModelMatrix = glm::rotate(this->ModelMatrix, glm::radians(this->Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	this->ModelMatrix = glm::rotate(this->ModelMatrix, glm::radians(this->Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	this->ModelMatrix = glm::rotate(this->ModelMatrix, glm::radians(this->Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	this->ModelMatrix = glm::scale(this->ModelMatrix, this->Scale);
}
