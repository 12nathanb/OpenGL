#pragma once
#include "Shape.h"
#include "LoadObjModel.h"
#include <vector>

class Torus : public Shape
{
public:
	Torus(std::string name, std::string filename);
private:
	LoadObjModel load;

};

