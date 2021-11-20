#include "Shader.h"
#include "Cube.h"
#include "Camera.h"
#include"Audio.h"
#include "Light.h"
#include "Input.h"
#include "Pyramid.h"

class Game
{
public:
	Game(GLFWwindow* window, int WindowWidth, int WindowHeight, int framebufferWidth, int frameBufferHight);
	void Init();
	void Keyboard_Input();
	void Mouse_Input();
	void textureBind();
	void Update();
	void Draw();
private:
	GLFWwindow* Window;
	int WindowWidth;
	int WindowHeight;
	int frameBufferWidth;
	int frameBufferHeight;

	Cube* t3;
	Cube* t4;

	Camera* camera;
	Audio* audio;
	Light* light;
	Input* input;
	Shader* core_program;
	std::vector<Shader*> shaderVec;
	std::vector<Shape*> shapeVec;
};