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
#include "Esfera.h"
#include "DirLight.h"
#include "PosLight.h"
#include "SpotLight.h"
#include "EsferaLuz.h"

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

	void enableCamLight(bool enable);
	void enableDirLight(bool enable);
	void enableSphereLight(bool enable) { esferaLuz->enableLight(enable); };


protected:

	std::vector<Entity*> grObjects;  // Entities (graphics objects) of the scene
	DirLight * dirLight;
	SpotLight * camLight;
	EsferaLuz * esferaLuz;


private:
	void scene2d();
	void scene3d();
	void sceneQuad ();

	Texture* textArray[5];
	//Texture textArray[3];
};

//-------------------------------------------------------------------------

#endif //_H_Scene_H_

