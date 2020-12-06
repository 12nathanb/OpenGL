#include "Texture.h"

Texture::Texture()
{
	
}

Texture::~Texture()
{
	glDeleteTextures(1, &this->id);
}

void Texture::init(const char* fileName, GLenum type, const GLint texture_unit)
{
	this->texture_unit = texture_unit;
	this->type = type;
	std::string dir = ".\\src\\Resources\\Images\\";
	dir += fileName;
	std::cout << fileName << std::endl;
	const char* file = dir.c_str();
	std::cout << file << std::endl;
	unsigned char* image = SOIL_load_image(file, &this->width, &this->height, NULL, SOIL_LOAD_RGBA);

	glGenTextures(1, &this->id);
	glBindTexture(type, this->id);

	glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	if (image)
	{
		glTexImage2D(type, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(type);
	}
	else
	{
		std::cout << "ERROR::TEXTURE::TEXTURE_LOADING_FAILED: " << fileName << "\n";
	}

	glActiveTexture(0);
	glBindTexture(type, 0);
	SOIL_free_image_data(image);
}

void Texture::bind()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(this->type, this->id);
}

void Texture::unbind()
{
	//glActiveTexture(0);
	//glBindTexture(this->type, 0);
}

