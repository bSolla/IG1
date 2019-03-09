#pragma once
#include "Entity.h"
class Estrella3D :
	public Entity
{
private:
	Mesh* mirrorMesh = nullptr;   // surface mesh
	glm::dmat4 modelMatMirror = glm::dmat4(1);    // modeling matrix
public:
	Estrella3D(GLdouble re, GLdouble np, GLdouble h);
	virtual ~Estrella3D();
	virtual void render(Camera const& cam);
};

