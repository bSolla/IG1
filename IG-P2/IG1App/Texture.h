#pragma once
#include "Pixmap32RGBA.h"
#include <glm.hpp>

class Texture
{
public:
	Texture(GLint wrap = GL_REPEAT) : w(0), h(0), id(0) {};
	~Texture() { if (id != 0) glDeleteTextures(1, &id); };
	void load(const std::string & BMP_Name, GLubyte alpha = 255);
	// cargar y transferir a GPU
	void bind(GLint mode = GL_REPLACE); // para mezcla de colores
	void bind(GLint mode, bool light);
	void unbind() { glBindTexture(GL_TEXTURE_2D, 0); };
	void save(const std::string & BMP_Name);
protected:
	GLuint w, h; // dimensiones de la imagen
	GLuint id; // identificador interno (GPU) de la textura
	void init();
};

