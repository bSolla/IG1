#include "Material.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

Material::Material () {
	setBlackPlastic (); // default material
}


Material::~Material () {
}

void Material::upload () {
	glShadeModel(sh);
	glMaterialfv(face, GL_AMBIENT, value_ptr(ambient));
	glMaterialfv(face, GL_DIFFUSE, value_ptr(diffuse));
	glMaterialfv(face, GL_SPECULAR, value_ptr(specular));
	glMaterialf(face, GL_SHININESS, expF);

}


void Material::setBlackPlastic () {
	expF = 32.0f;
	ambient = glm::fvec4 (0.0f, 0.0f, 0.0f, expF);
	diffuse = glm::fvec4 (0.01f, 0.01f, 0.01f, expF);
	specular = glm::fvec4 (0.5f, 0.5f, 0.5f, expF);
}

void Material::setBrass () {
	expF = 27.8974f;
	ambient = glm::fvec4 (0.329412f, 0.223529f, 0.027451f, expF);
	diffuse = glm::fvec4 (0.780392f, 0.568627f, 0.113725f, expF);
	specular = glm::fvec4 (0.992157f, 0.941176f, 0.907843f, expF);
}

void Material::setGold () {
	expF = 51.2f;
	ambient = glm::fvec4 (0.24725f, 0.1995f, 0.0745f, expF);
	diffuse = glm::fvec4 (0.75164f, 0.60648f, 0.22648f, expF);
	specular = glm::fvec4 (0.628281f, 0.555802f, 0.366065f, expF);
}

void Material::setPewter () {
	expF = 9.84615f;
	ambient = glm::fvec4 (0.10588f, 0.058824f, 0.113725f, expF);
	diffuse = glm::fvec4 (0.427451f, 0.470588f, 0.541176f, expF);
	specular = glm::fvec4 (0.3333f, 0.3333f, 0.521569f, expF);
}
