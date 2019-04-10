#pragma once
#include "Entity.h"

class TrianguloAnimado : public Entity {
private:
	double animationRadius = 200.0;
	double animationAngle = 0.0;
	double angleIncrement = 15.0;

public:
	TrianguloAnimado(GLdouble r);
	virtual ~TrianguloAnimado();
	virtual void render(Camera const& cam);
	virtual void update();
	virtual void update(GLuint elapsedTime);
};

