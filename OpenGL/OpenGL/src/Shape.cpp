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

	quad_number_of_vertices = sizeof(vertArray) / sizeof(Vertex);
	quad_number_of_indices = sizeof(indiArray) / sizeof(GLuint);

	glCreateVertexArrays(1, &VAO);
	glBindVertexArray(VAO);


	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, this->vertArray.size() * sizeof(Vertex), this->vertArray.data(), GL_STATIC_DRAW);


	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indiArray.size() * sizeof(GLuint), this->indiArray.data(), GL_STATIC_DRAW);


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

glm::mat4 Shape::Update(Shaders& program)
{
	glm::mat4 ModelMatrix(1.f);
	ModelMatrix = glm::translate(ModelMatrix, Position);
	ModelMatrix = glm::rotate(ModelMatrix, glm::radians(Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	ModelMatrix = glm::rotate(ModelMatrix, glm::radians(Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	ModelMatrix = glm::rotate(ModelMatrix, glm::radians(Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	ModelMatrix = glm::scale(ModelMatrix, Scale);
	
	glm::vec3 lightPos0(0.0f, 0.0f, 2.0f);

	program.setMat4fv(ModelMatrix, "ModelMatrix");
	program.setVec3f(lightPos0, "lightPos0");
	
	return ModelMatrix;
}

void Shape::Draw(Shaders& program)
{
	program.use();
	
	glBindVertexArray(VAO);

	glDrawElements(GL_TRIANGLES, quad_number_of_indices, GL_UNSIGNED_INT, 0);
}

void Shape::SetTexture(std::string fileName)
{
	const char* test = fileName.c_str(); 

	
	
	texture.init(test, GL_TEXTURE_2D, 0);

	texture.bind();
	mat.init(glm::vec3(0.1f), glm::vec3(0.1f), glm::vec3(0.1f), texture.getID(), texture.getID());
	
}
