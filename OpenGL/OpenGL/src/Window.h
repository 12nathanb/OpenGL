#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class Window
{
public:
	Window(int& window_width, int& window_height, int& frame_buffer_width, int& frame_buffer_height, std::string& program_name);
	//~Window();
	int showFPS();
	GLFWwindow* getWindow();

private:
	GLFWwindow* window;
	double t, t0, fps;
	int frames = 0;
};

