#include "SpotLight.h"
#include <gtc/type_ptr.hpp>


SpotLight::~SpotLight()
{
}

void SpotLight::upload(glm::dmat4 const & modelViewMat)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(value_ptr(modelViewMat));
	glLightf(id, GL_SPOT_CUTOFF, 30.0);
	glLightf(id, GL_SPOT_EXPONENT, 4.0);
	glLightfv(id, GL_SPOT_DIRECTION, value_ptr(spotDir));

	glLightf(id, GL_CONSTANT_ATTENUATION, 0.5);
	glLightf(id, GL_LINEAR_ATTENUATION, 0);
	glLightf(id, GL_QUADRATIC_ATTENUATION, 0);

	uploadLI();
}
