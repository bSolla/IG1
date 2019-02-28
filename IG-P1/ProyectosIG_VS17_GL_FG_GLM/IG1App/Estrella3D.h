#pragma once
#include "Entity.h"
class Estrella3D :
	public Entity
{
public:
	Estrella3D(GLdouble re, GLdouble np, GLdouble h);
	virtual ~Estrella3D();
	virtual void render(Camera const& cam);
};

