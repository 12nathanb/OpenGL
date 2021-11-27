#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include<glm.hpp>
#include <GL/glew.h>

#include "Vertex.h"

class LoadObjModel
{
public:
	static std::vector<Vertex> loadModel(const char* filename);

};

