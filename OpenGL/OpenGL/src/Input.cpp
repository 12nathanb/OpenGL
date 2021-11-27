#include "Input.h"

Input::Input(GLFWwindow* window)
{
    glfwSetWindowUserPointer(window, this);
    GLFWvidmode return_struct;
}

void Input::Update(GLFWwindow* window)
{
    glfwSetScrollCallback(window, scrollCallbackstatic);
    
    
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
        std::cout << "pressed:" << keycode << "\n";
        return true;
    }
    else
    {
        return false;
    }

    
}

std::pair<float, float> Input::getMousePos(GLFWwindow* window)
{
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    return { (float)xpos, (float)ypos };
}

int Input::getScrollY()
{
    float yvalue = scrollY;
    return yvalue;
}

int Input::getScrollX()
{
    float xvalue = scrollX;
    scrollX = 0;
    std::cout << xvalue << "\n";
    return xvalue;
}

void Input::scrollCallbackstatic(GLFWwindow* window, double xoffset, double yoffset)
{
    Input* that = static_cast<Input*>(glfwGetWindowUserPointer(window));
    that->scrollCallback(window, xoffset, yoffset);
}

void Input::scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    scrollY = yoffset;
    scrollX = xoffset;
}





