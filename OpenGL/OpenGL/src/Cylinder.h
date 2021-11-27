#pragma once
#include "Shape.h"
#include "LoadObjModel.h"
#include <vector>

class Cylinder : public Shape
{
public:
	Cylinder(std::string name, std::string filename);
private:
	LoadObjModel load;

};

