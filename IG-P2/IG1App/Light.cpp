#include "Light.h"
#include <gtc/type_ptr.hpp>

GLuint Light::cont = 0;

Light::Light () {
	if (cont < GL_MAX_LIGHTS) {
		id = GL_LIGHT0 + cont;
		++cont;
	}
}

Light::Light (glm::fvec4 amb, glm::fvec4 dif, glm::fvec4 spe) : ambient(amb), diffuse(dif), specular(spe) {
	if (cont < GL_MAX_LIGHTS) {
		id = GL_LIGHT0 + cont;
		++cont;
	}
}


Light::~Light () {
	disable();
}

void Light::uploadLI () {
	glLightfv(id, GL_AMBIENT, glm::value_ptr(ambient));
	glLightfv(id, GL_DIFFUSE, glm::value_ptr(diffuse));
	glLightfv(id, GL_SPECULAR, glm::value_ptr(specular));
}

void Light::disable () {
	if (id < GL_LIGHT0 + GL_MAX_LIGHTS) {
		glDisable(id); 
	}
}

void Light::enable () {
	if (id < GL_LIGHT0 + GL_MAX_LIGHTS) { 
		glEnable(id); 
	}
}
