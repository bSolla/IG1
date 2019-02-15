#include "Dragon.h"

#include <gtc/matrix_transform.hpp>



Dragon::Dragon(int numVertices)
{
	mesh = Mesh::generaDragon(numVertices);
}


Dragon::~Dragon()
{
	delete mesh; mesh = nullptr;
}

void Dragon::render(Camera const & cam)
{
	if (mesh != nullptr) {
		uploadMvM(cam.getViewMat());
		glColor3d(0.0, 0.0, 1.0);
		glPointSize(2);
		mesh->render();
	}
}