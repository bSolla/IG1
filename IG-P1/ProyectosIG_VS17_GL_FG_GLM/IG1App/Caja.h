#pragma once
#include "Entity.h"
class Caja :
	public Entity
{
public:
	Caja(GLdouble l);
	virtual ~Caja();
	virtual void render(Camera const& cam);
};

