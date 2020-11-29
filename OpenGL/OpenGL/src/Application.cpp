#pragma once
#include "libs.h"
#include "Triangle.h"
#include "Quad.h"
#include "Shader.h"
#include "Window.h"
#include "Input.h"
#include"Audio.h"
#include "Texture.h"

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


    GLuint core_program;

    Shader shader("vertex_shader.glsl", "fragment_shader.glsl", core_program);


    if (!shader.createShaders())
        return -1;

    Input input;
    Audio audio;
    //audio.loadFile("test.WAV", true);

    Texture texture("mario.jpg", GL_TEXTURE_2D);

    texture.bind(1);


    Quad t;
    //Triangle q;
    glm::vec3 Position;
   
    glm::vec3 Scale;


    glm::vec3 camPostion(0.0f, 0.f, 10.0f);
    glm::vec3 worldUp(0.0f, 1.0f, 0.0f);
    glm::vec3 camFront(0.0f, 0.0f, -1.0f);
    glm::mat4 ViewMatrix(1.0f);
    ViewMatrix = glm::lookAt(camPostion, camPostion + camFront, worldUp);
    
    float fov = 90.0f;
    float nearPlane = 0.1f;
    float farPlane = 1000.f;
    glm::mat4 ProjectionMatrix(1.0f);

    ProjectionMatrix = glm::perspective(glm::radians(fov), static_cast<float>(frame_buffer_width) / frame_buffer_height, nearPlane, farPlane);


    glUniformMatrix4fv(glGetUniformLocation(core_program, "ProjectionMatrix"), 1, GL_FALSE, glm::value_ptr(ProjectionMatrix));
    glUniformMatrix4fv(glGetUniformLocation(core_program, "ViewMatrix"), 1, GL_FALSE, glm::value_ptr(ViewMatrix));
   
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window.getWindow()))
    {
        /* Poll for and process events */
        glfwPollEvents();

        
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        
        input.Update(core_program, window.getWindow());


        glfwGetFramebufferSize(window.getWindow(), &frame_buffer_width, &frame_buffer_height);

        glm::mat4 ProjectionMatrix(1.0f);
        ProjectionMatrix = glm::perspective(glm::radians(fov), static_cast<float>(frame_buffer_width) / frame_buffer_height, nearPlane, farPlane);


        glUniformMatrix4fv(glGetUniformLocation(core_program, "ProjectionMatrix"), 1, GL_FALSE, glm::value_ptr(ProjectionMatrix));
        glUniformMatrix4fv(glGetUniformLocation(core_program, "ViewMatrix"), 1, GL_FALSE, glm::value_ptr(ViewMatrix));

        //q.Update(core_program);
        t.Update(core_program, frame_buffer_width, frame_buffer_height);

        //std::cout << window.showFPS() << std::endl;

        if (input.isKeyPressed(window.getWindow(), GLFW_KEY_ESCAPE))
        {
            glDeleteProgram(core_program);

            glfwTerminate();

            return 0;
        }
        
        //q.Draw(core_program);
        t.Draw(core_program);
        /* Swap front and back buffers */
        glfwSwapBuffers(window.getWindow());
        glFlush();
    }

    glDeleteProgram(core_program);

    glfwTerminate();
    return 0;
}

