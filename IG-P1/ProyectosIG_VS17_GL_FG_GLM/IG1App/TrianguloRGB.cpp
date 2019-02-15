#include "TrianguloRGB.h"



TrianguloRGB::TrianguloRGB(GLdouble r)
{
	mesh = Mesh::generaTrianguloRGB(r);
}


TrianguloRGB::~TrianguloRGB()
{
	delete mesh; mesh = nullptr;
}

void TrianguloRGB::render(Camera const & cam)
{
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat());
		glLineWidth(2);
		mesh->render();
	}
}
