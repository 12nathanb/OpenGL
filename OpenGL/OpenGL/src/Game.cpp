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
	//shapeVec.push_back(new Cube("t3", "box.jpg"));
	//shapeVec.push_back(new Pyramid("pyramid", "box.jpg"));

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
		camera->MoveCamera(glm::vec3(NULL, 0.01, NULL));
	}

	if (input->isKeyPressed(Window, GLFW_KEY_DOWN) || input->isKeyPressed(Window, GLFW_KEY_S))
	{
		camera->MoveCamera(glm::vec3(NULL, -0.01, NULL));
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
	if (input->isMouseKeyPressed(Window, 0))
	{

	}
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
	
	ImGui::Begin("Create Objects");
	static char str1[128] = "";
	ImGui::InputText("Object Name", str1, IM_ARRAYSIZE(str1));
	static char str2[128] = "";
	ImGui::InputText("Object texture", str2, IM_ARRAYSIZE(str1));
	const char* listbox_items[] = { "Cube", "Pyramid"};
	static int listbox_item_current = 0;
	ImGui::ListBox("Choose Object Type", &listbox_item_current, listbox_items, IM_ARRAYSIZE(listbox_items), 4);

	if (ImGui::Button("Create Object") && strlen(str1) != 0 && strlen(str2) != 0)
	{
		bool create = true;

		for (int i = 0; i < shapeVec.size(); i++)
		{
			if (shapeVec[i]->getObjName() == str1)
			{
				create = false;
			}
		}

		if (create == true)
		{
			std::cout << "Current Object count: " << shapeVec.size() << "\n";
			if (listbox_item_current == 0)
			{
				shapeVec.push_back(new Cube(str1, str2));
			}
			else if (listbox_item_current == 1)
			{
				shapeVec.push_back(new Pyramid(str1, str2));
			}

			shaderVec.push_back(shapeVec.back()->getShader());
		}
		
	}
	ImGui::End();
	
	for (int i = 0; i < shapeVec.size(); i++)
	{
		shapeVec[i]->Update();
	}

	input->Update(Window);
	
	

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
