#pragma once
#include "Entity.h"
#include "IndexMesh.h"
#include "EntityMaterial.h"
class Superficie :
	public EntityMaterial
{
public:
	Superficie(GLdouble lado, GLuint numDiv, GLdouble curvatura);
	virtual ~Superficie();
	virtual void render(Camera const& cam);
	IndexMesh* mesh_ = nullptr;
};

