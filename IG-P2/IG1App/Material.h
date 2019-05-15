#pragma once
#include <GL/freeglut.h>
#include <glm.hpp>

enum MaterialList {
	blackPlastic,
	brass,
	gold,
	pewter
};

class Material {
public:
	Material ();
	~Material ();

	virtual void upload ();

	void setBlackPlastic ();
	void setBrass ();
	void setGold ();
	void setPewter ();

private:
	glm::fvec4 ambient, diffuse, specular; // coeficientes de reflexión
	GLfloat expF; // exponente especular
	GLuint face = GL_FRONT_AND_BACK; // ambos lados
	GLuint sh = GL_SMOOTH; // smooth / flat shading
};

