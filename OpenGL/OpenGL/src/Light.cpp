#include "Light.h"

Light::Light()
{
	glm::vec3 lightPos0(0.0f, 0.0f, 2.0f);
}

void Light::Draw(Shader* program)
{
	program->setVec3f(lightPos0, "lightPos0");
}
