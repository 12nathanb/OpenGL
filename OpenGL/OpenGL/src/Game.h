#include "Shader.h"
#include "Cube.h"
#include "Camera.h"
#include"Audio.h"
#include "Light.h"
#include "Input.h"
#include "Pyramid.h"
#include "Menu.h"
#include "gameObject.h"
#include "Torus.h"
#include "IcoSphere.h"
#include "Quad.h"
#include "Sphere.h"
#include "Cylinder.h"
#include <ctime>

class Game
{
public:
	Game(GLFWwindow* window, int framebufferWidth, int frameBufferHight);
	void Init();
	void Keyboard_Input();
	void Mouse_Input();
	void Update();
	void Draw();
	void updateDt();

private:
	GLFWwindow* Window;

	int Frame_buffer_width;
	int Frame_buffer_height;

	float Delta_time = 0.f;;
	float Current_time;
	float Last_time;

	double Last_mouse_x = 0.0;
	double Last_mouse_y = 0.0;
	double Mouse_x = 0.0;
	double Mouse_y = 0.0;
	double Mouse_offset_x = 0.0;
	double Mouse_offset_y = 0.0;

	bool First_mouse = true;

	clock_t current_ticks, delta_ticks;
	clock_t fps = 0;

	Camera* camera;
	Audio* audio;
	Light* light;
	Input* input;
	Shader* shader;
	Menu* menu;

	std::vector<Shader*> Shader_vector;
	std::vector<Shape*> Shape_vector;
};