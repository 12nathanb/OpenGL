#include "Shader.h"
#include "Cube.h"
#include "Camera.h"
#include"Audio.h"
#include "Light.h"
#include "Input.h"
#include "Pyramid.h"
#include "Menu.h"
#include "gameObject.h"

class Game
{
public:
	Game(GLFWwindow* window, int WindowWidth, int WindowHeight, int framebufferWidth, int frameBufferHight);
	void Init();
	void Keyboard_Input();
	void Mouse_Input();
	void Update();
	void Draw();
	void updateDt();

private:
	GLFWwindow* Window;
	int WindowWidth;
	int WindowHeight;
	int frameBufferWidth;
	int frameBufferHeight;
	float dt;
	float curTime;
	float lastTime;
	Cube* t3;
	Cube* t4;

	double lastMouseX;
	double lastMouseY;
	double mouseX;
	double mouseY;
	double mouseOffsetX;
	double mouseOffsetY;
	bool firstMouse;

	Camera* camera;
	Audio* audio;
	Light* light;
	Input* input;
	Shader* core_program;
	std::vector<Shader*> shaderVec;
	std::vector<Shape*> shapeVec;
	Menu* menu;
	std::pair<float, float> mousePos;

};