#pragma once
#include "Entity.h"
class TrianguloRGB :
	public Entity
{
public:
	TrianguloRGB(GLdouble r);
	virtual ~TrianguloRGB();

	virtual void render(Camera const& cam);
};

