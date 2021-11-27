#pragma once
#include "Shape.h"
#include "LoadObjModel.h"
#include <vector>

class IcoSphere : public Shape
{
public:
	IcoSphere(std::string name, std::string filename);
private:
	LoadObjModel load;

};

