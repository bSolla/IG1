#pragma once
#include "Entity.h"

class EntityMaterial :	public Entity {
public:
	EntityMaterial ();
	virtual ~EntityMaterial ();

	void setTexture (Texture* tex);

protected:
	Texture* texture;
	GLUquadricObj *qObj;
};

