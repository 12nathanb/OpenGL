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
	shapeVec.push_back(new Cube("t3", "box.jpg"));
	shapeVec.push_back(new Pyramid("pyramid", "box.jpg"));

	for (int i = 0; i < shapeVec.size(); i++)
	{
		shaderVec.push_back(shapeVec[i]->getShader());
	}
	
	camera = new Camera(shaderVec);

	audio = new Audio();
	//audio.loadFile("test.WAV", true);

	light = new Light();
	input = new Input(Window);
	
	menu = new Menu(this->Window);

	camera->SetCameraPos(glm::vec3(0.0f, 0.0f, 3.0f));
}

void Game::Keyboard_Input()
{
	if (input->isKeyPressed(Window, GLFW_KEY_UP) || input->isKeyPressed(Window, GLFW_KEY_W))
	{
	}

	if (input->isKeyPressed(Window, GLFW_KEY_DOWN) || input->isKeyPressed(Window, GLFW_KEY_S))
	{
		
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
	}

	
}

void Game::Mouse_Input()
{
	mousePos = input->getMousePos(Window);
	if (input->getScrollY() >= 1)
	{

		camera->MoveCamera(glm::vec3(NULL, NULL, -0.3));
		input->setScrollY();
	}

	if (input->getScrollY() < 0)
	{
		camera->MoveCamera(glm::vec3(NULL, NULL, 0.3));
		input->setScrollY();
	}
	input->isMouseKeyPressed(Window, 0);
	input->isMouseKeyPressed(Window, 1);

	if (input->isMouseKeyPressed(Window, 2))
	{
		
	}


	input->isMouseKeyPressed(Window, 3);
	input->isMouseKeyPressed(Window, 4);
	input->isMouseKeyPressed(Window, 5);
	input->isMouseKeyPressed(Window, 6);

}

void Game::Update()
{
	menu->Update();
	input->Update(Window);
	
	for (int i = 0; i < shapeVec.size(); i++)
	{
		shapeVec[i]->Update();
	}

	camera->Update(shaderVec, Window, frameBufferWidth, frameBufferHeight);
}

void Game::Draw()
{
	
	for (int i = 0; i < shapeVec.size(); i++)
	{
		shapeVec[i]->Draw();
	}

	menu->Draw();
}
