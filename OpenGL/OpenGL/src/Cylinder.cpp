#include "Cylinder.h"

Cylinder::Cylinder(std::string name, std::string filename)
{
	this->setObjName(name);
	std::vector<Vertex> mesh = load.loadModel("\\primitives\\Cylinder.obj");
	Init(mesh.data(), mesh.size(), NULL, 0);
	this->SetTexture(filename);
}
