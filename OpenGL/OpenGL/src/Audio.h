#pragma once
#include <iostream>
#include <irrKlang.h>

using namespace irrklang;
class Audio
{
public:
	Audio();
	~Audio();
	void loadFile(std::string file, bool loop);
	

private:
	ISoundEngine* Sound_engine;
};

