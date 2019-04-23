#pragma once
#include "EntityMaterial.h"
class Esfera : public EntityMaterial {
public:
	Esfera (GLdouble r);
	virtual ~Esfera ();

	virtual void render (Camera const& cam);

private:
	GLdouble radio = 0;
	GLint meridianos = 16;
	GLint paralelos = 16;
};

