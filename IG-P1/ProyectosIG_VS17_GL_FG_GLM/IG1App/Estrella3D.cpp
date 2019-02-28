#include "Estrella3D.h"



Estrella3D::Estrella3D(GLdouble re, GLdouble np, GLdouble h)
{
	mesh = Mesh::generaEstrella3D(re, np, h);
}


Estrella3D::~Estrella3D()
{
	delete mesh; mesh = nullptr;
}

void Estrella3D::render(Camera const & cam)
{
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat());
		glColor3d(0.0, 0.0, 1.0);
		glLineWidth(2);
		glPolygonMode(GL_BACK, GL_LINE);
		glPolygonMode(GL_FRONT, GL_FILL);

		mesh->render();
	}
}
