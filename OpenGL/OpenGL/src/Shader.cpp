#include "Shader.h"

Shader::Shader(std::string vertex_shader_file, std::string fragment_shader_file, GLuint& program) : core_program(program)
{
	VERTEX_SHADER_FILE = ".\\src\\Resources\\Shaders\\" + vertex_shader_file;
	FRAGMENT_SHADER_FILE = ".\\src\\Resources\\Shaders\\" + fragment_shader_file;
}

Shader::~Shader()
{
    glDeleteProgram(core_program);
}

GLuint Shader::loadShaders(std::string& shader_file, std::string shader_type)
{
    char info_log[512];
    GLint success;

    std::string src;


    std::string line;
    std::ifstream in(shader_file);


    GLuint Shader;


    if (in.is_open())
    {
        while (getline(in, line))
            src += line + "\n";
    }
    else
    {
        std::cout << "ERROR LOADING SHADERS FILE" << std::endl;
    }

    in.close();

    if (shader_type == "VERTEX")
    {
        Shader = glCreateShader(GL_VERTEX_SHADER);
    }
    else if (shader_type == "FRAGMENT")
    {
        Shader = glCreateShader(GL_FRAGMENT_SHADER);
    }
    else
    {
        return 0;
    }


    const GLchar* vert_src = src.c_str();
    glShaderSource(Shader, 1, &vert_src, NULL);
    glCompileShader(Shader);

    glGetShaderiv(Shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(Shader, 512, NULL, info_log);

        if (shader_type == "VERTEX")
        {
            std::cout << "ERROR COMPILING VERTEX SHADERS" << std::endl;
        }
        else if (shader_type == "FRAGMENT")
        {
            std::cout << "ERROR COMPILING FRAGMENT SHADERS" << std::endl;
        }

        std::cout << info_log << std::endl;
    }


    return Shader;
}

bool Shader::createShaders()
{
    GLint success;
    bool load_success = true;
    char info_log[512];
    GLuint vert_shader = Shader::loadShaders(VERTEX_SHADER_FILE, "VERTEX");
    GLuint frag_shader = Shader::loadShaders(FRAGMENT_SHADER_FILE, "FRAGMENT");


    core_program = glCreateProgram();

    glAttachShader(core_program, vert_shader);
    glAttachShader(core_program, frag_shader);

    glLinkProgram(core_program);

    glGetProgramiv(core_program, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(core_program, 512, NULL, info_log);
        std::cout << "COULD NOT LINK PROGRAM" << std::endl;
        load_success = false;
        std::cout << info_log << std::endl;
    }

    glUseProgram(0);
    glDeleteShader(vert_shader);
    glDeleteShader(frag_shader);

    return load_success;
}
