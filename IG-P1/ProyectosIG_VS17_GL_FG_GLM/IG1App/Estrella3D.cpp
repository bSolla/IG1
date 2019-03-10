#include "Estrella3D.h"

#include <gtc/matrix_transform.hpp>




Estrella3D::Estrella3D(GLdouble re, GLdouble np, GLdouble h)
{
	//mesh = Mesh::generaEstrella3D(re, np, h);
	//mirrorMesh = Mesh::generaEstrella3D(re, np, h);
	mesh = Mesh::generaEstrellaTexCor(re, np, h);
	mirrorMesh = Mesh::generaEstrellaTexCor(re, np, h);
	texture.load("..\\Bmps\\baldosaP.bmp");
}


Estrella3D::~Estrella3D()
{
	delete mesh; mesh = nullptr;
}

void Estrella3D::render(Camera const & cam)
{
	if (mesh != nullptr) {
		texture.bind(GL_REPLACE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

		glm::dmat4 auxMat = modelMat;

		uploadMvM(cam.getViewMat());
		//glColor3d(0.0, 0.0, 1.0);
		//glLineWidth(2);
		//glPolygonMode(GL_BACK, GL_LINE);
		//glPolygonMode(GL_FRONT, GL_LINE);
		
		mesh->render();

		modelMat = auxMat * modelMatMirror;
		modelMat = glm::rotate(modelMat, glm::radians(180.0), glm::dvec3(1.0, 0.0, 0.0));
		uploadMvM(cam.getViewMat());

		mirrorMesh->render();

		modelMat = auxMat;

		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		texture.unbind();

		glm::dmat4 mat = glm::dmat4(1);
		mat = rotate(mat, glm::radians(angleIncrement/2), glm::dvec3(0.0, 0.0, 1.0));
		mat = rotate(mat, glm::radians(angleIncrement), glm::dvec3(0.0, 1.0, 0.0));
		modelMat = modelMat * mat;
	}
}

// TODO: ----------- create update in main and in Entity, and perform the rotations there ----------

void Estrella3D::update()
{

}