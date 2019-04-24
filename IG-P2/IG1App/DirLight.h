#pragma once
#include "Light.h"

class DirLight :
	public Light {
protected:
	glm::fvec4 direction = { 0, 0, 1, 0 }; // w=0 -> vector

public:
	DirLight(): Light() { }; 
	DirLight (glm::fvec4 dir, glm::fvec4 amb, glm::fvec4 dif, glm::fvec4 spe) : Light (amb, dif, spe), direction (dir) {};
	virtual ~DirLight ();

	virtual void upload (glm::dmat4 const& modelViewMat);
	void setDir(glm::fvec3 dir){ direction = glm::fvec4(dir, 0.0); };
};

