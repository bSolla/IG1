#pragma once
#include "Entity.h"
class Cristalera :
	public Entity
{
public:
	Cristalera(GLdouble l);
	~Cristalera();
	virtual void render(Camera const& cam);
};

