#include "Foto.h"



Foto::Foto(GLdouble w, GLdouble h)
{
	mesh = Mesh::generaRectanguloTexCor(w, h, 1, 1);
}


Foto::~Foto()
{
	delete mesh; mesh = nullptr;
}

void Foto::render(Camera const & cam)
{
	if (mesh != nullptr) {

		texture.save("Texture");
		texture.load("..\\Bmps\\Texture.bmp");
		texture.bind();
		uploadMvM(cam.getViewMat());
		mesh->render();
		texture.unbind();
	}
}
