#include "Caja.h"



Caja::Caja(GLdouble l)
{
	mesh = Mesh::generaContCubo(l);
}


Caja::~Caja()
{
}

void Caja::render(Camera const & cam)
{
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat());
		glColor3d(0.0, 0.0, 1.0);
		glPolygonMode(GL_BACK, GL_LINE);
		glPolygonMode(GL_FRONT, GL_FILL);

		mesh->render();
	}
}
