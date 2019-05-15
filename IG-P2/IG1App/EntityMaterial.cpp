#include "EntityMaterial.h"



EntityMaterial::EntityMaterial () {
	qObj = gluNewQuadric ();
}


EntityMaterial::~EntityMaterial () {
	gluDeleteQuadric (qObj);
}

void EntityMaterial::render(Camera const & cam)
{
	material.upload();
}

void EntityMaterial::setTexture (Texture * tex) {
	texture = tex;
}

void EntityMaterial::setMaterial(MaterialList mat)
{
	switch (mat)
	{
	case brass:
		material.setBrass();
		break;
	case gold:
		material.setGold();
		break;
	case pewter:
		material.setPewter();
		break;
	default: // plastic is the default
	case blackPlastic:
		break;
	}
}
