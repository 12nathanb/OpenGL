#pragma once
#include <iostream>
#include <fstream> 
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include<glm.hpp>
#include<vec2.hpp>
#include<vec3.hpp>
#include<vec4.hpp>
#include<mat4x4.hpp>
#include<gtc/matrix_transform.hpp>
#include<gtc/type_ptr.hpp>


class Shader
{
private:
	std::string loadShaderSource(const char* fileName);
	GLuint loadShader(GLenum type, const char* fileName);
	void linkProgram(GLuint vertexShader, GLuint geometryShader, GLuint fragmentShader);

public:

	Shader(const char* vertexFile, const char* fragmentFile, const char* geomtryFile = "");
	~Shader() { glDeleteProgram(this->id); }
	void use() { glUseProgram(this->id); }
	void unuse() { glUseProgram(0); }

	void setVec1i(GLint value, const GLchar* name);
	void setVec1f(GLfloat value, const GLchar* name);
	void setVec2f(glm::fvec2 value, const GLchar* name);
	void setVec3f(glm::fvec3 value, const GLchar* name);
	void setVec4f(glm::fvec4 value, const GLchar* name);
	void setMat4fv(glm::mat4 value, const GLchar* name, bool transpose = GL_FALSE);
	void setMat3fv(glm::mat3 value, const GLchar* name, bool transpose = GL_FALSE);
private:
	GLuint id;
};

