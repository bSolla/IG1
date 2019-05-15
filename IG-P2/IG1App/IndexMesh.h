#pragma once
#include "Mesh.h"
class IndexMesh :
	public Mesh
{
public:
	IndexMesh() { primitive = GL_TRIANGLES; }
	~IndexMesh() { delete[] indices; }
	virtual void render();
	static IndexMesh* generateGridTex(GLdouble lado, GLuint numDiv);
	static IndexMesh* generatePlanoCurvado(GLdouble lado, GLuint numDiv, GLdouble curvatura);

protected:
	GLuint* indices = nullptr;
	GLuint numIndices = 0;
};

