#include "PosLight.h"
#include <gtc/type_ptr.hpp>



PosLight::~PosLight () {
}

void PosLight::upload (glm::dmat4 const & modelViewMat) {
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(value_ptr(modelViewMat));
	glLightfv(id, GL_POSITION, value_ptr(position));
	uploadLI();
}
