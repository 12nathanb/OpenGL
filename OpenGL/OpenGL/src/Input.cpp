#include "Input.h"

Input::Input()
{
    GLFWvidmode return_struct;
}

void Input::Update(GLFWwindow* window)
{
   
    std::pair<float, float> mouse = getMousePos(window);

    bool t = isKeyPressed(window, GLFW_KEY_ESCAPE);
}

bool Input::isKeyPressed(GLFWwindow* window, int keycode)
{
    auto state = glfwGetKey(window, keycode);

    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

std::pair<float, float> Input::getMousePos(GLFWwindow* window)
{
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    return { (float)xpos, (float)ypos };
}

float Input::getMouseX(GLFWwindow* window)
{
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    return ypos;
}

float Input::getMouseY(GLFWwindow* window)
{
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    return xpos;
}

