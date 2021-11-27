#pragma once
#include "Shape.h"
#include "LoadObjModel.h"
#include <vector>

class Sphere : public Shape
{
public:
	Sphere(std::string name, std::string filename);
private:
	LoadObjModel load;

};

