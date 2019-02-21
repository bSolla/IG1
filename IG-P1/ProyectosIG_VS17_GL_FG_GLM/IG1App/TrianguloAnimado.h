#pragma once
#include "Entity.h"
class TrianguloAnimado :
	public Entity
{
private:
	double ang = 90.0;
	double incrAng = 1.0;
	double radio = 100.0;
	double x, y;

public:
	TrianguloAnimado(GLdouble r);
	virtual ~TrianguloAnimado();
	virtual void render(Camera const& cam);
	virtual void update();
};

