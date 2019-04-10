#pragma once
#include "Entity.h"
class Dragon :
	public Entity
{
public:
	Dragon(int numVertices);
	~Dragon();

	virtual void render(Camera const& cam);
};

