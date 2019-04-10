#include "Cristalera.h"



Cristalera::Cristalera(GLdouble l)
{
	mesh = Mesh::generaCajaTexCor(l);
	texture.load("..\\Bmps\\cristalTri.bmp", 100);
}


Cristalera::~Cristalera()
{
	delete mesh; mesh = nullptr;
}

void Cristalera::render(Camera const & cam)
{
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat());
		glDepthMask(GL_FALSE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		texture.bind(GL_REPLACE);
		mesh->render();
		texture.unbind();
		glDisable(GL_BLEND);
		glDepthMask(GL_TRUE);
	}
}
