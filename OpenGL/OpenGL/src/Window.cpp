#include "Window.h"

Window::Window(int& window_width, int& window_height, int& frame_buffer_width, int& frame_buffer_height, std::string& program_name)
{
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    window = glfwCreateWindow(window_width, window_height, program_name.c_str(), NULL, NULL);

    if (!window)
    {
        glfwTerminate();
    }

    glfwGetFramebufferSize(window, &frame_buffer_width, &frame_buffer_height);
    glViewport(0, 0, frame_buffer_width, frame_buffer_height);

    glfwMakeContextCurrent(window);

}

GLFWwindow* Window::getWindow()
{
    return window;
}