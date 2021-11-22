#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

class Menu
{
public:
	Menu(GLFWwindow* window);
	void Update();
	void Draw();
	~Menu();
private:
    ImGuiWindowFlags corner =
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoTitleBar;

};

