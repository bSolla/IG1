#include "TrianguloAnimado.h"
#include <gtc/matrix_transform.hpp>  



TrianguloAnimado::TrianguloAnimado(GLdouble r)
{
	mesh = Mesh::generaTrianguloRGB(r);
}


TrianguloAnimado::~TrianguloAnimado()
{
	delete mesh; mesh = nullptr;
}

void TrianguloAnimado::render(Camera const & cam)
{
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat());
		glLineWidth(2);

		x = radio * glm::cos(glm::radians(ang));
		y = radio * glm::sin(glm::radians(ang));

		modelMat = translate(modelMat, glm::dvec3(x, y, 0.0));
		ang += incrAng;

		mesh->render();
	}
}

void TrianguloAnimado::update()
{
	glm::dmat4 triangleMat = getModelMat();
	glm::dmat4 matR;
	matR = rotate(glm::dmat4(1), glm::radians(-25.0), glm::dvec3(0.0, 0.0, 1.0));

	setModelMat(triangleMat * matR);
}
