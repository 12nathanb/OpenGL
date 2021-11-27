#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

class Input
{
public:
	Input(GLFWwindow* window);

	void Update(GLFWwindow* window);
	void setScrollY() { scrollY = 0; }

	bool isKeyPressed(GLFWwindow* window, int keycode);
	bool isMouseKeyPressed(GLFWwindow* window, int keycode);

	std::pair<float, float> getMousePos(GLFWwindow* window);

	int getScrollY();
	int getScrollX();
	
private:
	static void scrollCallbackstatic(GLFWwindow* window, double xoffset, double yoffset);
	void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

private:
	GLFWvidmode vidMode;
	double scrollX;
	double scrollY;
};

