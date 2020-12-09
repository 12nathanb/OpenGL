#pragma once
#include "libs.h"
#include "Triangle.h"
#include "Quad.h"
#include "Shader.h"
#include "Window.h"
#include "Input.h"
#include"Audio.h"
#include "Texture.h"
#include "Camera.h"
#include"Pyramid.h"

int main(void)
{
    /* Initialize the library */
    
    if (!glfwInit())
        return -1;
    
     int WINDOW_WIDTH = 640;
     int WINDOW_HEIGHT = 480;
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

    Shader core_program("vertex_shader.glsl", "fragment_shader.glsl");

    Camera camera(core_program);
    camera.SetCameraPos(glm::vec3(0.0f, 0.0f, 3.0f));
    Input input;
    Audio audio;
    //audio.loadFile("test.WAV", true);

    Pyramid t;
    //Triangle t2;
    //t.SetTexture("mario.jpg");
    Texture texture0;
    texture0.init("box.jpg", GL_TEXTURE_2D, 0);
    material material0;
    material0.init(glm::vec3(0.1f), glm::vec3(1.1f), glm::vec3(0.1f), texture0.getID(), texture0.getID());
   
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window.getWindow()))
    {
        core_program.use();
        texture0.bind();
        /* Poll for and process events */
        
        glfwPollEvents();
        
        material0.sendToShader(core_program);
        /* Render here */
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        
        input.Update(window.getWindow());
        t.Draw(&core_program);
        //q.Update(core_program);
        
        //t2.Update(&core_program);
        t.Update(&core_program);
        camera.Update(core_program, window.getWindow(), frame_buffer_width, frame_buffer_height);
        //std::cout << window.showFPS() << std::endl;

        //Camera controls
        if (input.isKeyPressed(window.getWindow(), GLFW_KEY_UP) || input.isKeyPressed(window.getWindow(), GLFW_KEY_W))
        {
            t.MoveObject(glm::vec3(NULL, 0.01, NULL));
        }

        if (input.isKeyPressed(window.getWindow(), GLFW_KEY_DOWN) || input.isKeyPressed(window.getWindow(), GLFW_KEY_S))
        {
            t.MoveObject(glm::vec3(NULL, -0.01, NULL));
        }

        if (input.isKeyPressed(window.getWindow(), GLFW_KEY_LEFT) || input.isKeyPressed(window.getWindow(), GLFW_KEY_A))
        {
            t.MoveObject(glm::vec3(-0.01,NULL , NULL));
        }

        if (input.isKeyPressed(window.getWindow(), GLFW_KEY_RIGHT) || input.isKeyPressed(window.getWindow(), GLFW_KEY_D))
        {
            t.MoveObject(glm::vec3(0.01, NULL, NULL));
        }

        if (input.isKeyPressed(window.getWindow(), GLFW_KEY_Q))
        {
            t.RotateObject(glm::vec3(NULL, -0.5, NULL));
        }
        
        if (input.isKeyPressed(window.getWindow(), GLFW_KEY_E))
        {
            t.RotateObject(glm::vec3(NULL, 0.5, NULL));
        }

        if (input.isKeyPressed(window.getWindow(), GLFW_KEY_ESCAPE))
        {
         

            glfwTerminate();

            return 0;
        }
        
       

        /* Swap front and back buffers */
        glfwSwapBuffers(window.getWindow());
        glFlush();
    }


    glfwTerminate();
    return 0;
}

