#include "DirLight.h"
#include <gtc/type_ptr.hpp>


DirLight::~DirLight () {
}

void DirLight::upload (glm::dmat4 const & modelViewMat) {
	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(glm::value_ptr(modelViewMat));
	glLightfv(id, GL_POSITION, glm::value_ptr(direction));
	uploadLI();
}
