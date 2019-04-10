#include "Mesh.h"

using namespace glm;

//-------------------------------------------------------------------------

Mesh ::~Mesh(void) 
{
  delete[] vertices;  vertices = nullptr;
  delete[] colors;    colors = nullptr;
}
//-------------------------------------------------------------------------

void Mesh::render()
{
  if (vertices != nullptr) {
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_DOUBLE, 0, vertices);  // number of coordinates per vertex, type of each coordinate, stride, pointer 
    if (colors != nullptr) {
      glEnableClientState(GL_COLOR_ARRAY);
      glColorPointer(4, GL_DOUBLE, 0, colors);   // number of coordinates per color, type of each coordinate, stride, pointer 
    }

	if (texCoords != nullptr) {
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_DOUBLE, 0, texCoords);
	}

    glDrawArrays(primitive, 0, numVertices);   // primitive graphic, first index and number of elements to be rendered

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
  }
}
//-------------------------------------------------------------------------

Mesh * Mesh::createRGBAxes(GLdouble l)
{
  Mesh* m = new Mesh();
  m->primitive = GL_LINES;
  m->numVertices = 6;

  m->vertices = new dvec3[m->numVertices];
  // X axis vertices
  m->vertices[0] = dvec3(0.0, 0.0, 0.0);   
  m->vertices[1] = dvec3(l, 0.0, 0);
  // Y axis vertices
  m->vertices[2] = dvec3(0, 0.0, 0.0);
  m->vertices[3] = dvec3(0.0, l, 0.0); 
  // Z axis vertices
  m->vertices[4] = dvec3(0.0, 0.0, 0.0);
  m->vertices[5] = dvec3(0.0, 0.0, l);

  m->colors = new dvec4[m->numVertices];
  // X axis color: red  ( Alpha = 1 : fully opaque)
  m->colors[0] = dvec4(1.0, 0.0, 0.0, 1.0);
  m->colors[1] = dvec4(1.0, 0.0, 0.0, 1.0);
  // Y axis color: green
  m->colors[2] = dvec4(0.0, 1.0, 0.0, 1.0);
  m->colors[3] = dvec4(0.0, 1.0, 0.0, 1.0);
  // Z axis color: blue
  m->colors[4] = dvec4(0.0, 0.0, 1.0, 1.0);
  m->colors[5] = dvec4(0.0, 0.0, 1.0, 1.0);
 
  return m; 
}

Mesh * Mesh::generaPoliespiral(dvec2 verIni, GLdouble angIni, GLdouble incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert)
{
	Mesh* m = new Mesh();
	m->primitive = GL_LINE_STRIP;
	m->numVertices = numVert;

	m->vertices = new dvec3[m->numVertices];
	m->vertices[0] = dvec3(verIni.x, verIni.y, 0.0);

	double x, y, l, ang;
	l = ladoIni;
	ang = angIni;
	x = verIni.x;
	y = verIni.y;

	for (int i = 1; i < m->numVertices; i++) {
		x += (l*cos(radians(ang)));
		y += (l*sin(radians(ang)));

		m->vertices[i] = dvec3(x, y, 0.0);

		l += incrLado;
		ang += incrAng;
	}

	return m;
}


Mesh * Mesh::generaDragon(GLuint numVert)
{
	srand(time(NULL));
	Mesh* m = new Mesh();
	m->primitive = GL_POINTS;
	m->numVertices = numVert;

	m->vertices = new dvec3[m->numVertices];
	m->vertices[0] = dvec3(0.0, 0.0, 0.0);

	double x = 0.0;
	double y = 0.0;
	double xformula = 0.0;
	double yformula = 0.0;

	for (int i = 1; i < m->numVertices; i++) {
		

		double azar = rand() / double(RAND_MAX);

		xformula = x;
		yformula = y;

		
		if (azar < PR1) {
			x = 0.824074 * xformula + 0.281482 * yformula - 0.882290;
			y = -0.212346 * xformula + 0.864198 * yformula - 0.110607;
		} // T1
		else {
			x = 0.088272 * xformula + 0.520988 * yformula + 0.785360;
			y = -0.463889 * xformula - 0.377778 * yformula + 8.095795;
		} // T2

		m->vertices[i] = dvec3(x, y, 0.0);
	}

	return m;
}


Mesh * Mesh::generaTriangulo(GLdouble r)
{
	Mesh* m = new Mesh();
	m->primitive = GL_TRIANGLES;
	m->numVertices = 3;

	m->vertices = new dvec3[m->numVertices];
	m->vertices[0] = dvec3(0.0, r, 0.0);

	double ang = 90;
	double incrAng = (360 / 3);
	double x = 0.0;
	double y = 0.0;

	for (int i = 1; i < m->numVertices; i++) {
		ang += incrAng;

		x = r * cos(radians(ang));
		y = r * sin(radians(ang));

		m->vertices[i] = dvec3(x, y, 0.0);
	}

	return m;
}


Mesh * Mesh::generaTrianguloRGB(GLdouble r)
{
	Mesh * m = generaTriangulo(r);

	m->colors = new dvec4[m->numVertices];

	m->colors[0] = dvec4(1.0, 0.0, 0.0, 1.0);
	m->colors[1] = dvec4(0.0, 1.0, 0.0, 1.0);
	m->colors[2] = dvec4(0.0, 0.0, 1.0, 1.0);

	// crear el array de colores
	return m;
}


Mesh * Mesh::generaRectangulo(GLdouble w, GLdouble h)
{
	Mesh* m = new Mesh();
	m->primitive = GL_TRIANGLE_STRIP;
	m->numVertices = 4;

	m->vertices = new dvec3[m->numVertices];
	m->vertices[0] = dvec3(-w/2, h/2, 0.0);
	m->vertices[1] = dvec3(w/2, h/2, 0.0);
	m->vertices[2] = dvec3(-w/2, -h/2, 0.0); 
	m->vertices[3] = dvec3(w/2, -h/2, 0.0);
	//m->vertices[4] = dvec3(0.0, h, 0.0);
	//m->vertices[5] = dvec3(w, h, 0.0);

	return m;
}


Mesh * Mesh::generaRectanguloRGB(GLdouble w, GLdouble h)
{
	Mesh *m = generaRectangulo(w, h);

	m->colors = new dvec4[m->numVertices];

	m->colors[0] = dvec4(1.0, 0.0, 0.0, 1.0);
	m->colors[1] = dvec4(0.0, 1.0, 0.0, 1.0);
	m->colors[2] = dvec4(0.0, 1.0, 0.0, 1.0);
	m->colors[3] = dvec4(0.0, 0.0, 1.0, 1.0);
	//m->colors[4] = dvec4(0.0, 1.0, 0.0, 1.0);
	//m->colors[5] = dvec4(0.0, 0.0, 1.0, 1.0);

	return m;
}


Mesh * Mesh::generaEstrella3D(GLdouble re, GLdouble np, GLdouble h)
{
	Mesh* m = new Mesh();
	m->primitive = GL_TRIANGLE_FAN;
	m->numVertices = 2 * np + 2;
	m->vertices = new dvec3[m->numVertices];

	int numTriangulos = 2 * np;

	double ang = 360.0;
	double incrAng = -(ang / numTriangulos);

	m->vertices[0] = dvec3(0.0, 0.0, 0.0);

	for (int i = 1; i < m->numVertices; i++) {
		if (i % 2 == 0) {
			m->vertices[i] = dvec3(re*cos(radians(ang)), re* sin(radians(ang)), h);
		}
		else {
			m->vertices[i] = dvec3((re / 2)*cos(radians(ang)), (re / 2)* sin(radians(ang)), h);
		}
		ang += incrAng;
	}

	return m;
}


Mesh * Mesh::generaContCubo(GLdouble l)
{
	Mesh* m = new Mesh();
	m->numVertices = 10;
	m->primitive = GL_TRIANGLE_STRIP;

	m->vertices = new dvec3[m->numVertices];

	
	m->vertices[0] = dvec3(-l/2, l/2, l/2);
	m->vertices[1] = dvec3(-l/2, -l/2, l/2);
	m->vertices[2] = dvec3(l/2, l/2, l/2);
	m->vertices[3] = dvec3(l/2, -l/2, l/2);
	m->vertices[4] = dvec3(l/2, l/2, -l/2);
	m->vertices[5] = dvec3(l/2, -l/2, -l/2);
	m->vertices[6] = dvec3(-l/2, l/2, -l/2);
	m->vertices[7] = dvec3(-l/2, -l/2, -l/2);
	m->vertices[8] = dvec3(-l/2, l/2, l/2);
	m->vertices[9] = dvec3(-l/2, -l/2, l/2);

	return m;
}


Mesh * Mesh::generaRectanguloTexCor(GLdouble w, GLdouble h, GLuint rw, GLuint rh)
{
	Mesh* m = generaRectangulo(w, h);
	m->texCoords = new dvec2[m->numVertices];
	m->texCoords[0] = dvec2(0, rh);
	m->texCoords[1] = dvec2(0, 0);
	m->texCoords[2] = dvec2(rw, rh);
	m->texCoords[3] = dvec2(rw, 0);
	return m;
}


Mesh * Mesh::generaEstrellaTexCor(GLdouble r, GLdouble nL, GLdouble h)
{
	// creates the base mesh
	Mesh* m = generaEstrella3D(r, nL, h);

	// assigns coordinates to the texture array
	int numTriangulos = 2 * nL;
	double ang = 360.0;
	double incrAng = -(ang / numTriangulos);
	double x, y;

	m->texCoords = new dvec2[m->numVertices];

	m->texCoords[0] = dvec2 (0.5, 0.5);
	for (int i = 1; i < m->numVertices; i++) {
		// 0.5 is both the radius of the "circumference" used to get the text. coord., and the offset to the
		// upper left corner (the zero in the texture coords)
		x = 0.5 + (0.5 * cos (radians (ang))); 
		y = 0.5 + (0.5 * sin (radians (ang)));
		m->texCoords[i] = dvec2(x, y);
		
		ang += incrAng;
	}

	return m;
}

Mesh * Mesh::generaCajaTexCor(GLdouble l)
{
	Mesh* m = generaContCubo(l);

	m->texCoords = new dvec2[m->numVertices];
	m->texCoords[0] = dvec2(0.0, 1.0);
	m->texCoords[1] = dvec2(0.0, 0.0);
	m->texCoords[2] = dvec2(1.0, 1.0);
	m->texCoords[3] = dvec2(1.0, 0.0);
	m->texCoords[4] = dvec2(0.0, 1.0);
	m->texCoords[5] = dvec2(0.0, 0.0);
	m->texCoords[6] = dvec2(1.0, 1.0);
	m->texCoords[7] = dvec2(1.0, 0.0);
	m->texCoords[8] = dvec2(0.0, 1.0);
	m->texCoords[9] = dvec2(0.0, 0.0);


	return m;
}
//-------------------------------------------------------------------------
