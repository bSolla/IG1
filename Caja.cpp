#include "Caja.h"

#include <gtc/matrix_transform.hpp>


Caja::Caja(GLdouble l)
{
	mesh = Mesh::generaContCubo(l);
	meshFondo = Mesh::generaRectanguloRGB(l, l);
	lado = l;
}


Caja::~Caja()
{
}

void Caja::render(Camera const & cam)
{
	if (mesh != nullptr) {

		glm::dmat4 auxMat = modelMat;

		uploadMvM(cam.getViewMat());
		glColor3d(0.0, 0.0, 1.0);
		glPolygonMode(GL_BACK, GL_LINE);
		glPolygonMode(GL_FRONT, GL_LINE);

		mesh->render();

		modelMat = modelMatFondo * auxMat;
		modelMat = glm::translate(modelMat, glm::dvec3(0.0, -(lado / 2), 0.0));
		modelMat = glm::rotate(modelMat, glm::radians(90.0), glm::dvec3(1.0, 0.0, 0.0));

		uploadMvM(cam.getViewMat());
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		meshFondo->render();

		modelMat = auxMat;

	}
}
