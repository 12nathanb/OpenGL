#include "Audio.h"

Audio::Audio()
{
	engine = createIrrKlangDevice();
}

Audio::~Audio()
{
	engine->drop();
}

void Audio::loadFile(std::string file, bool loop)
{
	std::string f = ".\\src\\Resources\\Audio\\" + file;
	std::cout << "LOADING AUDIO FILE: " << f << std::endl;
	engine->play2D(f.c_str(), loop);
}
