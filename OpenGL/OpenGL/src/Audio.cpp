#include "Audio.h"

Audio::Audio()
{
	Sound_engine = createIrrKlangDevice();
}

Audio::~Audio()
{
	Sound_engine->drop();
}

void Audio::loadFile(std::string file, bool loop)
{
	std::string f = ".\\src\\Resources\\Audio\\" + file;
	std::cout << "[Audio.cpp] LOADING AUDIO FILE: " << f << std::endl;
	Sound_engine->play2D(f.c_str(), loop);
}
