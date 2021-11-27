#include "Shape.h"

Shape::Shape()
{
}

void Shape::Init(Vertex* vertexArray, const unsigned& num_of_vert, GLuint* indexArray, const unsigned& num_of_indi)
{
	shader = new Shader("vertex_shader.glsl", "fragment_shader.glsl");

	for (size_t i = 0; i < num_of_vert; i++)
	{
		this->Vertices_array.push_back(vertexArray[i]);
	}

	for (size_t i = 0; i < num_of_indi; i++)
	{
		this->Indices_array.push_back(indexArray[i]);
	}

	createShape(Vertices_array, Indices_array);

}

void Shape::createShape(std::vector<Vertex> vert, std::vector<GLuint> indi)
{
	number_of_vertices = vert.size();
	number_of_indices = indi.size();

	VAO.CreateVertexArray(1);

	VBO.GenerateBuffers(1);
	VBO.BindBuffer(number_of_vertices, vert.data(), GL_STATIC_DRAW);

	if (indi.size() > 0)
	{
		EBO.GenerateBuffers(1);
		EBO.BindBuffer(number_of_indices, indi.data(), GL_STATIC_DRAW);
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


void Shape::Update()
{
	Material_0.init(glm::vec3(Ambient_amount), glm::vec3(Diffuse_amount), glm::vec3(Specular_amount), Texture_0.getID(), Texture_0.getID());
	glm::vec3 lightPos0(0.0f, 0.0f, 2.0f);
	
	shader->setVec3f(lightPos0, "lightPos0");
	ShapeMenu();
}


void Shape::Draw()
{
	this->updateModelMatrix();
	this->updateUniforms(shader);
	Texture_0.bind();
	Material_0.sendToShader(shader);
	shader->use();

	glBindVertexArray(VAO.GetVertexArray());

	if (this->number_of_indices == 0)
	{
		glDrawArrays(GL_TRIANGLES, 0, this->number_of_vertices);

	}
	else
	{
		glDrawElements(GL_TRIANGLES, number_of_indices, GL_UNSIGNED_INT, 0);

	}
	
	
}

void Shape::SetTexture(std::string fileName)
{
	const char* test = fileName.c_str(); 
	
	Texture_0.init(fileName.c_str(), GL_TEXTURE_2D, 0);
	
	Material_0.init(glm::vec3(0.1f), glm::vec3(0.1f), glm::vec3(0.1f), Texture_0.getID(), Texture_0.getID());
	std::cout << "texture id: " << Texture_0.getID() << "\n";
}

void Shape::updateModelMatrix()
{
	this->Model_matrix = glm::mat4(1.f);
	this->Model_matrix = glm::translate(this->Model_matrix, this->Position);
	this->Model_matrix = glm::rotate(this->Model_matrix, glm::radians(this->Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	this->Model_matrix = glm::rotate(this->Model_matrix, glm::radians(this->Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	this->Model_matrix = glm::rotate(this->Model_matrix, glm::radians(this->Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	this->Model_matrix = glm::scale(this->Model_matrix, this->Scale);
}

void Shape::ShapeMenu()
{
	std::string title = this->Object_name + " settings";
	std::string position = this->Object_name + "_position";
	std::string rotate = this->Object_name + "_rotate";
	std::string scale = this->Object_name + "_scale";
	std::string ambient = this->Object_name + "_Ambient";
	std::string diffuse = this->Object_name + "_Diffuse";
	std::string specular = this->Object_name + "_Specular";
	std::string light = this->Object_name + "_light";


	ImGui::BeginChild(title.c_str(), ImVec2(0, ImGui::GetFontSize() * 20.0f), true, ImGuiWindowFlags_MenuBar);

	ImGui::InputFloat3(position.c_str(), (float*)&Position);
	ImGui::InputFloat3(rotate.c_str(), (float*)&Rotation);
	ImGui::InputFloat3(scale.c_str(), (float*)&Scale);
	ImGui::SliderFloat(ambient.c_str(), &Ambient_amount, 0.1f, 10.f);
	ImGui::SliderFloat(diffuse.c_str(), &Diffuse_amount, 0.1f, 10.f);
	ImGui::SliderFloat(specular.c_str(), &Specular_amount, 0.1f, 10.f);
	ImGui::SliderFloat3(light.c_str(), (float*)&Light_position_0, 0.0f, 10.0f);
	ImGui::EndChild();
}

