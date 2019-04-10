#pragma once
#include "Entity.h"
class RectanguloRGB :
	public Entity
{
public:
	RectanguloRGB(GLdouble w, GLdouble h);
	virtual ~RectanguloRGB();

	virtual void render(Camera const& cam);
};

