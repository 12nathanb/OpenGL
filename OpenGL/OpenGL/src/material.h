#pragma once
#include <glm.hpp>
#include "Shader.h"

class material
{
private:

public:
	void init(glm::vec3 ambient,
		glm::vec3 diffuse,
		glm::vec3 specular,
		GLint diffuseTex,
		GLint specularTex);



	void sendToShader(Shader* programID);

private:
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	GLint diffuseTex;
	GLint specularTex;
	glm::vec3 lightPos0;
};

