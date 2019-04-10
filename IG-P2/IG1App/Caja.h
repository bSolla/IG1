#pragma once
#include "Entity.h"
#include "RectanguloRGB.h"

class Caja :
	public Entity
{
private:
	Mesh* meshFondo = nullptr;   // surface mesh
	glm::dmat4 modelMatFondo = glm::dmat4(1);    // modeling matrix
	GLdouble lado;

public:
	Caja(GLdouble l);
	virtual ~Caja();
	virtual void render(Camera const& cam);
};

