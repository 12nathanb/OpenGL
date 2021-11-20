#include "Game.h"

Game::Game(GLFWwindow* window, int WindowWidth, int WindowHeight, int framebufferWidth, int frameBufferHight)
{
	//this->core_program = program;
	this->WindowHeight = WindowHeight;
	this->WindowWidth = WindowWidth;
	this->Window = window;
	this->frameBufferHeight = frameBufferHight;
	this->frameBufferWidth = framebufferWidth;
	this->Init();
}

void Game::Init()
{
	//core_program = new Shader("vertex_shader.glsl", "fragment_shader.glsl");
	shapeVec.push_back(new Cube("t3", "box.jpg"));
	shapeVec.push_back(new Pyramid("pyramid", "box.jpg"));

	for (int i = 0; i < shapeVec.size(); i++)
	{
		shaderVec.push_back(shapeVec[i]->getShader());
	}

	//t3 = new Cube("t3");
	//t3->SetTexture("box.jpg");
	//

	//t4 = new Cube("t4");
	//t4->SetTexture("mario.jpg");
	//shaderVec.push_back(t4->getShader());

	
	
	camera = new Camera(shaderVec);

	audio = new Audio();
	//audio.loadFile("test.WAV", true);

	light = new Light();
	input = new Input(Window);
	

	camera->SetCameraPos(glm::vec3(0.0f, 0.0f, 3.0f));
}

void Game::Keyboard_Input()
{
	if (input->isKeyPressed(Window, GLFW_KEY_UP) || input->isKeyPressed(Window, GLFW_KEY_W))
	{
		camera->MoveCamera(glm::vec3(NULL, NULL, -0.01));
	}

	if (input->isKeyPressed(Window, GLFW_KEY_DOWN) || input->isKeyPressed(Window, GLFW_KEY_S))
	{
		camera->MoveCamera(glm::vec3(NULL, NULL, 0.01));
	}

	if (input->isKeyPressed(Window, GLFW_KEY_LEFT) || input->isKeyPressed(Window, GLFW_KEY_A))
	{
		camera->MoveCamera(glm::vec3(-0.01, NULL, NULL));
	}

	if (input->isKeyPressed(Window, GLFW_KEY_RIGHT) || input->isKeyPressed(Window, GLFW_KEY_D))
	{
		camera->MoveCamera(glm::vec3(0.01, NULL, NULL));
	}

	if (input->isKeyPressed(Window, GLFW_KEY_ESCAPE))
	{
		glfwTerminate();
		//return 0;
	}
}

void Game::Mouse_Input()
{
	input->isMouseKeyPressed(Window, GLFW_MOUSE_BUTTON_RIGHT);
}


void Game::Update()
{
	input->Update(Window);
	
	for (int i = 0; i < shapeVec.size(); i++)
	{
		shapeVec[i]->Update();
	}


	//t3->Update();
	//t4->Update();
	camera->Update(shaderVec, Window, frameBufferWidth, frameBufferHeight);
}

void Game::Draw()
{
	for (int i = 0; i < shapeVec.size(); i++)
	{
		shapeVec[i]->Draw();
	}
	//t3->Draw();
	//t4->Draw();
}
