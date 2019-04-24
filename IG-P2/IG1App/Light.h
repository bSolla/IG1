#pragma once
#include <GL/freeglut.h>
#include <glm.hpp>

class Light {
protected:
	static GLuint cont; // valor inicial: cont = 0
	// id: identificador interno (GPU) de la luz
	GLuint id = GL_LIGHT0 + GL_MAX_LIGHTS; // GL_LIGHTi
	glm::fvec4 ambient = { 0.1, 0.1, 0.1, 1 } ;
	glm::fvec4 diffuse = { 0.5, 0.5, 0.5, 1 } ;
	glm::fvec4 specular = { 0.5, 0.5, 0.5, 1 };

public: 
	Light ();
	Light (glm::fvec4 amb, glm::fvec4 dif, glm::fvec4 spe);
	virtual ~Light ();

	virtual void uploadLI();
	virtual void upload(glm::dmat4 const& modelViewMat) = 0;
	void disable ();
	void enable ();
	void setAmb(glm::fvec4 amb) { ambient = amb ; };
};

