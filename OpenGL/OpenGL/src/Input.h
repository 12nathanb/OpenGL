#pragma once
#include "libs.h"
class Input
{
public:
	Input();
	void Update(GLuint& program, GLFWwindow* window);
	bool isKeyPressed(GLFWwindow* window, int keycode);
	std::pair<float, float> getMousePos(GLFWwindow* window);
	float getMouseX(GLFWwindow* window);
	float getMouseY(GLFWwindow* window);
private:
	
	

private:
	
	GLFWvidmode vidMode;
};

