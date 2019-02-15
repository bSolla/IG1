#include "RectanguloRGB.h"

#include <gtc/matrix_transform.hpp>


RectanguloRGB::RectanguloRGB(GLdouble w, GLdouble h)
{
	mesh = Mesh::generaRectanguloRGB(w, h);
}


RectanguloRGB::~RectanguloRGB()
{
	delete mesh; mesh = nullptr;
}

void RectanguloRGB::render(Camera const & cam)
{
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat());
		glLineWidth(2);
		mesh->render();
	}
}
