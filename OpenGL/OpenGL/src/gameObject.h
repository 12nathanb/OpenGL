#pragma once
#include "Shape.h"
#include "LoadObjModel.h"
#include <vector>

class gameObject : public Shape
{
public:
	gameObject(std::string name, std::string object_filename, std::string texture_filename);
	LoadObjModel load;
};

