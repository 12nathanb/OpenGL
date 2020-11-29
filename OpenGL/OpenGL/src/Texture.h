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
	Texture(const char* fileName, GLenum type);
	~Texture();
	inline GLuint getID() const { return this->id; }
	void bind(const GLint texture_unit);
	void unbind();
	void loadFromFile(const char* fileName);
};

