#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

class Input
{
public:
	Input();
	void Update(GLFWwindow* window);
	bool isKeyPressed(GLFWwindow* window, int keycode);
	std::pair<float, float> getMousePos(GLFWwindow* window);
	float getMouseX(GLFWwindow* window);
	float getMouseY(GLFWwindow* window);

private:
	
	

private:
	
	GLFWvidmode vidMode;
};

