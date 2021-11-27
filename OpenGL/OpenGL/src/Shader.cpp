#include "Shader.h"

Shader::Shader(const char* vertexFile,  const char* fragmentFile,  const char* geomtryFile)
{
	const char* fileDir = ".\\src\\Resources\\Shaders\\";
	
	std::string vertFile(std::string(fileDir) + vertexFile);
	std::string fragFile(std::string(fileDir) + fragmentFile);
	std::string geoFile(std::string(fileDir) + geomtryFile);

	std::cout << "[Shader.cpp] Loaded vertex shader file: " << vertFile << std::endl;
	std::cout << "[Shader.cpp] Loaded fragment shader file: " << fragFile << std::endl;
	std::cout << "[Shader.cpp] Loaded geometry shader file: " << geoFile << std::endl;

	GLuint vertexShader = 0;
	GLuint geometryShader = 0;
	GLuint fragmentShader = 0;

	
	
	vertexShader = loadShader(GL_VERTEX_SHADER, vertFile.c_str());

	if (geomtryFile != "")
	{
		geometryShader = loadShader(GL_GEOMETRY_SHADER, geoFile.c_str());
	}

	fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragFile.c_str());

	this->linkProgram(vertexShader, geometryShader, fragmentShader);
	
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glDeleteShader(geometryShader);
	
}

void Shader::setVec1i(GLint value, const GLchar* name)
{
	this->use();
	glUniform1i(glGetUniformLocation(this->id, name), value);
	this->unuse();
}

void Shader::setVec1f(GLfloat value, const GLchar* name)
{
	this->use();
	glUniform1f(glGetUniformLocation(this->id, name), value);
	this->unuse();
}

void Shader::setVec2f(glm::fvec2 value, const GLchar* name)
{
	this->use();
	glUniform2fv(glGetUniformLocation(this->id, name), 1, glm::value_ptr(value));
	this->unuse();
}

void Shader::setVec3f(glm::fvec3 value, const GLchar* name)
{
	this->use();
	glUniform3fv(glGetUniformLocation(this->id, name), 1, glm::value_ptr(value));
	this->unuse();
}

void Shader::setVec4f(glm::fvec4 value, const GLchar* name)
{
	this->use();
	glUniform4fv(glGetUniformLocation(this->id, name), 1, glm::value_ptr(value));
	this->unuse();
}

void Shader::setMat4fv(glm::mat4 value, const GLchar* name, bool transpose)
{
	this->use();
	glUniformMatrix4fv(glGetUniformLocation(this->id, name), 1, transpose, glm::value_ptr(value));
	this->unuse();
}

void Shader::setMat3fv(glm::mat3 value, const GLchar* name, bool transpose)
{
	this->use();
	glUniformMatrix3fv(glGetUniformLocation(this->id, name), 1, transpose, glm::value_ptr(value));
	this->unuse();
}

std::string Shader::loadShaderSource(const char* fileName)
{
	std::string temp = "";
	std::string src = "";

	std::ifstream in_file;

	in_file.open(fileName);

	if (in_file.is_open())
	{
		while (std::getline(in_file, temp))
			src += temp + "\n";
	}
	else
	{
		std::cout << "[Shader.cpp] ERROR LOADING SHADER FILE: " << fileName << std::endl;
	}

	std::string versionNr =
		std::to_string(4) +
		std::to_string(4) +
		"0";

	src.replace(src.find("#version"), 12, ("#version " + versionNr));

	return src;
}

GLuint Shader::loadShader(GLenum type, const char* fileName)
{
	GLint success;
	char info_log[512];

	GLuint shader = glCreateShader(type);
	std::string str_src = this->loadShaderSource(fileName);
	const GLchar* src = str_src.c_str();
	glShaderSource(shader, 1, &src, NULL);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, info_log);
		std::cout << "[Shader.cpp] ERROR COMPILING SHADER" << fileName << std::endl;
		std::cout << "[Shader.cpp] " << info_log << std::endl;
	}

	return shader;
}

void Shader::linkProgram(GLuint vertexShader, GLuint geometryShader, GLuint fragmentShader)
{
	GLint success;
	char info_log[512];

	this->id = glCreateProgram();

	glAttachShader(this->id, vertexShader);

	if (geometryShader)
		glAttachShader(this->id, geometryShader);

	glAttachShader(this->id, fragmentShader);

	glLinkProgram(this->id);

	glGetProgramiv(this->id, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(this->id, 512, NULL, info_log);
		std::cout << "[Shader.cpp] COULD NOT LINK PROGRAM" << std::endl;
		std::cout << "[Shader.cpp] " << info_log << std::endl;
	}
	glUseProgram(0);
}



