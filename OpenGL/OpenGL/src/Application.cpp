#pragma once

#include "libs.h"
#include "Triangle.h"


GLuint loadShaders(std::string shader_file, std::string type)
{
    char info_log[512];
    GLint success;

    std::string src;


    std::string line;
    std::ifstream in(".\\src\\" + shader_file);
    

    GLuint Shader;


    if (in.is_open())
    {
        while (getline(in, line))
            src += line + "\n";
    }
    else
    {
        std::cout << "ERROR LOADING SHADERS FILE" << std::endl;
    }

    in.close();

    if (type == "VERTEX")
    {
        Shader = glCreateShader(GL_VERTEX_SHADER);
    }
    else if (type == "FRAGMENT")
    {
        Shader = glCreateShader(GL_FRAGMENT_SHADER);
    }
    else
    {
        return 0;
    }
    

    const GLchar* vert_src = src.c_str();
    glShaderSource(Shader, 1, &vert_src, NULL);
    glCompileShader(Shader);

    glGetShaderiv(Shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(Shader, 512, NULL, info_log);

        if (type == "VERTEX")
        {
            std::cout << "ERROR COMPILING VERTEX SHADERS" << std::endl;
        }
        else if (type == "FRAGMENT")
        {
            std::cout << "ERROR COMPILING FRAGMENT SHADERS" << std::endl;
        }
        
        std::cout << info_log << std::endl;
    }


    return Shader;
}

bool createShaders(GLuint& program)
{
    GLint success;
    bool load_success = true;
    char info_log[512];
    GLuint vert_shader = loadShaders("vertex_shader.glsl", "VERTEX");
    GLuint frag_shader = loadShaders("fragment_shader.glsl", "FRAGMENT");


    program = glCreateProgram();

    glAttachShader(program, vert_shader);
    glAttachShader(program, frag_shader);

    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(program, 512, NULL, info_log);
        std::cout << "COULD NOT LINK PROGRAM" << std::endl;
        load_success = false;
        std::cout << info_log << std::endl;
    }

    glUseProgram(0);
    glDeleteShader(vert_shader);
    glDeleteShader(frag_shader);

    return load_success;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    const int WINDOW_WIDTH = 640;
    const int WINDOW_HEIGHT = 480;
    const std::string WINDOW_NAME = "Hello World!";
    int frame_buffer_width = 0;
    int frame_buffer_height = 0;

 

    
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME.c_str(), NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwGetFramebufferSize(window, &frame_buffer_width, &frame_buffer_height);
    glViewport(0, 0, frame_buffer_width, frame_buffer_height);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

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



    if (!createShaders(core_program))
        return -1;



    Triangle t;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Poll for and process events */
        glfwPollEvents();

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        t.Draw(core_program);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        glFlush();
    }

    glDeleteProgram(core_program);

    glfwTerminate();
    return 0;
}

