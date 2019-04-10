#include "RectanguloRGB.h"

#include <gtc/matrix_transform.hpp>


RectanguloRGB::RectanguloRGB(GLdouble w, GLdouble h)
{
	//mesh = Mesh::generaRectanguloRGB(w, h);
	mesh = Mesh::generaRectanguloTexCor(w, h, 6, 6);
	texture.load("..\\Bmps\\baldosaC.bmp");
}


RectanguloRGB::~RectanguloRGB()
{
	delete mesh; mesh = nullptr;
}

void RectanguloRGB::render(Camera const & cam)
{
	if (mesh != nullptr) {
		texture.bind(GL_REPLACE);
		uploadMvM(cam.getViewMat());
		glLineWidth(2);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		mesh->render();
		texture.unbind();
	}
}
