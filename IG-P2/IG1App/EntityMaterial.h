#pragma once
#include "Entity.h"
#include "Material.h"

class EntityMaterial :	public Entity {
public:
	EntityMaterial ();
	virtual ~EntityMaterial ();
	virtual void render(Camera const & cam);

	void setTexture (Texture* tex);
	void setMaterial(MaterialList mat);
protected:
	Texture* texture;
	GLUquadricObj *qObj;
	Material material;
};

