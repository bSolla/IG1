#include "Scene.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

using namespace glm;

//-------------------------------------------------------------------------

void Scene::init()
{ // OpenGL basic setting
  glClearColor(1.0, 1.0, 1.0, 1.0);  // background color (alpha=1 -> opaque)
  glEnable(GL_DEPTH_TEST);  // enable Depth test 
     
  // lights
  // textures  
  // meshes

  // Graphics objects (entities) of the scene
  //grObjects.push_back(new EjesRGB(200.0));
  //grObjects.push_back(new Poliespiral(glm::dvec2(0.0, 0.0), 0, 61, 1.2, 1, 200));
  //grObjects.push_back(new Dragon(3000));
  //grObjects.push_back(new TrianguloRGB(100));

  /*grObjects.push_back(new RectanguloRGB(200, 100));
  dmat4 m = grObjects.back()->getModelMat();
  dvec3 v = { 0.0, 0.0, 1.0 };
  m = rotate(m, radians(25.0), dvec3(v));
  grObjects.back()->setModelMat(m);*/

  grObjects.push_back(new TrianguloAnimado(100));



}
//-------------------------------------------------------------------------

Scene::~Scene()
{ // free memory and resources   
  
  for (Entity* el: grObjects)
  {
	  delete el;  el = nullptr;
  }
}
//-------------------------------------------------------------------------

void Scene::render(Camera const& cam)
{
	for (Entity* el: grObjects)
	{
		el->render(cam);
	}
}
//-------------------------------------------------------------------------

void Scene::update()
{
	for (Entity* el : grObjects)
	{
		el->update();
	}
}
//-------------------------------------------------------------------------

