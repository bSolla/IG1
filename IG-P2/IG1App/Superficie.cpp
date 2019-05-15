#include "Superficie.h"



Superficie::Superficie(GLdouble lado, GLuint numDiv, GLdouble curvatura)
{
	mesh = IndexMesh::generatePlanoCurvado(lado, numDiv, curvatura);
}


Superficie::~Superficie()
{
	delete mesh;
}

void Superficie::render(Camera const & cam)
{
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat());
		glColor3d(0.1, 0.0, 0.5);
		mesh->render();
	}
}
