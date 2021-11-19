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
#include "Light.h"
#include "Cube.h"

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

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window.getWindow(), true);
    ImGui_ImplOpenGL3_Init("#version 330");
    ImGui::SetNextWindowPos(ImVec2(0, 0));

    Shader core_program("vertex_shader.glsl", "fragment_shader.glsl");

    Camera camera(&core_program);
    camera.SetCameraPos(glm::vec3(0.0f, 0.0f, 3.0f));
    Input input(window.getWindow());
    Audio audio;
    Light light;
    //audio.loadFile("test.WAV", true);
    //Pyramid t("t");
    Cube t2("t2");
    Cube t3("T3");

    int amount = 10;

    float ambientAmount = 1.1f;
    float diffuseAmount = 0.1f;
    float specularAmount = 0.1f;
    std::pair<float, float> mousePos;
    Texture texture0;
    texture0.init("box.jpg", GL_TEXTURE_2D, 0);
    material material0;
    
    //t.SetPosition(glm::vec3(0, 0, 0));
    t2.SetPosition(glm::vec3(2, 0, 0));
    t3.SetPosition(glm::vec3(-2, 0, 0));
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window.getWindow()))
    {
        core_program.use();
        texture0.bind();
        /* Poll for and process events */
        
        glfwPollEvents();
        material0.init(glm::vec3(ambientAmount), glm::vec3(diffuseAmount), glm::vec3(specularAmount), texture0.getID(), texture0.getID());
        material0.sendToShader(core_program);
        /* Render here */
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();


        ImGui::Begin("Object Settings");

        ImGui::SliderFloat("Ambient", &ambientAmount, 0.1f, 10.f);
        ImGui::SliderFloat("Diffuse", &diffuseAmount, 0.1f, 10.f);
        ImGui::SliderFloat("Specular", &specularAmount, 0.1f, 10.f);



        ImGui::End();

        
        input.Update(window.getWindow());
     
        
        camera.Update(&core_program, window.getWindow(), frame_buffer_width, frame_buffer_height);


       // t.Update(&core_program);
        t2.Update(&core_program);
        t3.Update(&core_program);
        //Camera controls
        if (input.isKeyPressed(window.getWindow(), GLFW_KEY_UP) || input.isKeyPressed(window.getWindow(), GLFW_KEY_W))
        {
            camera.MoveCamera(glm::vec3(NULL, NULL, -0.01));
        }

        if (input.isKeyPressed(window.getWindow(), GLFW_KEY_DOWN) || input.isKeyPressed(window.getWindow(), GLFW_KEY_S))
        {
            camera.MoveCamera(glm::vec3(NULL, NULL, 0.01));
        }

        if (input.isKeyPressed(window.getWindow(), GLFW_KEY_LEFT) || input.isKeyPressed(window.getWindow(), GLFW_KEY_A))
        {
            camera.MoveCamera(glm::vec3(-0.01, NULL, NULL));
        }

        if (input.isKeyPressed(window.getWindow(), GLFW_KEY_RIGHT) || input.isKeyPressed(window.getWindow(), GLFW_KEY_D))
        {
            camera.MoveCamera(glm::vec3(0.01, NULL, NULL));
        }

        if (input.isKeyPressed(window.getWindow(), GLFW_KEY_ESCAPE))
        {
            glfwTerminate();
            return 0;
        }

        input.isMouseKeyPressed(window.getWindow(), GLFW_MOUSE_BUTTON_RIGHT);

       // t.Draw(&core_program);
        t2.Draw(&core_program);
        t3.Draw(&core_program);
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        /* Swap front and back buffers */
        glfwSwapBuffers(window.getWindow());
        glFlush();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();

    return 0;
}

void init()
{
    
}

void input()
{

}

void update()
{

}

void draw()
{

}