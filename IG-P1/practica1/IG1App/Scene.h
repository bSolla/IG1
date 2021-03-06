//#pragma once
#ifndef _H_Scene_H_
#define _H_Scene_H_

#include <GL/freeglut.h>
#include <glm.hpp>

#include "Camera.h"
#include "Entity.h"
#include "Poliespiral.h"
#include "Dragon.h"
#include "TrianguloRGB.h"
#include "RectanguloRGB.h"
#include "TrianguloAnimado.h"
#include "Caja.h"
#include "Estrella3D.h"
#include "Cristalera.h"
#include "Foto.h"
//#include "Mesh.h"

#include <vector>

//-------------------------------------------------------------------------

class Scene	
{ 
public:

    Scene() { };
	~Scene();
    void init(); 

    void render(Camera const& cam);
	void update();
	void update (GLuint timeElapsed);

	void changeScene(bool its3D);

protected:

	std::vector<Entity*> grObjects;  // Entities (graphics objects) of the scene

private:
	void scene2d();
	void scene3d();
};

//-------------------------------------------------------------------------

#endif //_H_Scene_H_

