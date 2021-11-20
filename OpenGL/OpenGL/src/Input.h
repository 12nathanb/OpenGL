#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

class Input
{
public:
	Input(GLFWwindow* window);
	void Update(GLFWwindow* window);
	bool isKeyPressed(GLFWwindow* window, int keycode);
	bool isMouseKeyPressed(GLFWwindow* window, int keycode);
	std::pair<float, float> getMousePos(GLFWwindow* window);
private:
	
	GLFWvidmode vidMode;
};

