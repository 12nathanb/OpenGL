#pragma once
#include "Shape.h"
#include "LoadObjModel.h"
#include <vector>

class Cube : public Shape
{
public:
	Cube(std::string name, std::string filename);
private:
	LoadObjModel load;

};

