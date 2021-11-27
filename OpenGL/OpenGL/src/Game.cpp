#include "Game.h"

Game::Game(GLFWwindow* window, int framebufferWidth, int frameBufferHight)
{
	this->Window = window;
	this->Frame_buffer_height = frameBufferHight;
	this->Frame_buffer_width = framebufferWidth;
	this->Init();
}

void Game::Init()
{	
	camera = new Camera();

	audio = new Audio();
	//audio.loadFile("test.WAV", true);

	light = new Light();
	input = new Input(Window);
	
	menu = new Menu(this->Window);
}

void Game::Keyboard_Input()
{
	if (input->isKeyPressed(Window, GLFW_KEY_UP) || input->isKeyPressed(Window, GLFW_KEY_W))
	{
		camera->move(Delta_time, FORWARD);
	}

	if (input->isKeyPressed(Window, GLFW_KEY_DOWN) || input->isKeyPressed(Window, GLFW_KEY_S))
	{
		camera->move(Delta_time, BACKWARD);
	}

	if (input->isKeyPressed(Window, GLFW_KEY_LEFT) || input->isKeyPressed(Window, GLFW_KEY_A))
	{
		camera->move(Delta_time, LEFT);
	}

	if (input->isKeyPressed(Window, GLFW_KEY_RIGHT) || input->isKeyPressed(Window, GLFW_KEY_D))
	{
		camera->move(Delta_time, RIGHT);
	}

	if (input->isKeyPressed(Window, GLFW_KEY_ESCAPE))
	{
		glfwTerminate();
	}
}

void Game::Mouse_Input()
{
	glfwGetCursorPos(this->Window, &this->Mouse_x, &this->Mouse_y);

	if (this->First_mouse)
	{
		this->Last_mouse_x = this->Mouse_x;
		this->Last_mouse_y = this->Mouse_y;
		this->First_mouse = false;
	}

	//Calc offset
	this->Mouse_offset_x = this->Mouse_x - this->Last_mouse_x;
	this->Mouse_offset_y = this->Last_mouse_y - this->Mouse_y;

	//Set last X and Y
	this->Last_mouse_x = this->Mouse_x;
	this->Last_mouse_y = this->Mouse_y;

	if (input->isMouseKeyPressed(Window, 2))
	{
		camera->updateInput(Delta_time, -1, this->Mouse_offset_x, this->Mouse_offset_y);
	}

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
}

void Game::Update()
{
	
	this->updateDt();
	
	menu->Update();
	
	ImGui::Begin("Menu", 0 , ImGuiTreeNodeFlags_CollapsingHeader);

	std::string objcount = "object count: " + std::to_string(Shape_vector.size());
	std::string fpsStr = " fps: " + std::to_string(fps);

	ImGui::Text(objcount.c_str());
	ImGui::SameLine();
	ImGui::Text(fpsStr.c_str());
	
	ImGui::BeginChild("Create Object", ImVec2(0, ImGui::GetFontSize() * 20.0f), true, ImGuiWindowFlags_MenuBar);
	static char str1[128] = "";
	ImGui::InputText("Object Name", str1, IM_ARRAYSIZE(str1));
	static char str2[128] = "";
	ImGui::InputText("Object texture", str2, IM_ARRAYSIZE(str2));
	static char str3[128] = "";
	const char* listbox_items[] = { "Cube", "Cone", "Plane", "Torus", "Cylinder" , "Icosphere", "Sphere","Custom"};
	static int listbox_item_current = 0;
	ImGui::ListBox("Choose Object Type", &listbox_item_current, listbox_items, IM_ARRAYSIZE(listbox_items), 4);

	if (listbox_item_current == 7)
	{
		ImGui::InputText("obj file", str3, IM_ARRAYSIZE(str3));
	}

	if (ImGui::Button("Create Object") && strlen(str1) != 0 && strlen(str2) != 0)
	{
		bool create = true;

		for (int i = 0; i < Shape_vector.size(); i++)
		{
			if (Shape_vector[i]->getObjName() == str1)
			{
				create = false;
			}
		}

		if (create == true)
		{
			if (listbox_item_current != 7)
			{
				if (listbox_item_current == 0)
				{
					Shape_vector.push_back(new Cube(str1, str2));
				}
				else if (listbox_item_current == 1)
				{
					Shape_vector.push_back(new Pyramid(str1, str2));
				}
				else if (listbox_item_current == 2)
				{
					Shape_vector.push_back(new Quad(str1, str2));
				}

				else if (listbox_item_current == 3)
				{
					Shape_vector.push_back(new Torus(str1, str2));
				}

				else if (listbox_item_current == 4)
				{
					Shape_vector.push_back(new Cylinder(str1, str2));
				}

				else if (listbox_item_current == 5)
				{
					Shape_vector.push_back(new IcoSphere(str1, str2));
				}

				else if (listbox_item_current == 6)
				{
					Shape_vector.push_back(new Sphere(str1, str2));
				}


				Shader_vector.push_back(Shape_vector.back()->getShader());
			}
			else if (listbox_item_current == 7 && strlen(str3) != 0)
			{
				Shape_vector.push_back(new gameObject(str1, str3, str2));
				Shader_vector.push_back(Shape_vector.back()->getShader());
			}
			
		}
		
	}
	ImGui::EndChild();
	ImGui::End();
	camera->Update(Window);
	input->Update(Window);
	for (int i = 0; i < Shape_vector.size(); i++)
	{
		Shape_vector[i]->Update();
	}

	
	
}

void Game::Draw()
{
	current_ticks = clock();
	for (int i = 0; i < Shape_vector.size(); i++)
	{
		Shader_vector[i]->setMat4fv(camera->GetProjectionMatrix(), "ProjectionMatrix");
		Shader_vector[i]->setMat4fv(camera->GetViewMatrix(), "ViewMatrix");
		Shader_vector[i]->setVec3f(camera->GetCameraPos(), "cameraPos");
		Shape_vector[i]->Draw();
	}

	menu->Draw();

	delta_ticks = clock() - current_ticks; //the time, in ms, that took to render the scene
	if (delta_ticks > 0)
		fps = CLOCKS_PER_SEC / delta_ticks;
}

void Game::updateDt()
{
	this->Current_time = static_cast<float>(glfwGetTime());
	this->Delta_time = this->Current_time - this->Last_time;
	this->Last_time = this->Current_time;
}
