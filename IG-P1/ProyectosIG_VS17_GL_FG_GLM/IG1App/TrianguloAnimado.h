#pragma once
#include "Entity.h"

class TrianguloAnimado : public Entity {
public:
	TrianguloAnimado(GLdouble r);
	virtual ~TrianguloAnimado();
	virtual void render(Camera const& cam);
	virtual void update();
};

