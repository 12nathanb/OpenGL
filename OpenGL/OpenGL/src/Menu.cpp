#include "Menu.h"

Menu::Menu(GLFWwindow* window)
{
    this->window = window;
    
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    
}

void Menu::Update()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    
    glfwGetWindowSize(window, &width, &height);
    ImGui::SetNextWindowSize(ImVec2((width / 4), height));
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::Begin("Menu", 0, ImGuiWindowFlags_NoResize);
}

void Menu::Draw()
{
    ImGui::End();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

Menu::~Menu()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
