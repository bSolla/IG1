#include "Caja.h"

#include <gtc/matrix_transform.hpp>


Caja::Caja(GLdouble l)
{
	mesh = Mesh::generaCajaTexCor(l);
	meshFondo = Mesh::generaRectanguloTexCor(l, l, 1.0, 1.0);
	lado = l;
}


Caja::~Caja()
{
	delete mesh; mesh = nullptr;
}

void Caja::render(Camera const & cam)
{
	if (mesh != nullptr) {
		texture.load("..\\Bmps\\container.bmp");

		glm::dmat4 auxMat = modelMat;

		uploadMvM(cam.getViewMat());

		// ---------------------------------------- normal, line only box
		//glColor3d(0.0, 0.0, 1.0);
		//glPolygonMode(GL_BACK, GL_LINE);
		//glPolygonMode(GL_FRONT, GL_LINE);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		// ---------------------------------------- textured box
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		mesh->render();

		glDisable(GL_CULL_FACE);

		texture.unbind();

		texture.load("..\\Bmps\\papelE.bmp");

		glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT);
		mesh->render();

		glDisable(GL_CULL_FACE);


		modelMat = modelMatFondo * auxMat;
		modelMat = glm::translate(modelMat, glm::dvec3(0.0, -(lado / 2), 0.0));
		modelMat = glm::rotate(modelMat, glm::radians(90.0), glm::dvec3(1.0, 0.0, 0.0));

		uploadMvM(cam.getViewMat());
		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		meshFondo->render();

		glDisable(GL_CULL_FACE);
		texture.unbind();

		texture.load("..\\Bmps\\container.bmp");
		glEnable(GL_CULL_FACE);
		glCullFace(GL_FRONT);
		meshFondo->render();

		glDisable(GL_CULL_FACE);
		texture.unbind();


		modelMat = auxMat;

	}
}
