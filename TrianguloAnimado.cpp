#include "TrianguloAnimado.h"
#include <gtc/matrix_transform.hpp>  



TrianguloAnimado::TrianguloAnimado(GLdouble r) {
	mesh = Mesh::generaTrianguloRGB(r);
}


TrianguloAnimado::~TrianguloAnimado() {
	delete mesh; mesh = nullptr;
}

void TrianguloAnimado::render(Camera const & cam) {
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat());
		glLineWidth(2);

		mesh->render();
	}
}

void TrianguloAnimado::update() {
	double x, y;

	setModelMat (glm::dmat4 (1));

	glm::dmat4 mat = glm::dmat4(1);
	mat = rotate(mat, glm::radians(animationAngle), glm::dvec3(0.0, 0.0, 1.0));
	
	x =  animationRadius * glm::cos(glm::radians(animationAngle));
	y = animationRadius * glm::sin(glm::radians(animationAngle));

	mat = translate(mat, glm::dvec3(x, y, 0.0));
	animationAngle += angleIncrement;

	setModelMat(mat);
}
