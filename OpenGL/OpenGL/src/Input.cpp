#include "Input.h"

Input::Input(GLFWwindow* window)
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

bool Input::isMouseKeyPressed(GLFWwindow* window, int keycode)
{
    int state = glfwGetMouseButton(window, keycode);
    if (state == GLFW_PRESS)
    {
        std::cout << "pressed" << "\n";
    }

    return state == GLFW_PRESS;
    
}

std::pair<float, float> Input::getMousePos(GLFWwindow* window)
{
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    return { (float)xpos, (float)ypos };
}


