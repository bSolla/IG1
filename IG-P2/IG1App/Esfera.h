#pragma once
#include "EntityMaterial.h"
class Esfera : public EntityMaterial {
public:
	Esfera() {};
	Esfera (GLdouble r);
	virtual ~Esfera ();

	virtual void render (Camera const& cam);

protected:
	GLdouble radio = 0;
	GLint meridianos = 64;
	GLint paralelos = 64;
};

