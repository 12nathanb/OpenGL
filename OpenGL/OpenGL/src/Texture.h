#pragma once

#include<iostream>
#include<string>

#include"libs.h"

#include<SOIL2.h>

class Texture
{
private:
	GLuint id;
	int width;
	int height;
	unsigned int type;

public:
	Texture();
	~Texture();
	void init(const char* fileName, GLenum type);
	inline GLuint getID() const { return id; }
	void bind(const GLint texture_unit);
	void unbind();
};

