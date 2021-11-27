#include "Quad.h"

Quad::Quad(std::string name, std::string filename)
{
	this->setObjName(name);
	std::vector<Vertex> mesh = load.loadModel("\\primitives\\Plane.obj");
	Init(mesh.data(), mesh.size(), NULL, 0);
	this->SetTexture(filename);
}
