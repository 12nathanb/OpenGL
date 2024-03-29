#include "material.h"

void material::init(glm::vec3 ambient,
					glm::vec3 diffuse,
					glm::vec3 specular,
					GLint diffuseTex,
					GLint specularTex)
{
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specular = specular;
	this->Diffuse_texture = diffuseTex;
	this->Specular_texture = specularTex;
}





void material::sendToShader(Shader* program)
{
	program->setVec3f(this->ambient, "material.ambient");
	program->setVec3f(this->diffuse, "material.diffuse");
	program->setVec3f(this->specular, "material.specular");

	program->setVec1i(this->Diffuse_texture, "material.diffuseTex");
	program->setVec1i(this->Specular_texture, "material.specularTex");
}
