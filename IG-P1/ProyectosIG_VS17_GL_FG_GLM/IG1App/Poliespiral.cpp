#include "Poliespiral.h"



Poliespiral::Poliespiral(glm::dvec2 verIni, GLdouble angIni, GLdouble
	incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert)
{
	mesh = Mesh::generaPoliespiral(verIni, angIni, incrAng, ladoIni, incrLado, numVert);
}


Poliespiral::~Poliespiral()
{
	delete mesh; mesh = nullptr;
}

void Poliespiral::render(Camera const & cam)
{
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat());
		glColor3d(0.0, 0.0, 1.0);
		glLineWidth(2);
		mesh->render();
	}
}

