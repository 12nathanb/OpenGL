#pragma once
#include<iostream>
#include<string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include<SOIL2.h>

class Texture
{
private:
	GLuint id;
	int width;
	int height;
	unsigned int type;
	GLint Texture_unit;
public:
	Texture();
	~Texture();
	void init(const char* fileName, GLenum type, const GLint texture_unit);
	inline GLuint getID() const { return id; }
	void bind();
	void unbind();
};

