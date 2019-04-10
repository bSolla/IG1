#pragma once
#include "Entity.h"

class Foto :
	public Entity
{
private:
	GLdouble width;
	GLdouble height;
public:
	Foto(GLdouble w, GLdouble h);
	~Foto();
	virtual void render(Camera const& cam);
};

