#include "EsferaLuz.h"



EsferaLuz::EsferaLuz(GLdouble r)
{
	spotLight = new SpotLight();
	radio = r;
	spotLight->setPos(glm::fvec3(0.0, 0.0, 0.0));
	spotLight->setDir(glm::fvec4(0.0, -1.0, 0.0, 0.0));
	spotLight->enable();
}

EsferaLuz::~EsferaLuz()
{
}

void EsferaLuz::render(Camera const & cam)
{
	if (qObj != nullptr) {
		material.upload();
		texture->bind(GL_MODULATE, true);

		uploadMvM(cam.getViewMat());

		gluQuadricDrawStyle(qObj, GLU_FILL);
		gluQuadricNormals(qObj, GLU_SMOOTH);
		gluQuadricOrientation(qObj, GLU_OUTSIDE);
		gluQuadricTexture(qObj, GL_TRUE);
		gluSphere(qObj, radio, meridianos, paralelos);

		texture->unbind();
	}
}
