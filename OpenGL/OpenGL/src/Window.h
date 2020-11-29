#pragma once
#include "libs.h"

class Window
{
public:
	Window(int& window_width, int& window_height, int& frame_buffer_width, int& frame_buffer_height, std::string& program_name);
	//~Window();

	GLFWwindow* getWindow();

private:
	GLFWwindow* window;
};

