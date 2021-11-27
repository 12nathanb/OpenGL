#pragma once
#include "Shape.h"
#include "LoadObjModel.h"
#include <vector>

class Pyramid : public Shape
{
public:
	Pyramid(std::string name, std::string filename);
private:
	LoadObjModel load;
};

