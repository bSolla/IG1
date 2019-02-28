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
		mesh->render();
	}
}

void TrianguloAnimado::update()
{
	modelMat = rotate(modelMat, glm::radians(25.0), glm::dvec3(0.0, 0.0, 1.0));
}
