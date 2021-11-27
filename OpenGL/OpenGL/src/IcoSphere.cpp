#include "IcoSphere.h"

IcoSphere::IcoSphere(std::string name, std::string filename)
{
	this->setObjName(name);
	std::vector<Vertex> mesh = load.loadModel("\\primitives\\Ico_sphere.obj");
	Init(mesh.data(), mesh.size(), NULL, 0);
	this->SetTexture(filename);
}
