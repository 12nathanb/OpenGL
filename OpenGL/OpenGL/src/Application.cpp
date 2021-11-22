#pragma once
#include "libs.h"
#include "Triangle.h"
#include "Shader.h"
#include "Window.h"
#include "Input.h"
#include"Audio.h"
#include "Texture.h"
#include "Camera.h"
#include"Pyramid.h"
#include "Light.h"
#include "Cube.h"
#include "Game.h"

int main(void)
{
    /* Initialize the library */
    
    if (!glfwInit())
        return -1;
    
     
    int WINDOW_WIDTH = 1280;
    int WINDOW_HEIGHT = 720;
    std::string WINDOW_NAME = "Hello World!";
    int frame_buffer_width = 0;
    int frame_buffer_height = 0;

    Window window(WINDOW_WIDTH, WINDOW_HEIGHT, frame_buffer_width, frame_buffer_height, WINDOW_NAME);
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window.getWindow());

    glewExperimental = GL_TRUE;

    /*initilise*/
    if (glewInit() != GLEW_OK)
    {
        std::cout << "ERROR WITH GLEW INIT" << std::endl;
        glfwTerminate();
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_CULL_FACE);

    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Game game(window.getWindow(), WINDOW_WIDTH, WINDOW_HEIGHT, frame_buffer_width, frame_buffer_height);

    while (!glfwWindowShouldClose(window.getWindow()))
    {

        glfwPollEvents();
        game.Update();
        game.Keyboard_Input();
        game.Mouse_Input();

        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        
        game.Draw();
        

        glfwSwapBuffers(window.getWindow());
        glFlush();
    }

    glfwTerminate();

    return 0;
}
