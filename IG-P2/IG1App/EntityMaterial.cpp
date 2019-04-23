#include "EntityMaterial.h"



EntityMaterial::EntityMaterial () {
	qObj = gluNewQuadric ();
}


EntityMaterial::~EntityMaterial () {
	gluDeleteQuadric (qObj);
}

void EntityMaterial::setTexture (Texture * tex) {
	texture = tex;
}
