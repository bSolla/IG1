#include "Esfera.h"



Esfera::Esfera (GLdouble r) {
	radio = r;
}


Esfera::~Esfera () {
}

void Esfera::render (Camera const & cam) {
	if (qObj != nullptr) {
		material.upload();
		texture->bind(GL_MODULATE, true);

		uploadMvM(cam.getViewMat());

		gluQuadricDrawStyle (qObj, GLU_FILL);
		gluQuadricNormals (qObj, GLU_SMOOTH);
		gluQuadricOrientation (qObj, GLU_OUTSIDE);
		gluQuadricTexture (qObj, GL_TRUE);
		gluSphere (qObj, radio, meridianos, paralelos);

		texture->unbind();
	}
}
