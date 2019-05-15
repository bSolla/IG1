#pragma once
#include "Esfera.h"
#include "SpotLight.h"

class EsferaLuz :
	public Esfera
{
public:
	EsferaLuz(GLdouble r);
	virtual ~EsferaLuz();

	virtual void render(Camera const& cam);

	void enableLight(bool enable) { if (enable) spotLight->enable(); else spotLight->disable(); };
	
private:
	SpotLight * spotLight;
};

