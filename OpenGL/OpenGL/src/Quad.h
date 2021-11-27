#pragma once
#include "Shape.h"
#include "LoadObjModel.h"
#include <vector>

class Quad : public Shape
{
public:
	Quad(std::string name, std::string filename);
private:
	LoadObjModel load;
};

