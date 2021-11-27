#include "gameObject.h"

gameObject::gameObject(std::string name, std::string object_filename, std::string texture_filename)
{
	this->setObjName(name);
	std::string dir = object_filename + ".obj";
	std::vector<Vertex> mesh = load.loadModel(dir.c_str());
	Init(mesh.data(), mesh.size(), NULL, 0);
	this->SetTexture(texture_filename);
}
