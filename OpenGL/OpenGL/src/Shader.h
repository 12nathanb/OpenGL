#pragma once
#include "libs.h"

class Shader
{
public:
	Shader(std::string vertex_shader_file, std::string fragment_shader_file, GLuint& program);
	~Shader();
	GLuint loadShaders(std::string& shader_file, std::string shader_type);
	bool createShaders();
private:
	std::string VERTEX_SHADER_FILE;
	std::string FRAGMENT_SHADER_FILE;
	GLuint& core_program;
};

