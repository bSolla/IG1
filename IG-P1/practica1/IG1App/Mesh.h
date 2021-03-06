//#pragma once
#ifndef _H_Mesh_H_
#define _H_Mesh_H_

#include <GL/freeglut.h>
#include <glm.hpp>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

const double PR1 = 0.787473;
const double PR2 = 0.212527;
//-------------------------------------------------------------------------

class Mesh 
{
public:
	static Mesh* createRGBAxes(GLdouble l); // creates a new 3D RGB axes mesh
	static Mesh* generaPoliespiral(glm::dvec2 verIni, GLdouble angIni, GLdouble
		incrAng, GLdouble ladoIni, GLdouble incrLado, GLuint numVert);
	static Mesh* generaDragon(GLuint numVert);
	static Mesh* generaTriangulo(GLdouble r);
	static Mesh * generaTrianguloRGB(GLdouble r);
	static Mesh* generaRectangulo(GLdouble w, GLdouble h);
	static Mesh* generaRectanguloRGB(GLdouble w, GLdouble h);
	// 3d -------------------------
	static Mesh* generaEstrella3D(GLdouble re, GLdouble np, GLdouble h);
	static Mesh* generaContCubo(GLdouble l);
	// Textures -------------------
	static Mesh* generaRectanguloTexCor(GLdouble w, GLdouble h, GLuint rw, GLuint rh);
	static Mesh* generaEstrellaTexCor(GLdouble r, GLdouble nL, GLdouble h);
	static Mesh* generaCajaTexCor(GLdouble l);


	Mesh(void) { };
	~Mesh(void);
	virtual void render();

	glm::dvec3* getVertices() { return vertices; };  // vertex array
	glm::dvec4* getColors() { return colors; };      // color array
   
protected:

	GLuint numVertices = 0;   // arrays size (number of elements)
	GLuint primitive = GL_TRIANGLES;  // graphic primitive: GL_POINTS, GL_LINES, GL_TRIANGLES, ...

	glm::dvec3* vertices = nullptr;  // vertex array
	glm::dvec4* colors = nullptr;    // color array
	glm::dvec2* texCoords = nullptr;          // texture coords array
};

//-------------------------------------------------------------------------

#endif //_H_Scene_H_