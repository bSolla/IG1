#pragma once
#include "Light.h"
class PosLight :
	public Light {
protected:
	glm::fvec4 position = { 0, 0, 0, 1 }; // w=1 -> punto
public:
	PosLight(): Light() { }; // Constructora con parámetros !!!
	PosLight(glm::fvec4 pos, glm::fvec4 amb, glm::fvec4 dif, glm::fvec4 spe) : Light (amb, dif, spe), position (pos) {};
	virtual ~PosLight ();

	virtual void upload (glm::dmat4 const& modelViewMat);
	void setPos(glm::fvec3 pos) { position = glm::fvec4(pos, 1.0); };
};

