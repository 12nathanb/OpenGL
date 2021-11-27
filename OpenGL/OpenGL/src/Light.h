#pragma once
#include <glm.hpp>
#include "Shader.h"

class Light
{
public:
	Light();
	void SetLightPosition(glm::vec3 pos) { Light_position_0 = pos; }
	void Draw(Shader* program);
private:
	glm::vec3 Light_position_0;
};

