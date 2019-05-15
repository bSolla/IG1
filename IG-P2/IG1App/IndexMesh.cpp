#include "IndexMesh.h"

// TODO: fix

void IndexMesh::render()
{
	if (indices != nullptr) {
		glEnableClientState(GL_INDEX_ARRAY);
		glIndexPointer(GL_UNSIGNED_INT, 0, indices);

		if (texCoords != nullptr) {
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glTexCoordPointer(2, GL_DOUBLE, 0, texCoords);
		}

		if (normals != nullptr) {
			glEnableClientState(GL_NORMAL_ARRAY);
			glNormalPointer(GL_DOUBLE, 0, normals);
		}

		glDrawElements(primitive, numIndices, GL_UNSIGNED_INT, indices);

		glDisableClientState(GL_INDEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
	}
}

IndexMesh * IndexMesh::generateGridTex(GLdouble lado, GLuint numDiv)
{

	IndexMesh* m = new IndexMesh();
	GLdouble incr = lado / numDiv;
	GLuint numFC = numDiv + 1;

	m->numVertices = numFC * numFC; // número de vértices
	m->vertices = new glm::dvec3[m->numVertices];
	//… // ->
	GLdouble x = -lado / 2;
	GLdouble z = -lado / 2;
	for (int f = 0; f < numFC; f++) {
		for (int c = 0; c < numFC; c++) {
			m->vertices[f* numFC + c] = glm::dvec3(x + c * incr, 0, z + f * incr);
		}
	}

	// generar índices
	m->numIndices = numDiv * numDiv * 6; // número de índices
	m->indices = new GLuint[m->numIndices];

	GLint i = 0;
	for (int h = 0; h < numDiv; h++) {
		for (int k = 0; k < numDiv; k++) {
			GLint iv = h * numFC + k;
			m->indices[i++] = iv;
			m->indices[i++] = iv + numFC;
			m->indices[i++] = iv + 1;
			m->indices[i++] = iv + 1;
			m->indices[i++] = iv + numFC;
			m->indices[i++] = iv + numFC + 1;
		}
	}
	//… // ->

	m->texCoords = new glm::dvec2[m->numVertices];
	GLint s = 0;
	GLint t = 1;

	for (int f = 0; f < numFC; f++) {
		for (int c = 0; c < numFC; c++) {
			m->texCoords[f*numFC + c] = glm::dvec2(f/numDiv, c/numDiv);
		}
	}
	//… // ->


	return m;
}

IndexMesh * IndexMesh::generatePlanoCurvado(GLdouble lado, GLuint numDiv, GLdouble curvatura)
{
	IndexMesh* m = generateGridTex(lado, numDiv);
	m->normals = new glm::dvec3[m->numVertices];

	int ahduhd = m->numVertices;
	for (int i = 0; i < m->numVertices; i++) {
		GLdouble x = m->vertices[i].x;
		GLdouble z = m->vertices[i].z;
		GLdouble y = lado * curvatura / 2 - curvatura / lado * (x*x) - curvatura / lado * (z*z);
		m->vertices[i] = glm::dvec3(x, y, z);
		m->normals[i] = glm::dvec3(2 * curvatura / lado * x, 1, 2 * curvatura / lado * z);
	}

	return m;
}
