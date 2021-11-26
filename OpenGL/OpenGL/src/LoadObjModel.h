#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "Vertex.h"
#include "libs.h"
class LoadObjModel
{
public:
	static std::vector<Vertex> loadModel(const char* filename);

};

