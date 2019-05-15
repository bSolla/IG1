#pragma once
#include "PosLight.h"
class SpotLight :
	public PosLight
{
public:
	SpotLight() {};
	virtual ~SpotLight();

	virtual void upload(glm::dmat4 const& modelViewMat);

	void setDir(glm::fvec4 camDir) { spotDir = camDir; }

private:
	glm::fvec4 spotDir = { 0.0, 0.0, -1.0, 0.0 };
};

