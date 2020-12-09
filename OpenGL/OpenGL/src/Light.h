#pragma once
#include <glm.hpp>
#include "Shader.h"

class Light
{
public:
	Light();
	void SetLightPosition(glm::vec3 pos) { lightPos0 = pos; }
	void Draw(Shader* program);
private:
	glm::vec3 lightPos0;
};

