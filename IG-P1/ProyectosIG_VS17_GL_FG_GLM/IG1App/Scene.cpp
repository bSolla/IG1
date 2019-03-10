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
    glEnable(GL_TEXTURE_2D);
  // meshes

  // Graphics objects (entities) of the scene
  
  grObjects.push_back(new EjesRGB(200.0));

  // ---------------------------------------------
  // --			P O L I E S P I R A L			--
  // ---------------------------------------------

  //grObjects.push_back(new Poliespiral(glm::dvec2(0.0, 0.0), 0, 61, 1.2, 1, 200));



  // ---------------------------------------------
  // --				D R A G Ó N					--
  // ---------------------------------------------

  //grObjects.push_back(new Dragon(3000));
  //dmat4 mDragon = grObjects.back()->getModelMat();
  //dvec3 vDragon = { 20.0, 20.0, 20.0 };
  //double aDragon = radians (45.0);
  //mDragon = scale(mDragon, vDragon);
  //mDragon = rotate (mDragon, aDragon, dvec3 { 0.0, 0.0, 1.0 });
  //grObjects.back()->setModelMat(mDragon);



  // ---------------------------------------------
  // --			T R I Á N G U L O  R G B		--
  // ---------------------------------------------
  
  //grObjects.push_back(new TrianguloRGB(100));



  // ---------------------------------------------
  // --		  R E C T Á N G U L O  R G B		--
  // ---------------------------------------------

  //grObjects.push_back(new RectanguloRGB(200, 100));
  //dmat4 m = grObjects.back()->getModelMat();
  //dvec3 v = { 0.0, 0.0, 1.0 };
  //m = rotate(m, radians(25.0), dvec3(v));
  //grObjects.back()->setModelMat(m);



  // ---------------------------------------------
  // --	  T R I Á N G U L O  A N I M A D O		--
  // ---------------------------------------------

  //grObjects.push_back(new TrianguloAnimado(100));



  // ---------------------------------------------
  // --			E S C E N A  2 D				--
  // ---------------------------------------------

  //dmat4 m;
  //grObjects.push_back (new TrianguloAnimado (85.0)); // ---------------------------------- triángulo animado
  //grObjects.push_back (new TrianguloRGB (120.0)); // ------------------------------------- triángulo rgb
  //m = grObjects.back ()->getModelMat ();
  //m = translate (dmat4 (1), dvec3 { -300.0, 180.0, 0.0 });
  //m = rotate (m, radians (70.0), dvec3 { 0.0, 0.0, 1.0 });
  //grObjects.back ()->setModelMat (m);
  //grObjects.push_back (new Dragon (3500)); //--------------------------------------------- dragón
  //m = grObjects.back ()->getModelMat ();
  //m = translate (dmat4 (1), dvec3 { -100.0, -60.0, 0.0 });
  //m = rotate (m, radians (130.0), dvec3 { 0.0, 0.0, 1.0 });
  //m = scale (m, dvec3 { 20.0, 20.0, 20.0 });
  //grObjects.back ()->setModelMat (m);
  //grObjects.push_back (new RectanguloRGB (250, 150)); // -------------------------------- rectángulo rgb
  //m = grObjects.back ()->getModelMat ();
  //m = translate (dmat4 (1), dvec3 { 200.0, 100.0, 0.0 });
  //m = rotate (m, radians (60.0), dvec3 { 0.0, 0.0, 1.0 });
  //grObjects.back ()->setModelMat (m);
  //grObjects.push_back (new Poliespiral (dvec2 { 0.0, 0.0 }, 0, 72.0, 30.0, 2.0, 400)); // poliespiral
  //m = grObjects.back ()->getModelMat ();
  //m = translate (dmat4 (1), dvec3 { 50.0, -30.0, 0.0 });
  //m = rotate (m, radians (-10.0), dvec3 { 0.0, 0.0, 1.0 });
  //grObjects.back ()->setModelMat (m);



  // ---------------------------------------------
  // --			E S T R E L L A  3 D			--
  // ---------------------------------------------

  //grObjects.push_back(new Estrella3D(100, 6, 150));



  // ---------------------------------------------
  // --				C A J A						--
  // ---------------------------------------------
  //grObjects.push_back(new Caja(20));

  // ---------------------------------------------
  // --			 E S C E N A  3 D   			--
  // ---------------------------------------------
  dmat4 m;

  grObjects.push_back(new Estrella3D(50, 6, 50));
  m = grObjects.back()->getModelMat();
  m = translate(dmat4(1), dvec3(-100, 200, -100));
  grObjects.back()->setModelMat(m);


  grObjects.push_back(new Caja(100));
  m = grObjects.back()->getModelMat();
  m = translate(dmat4(1), dvec3(-100, 50.2, -100));
  m = rotate(m, radians(90.0), dvec3(0.0, 1.0, 0.0));
  grObjects.back()->setModelMat(m);

  grObjects.push_back (new RectanguloRGB (500, 500)); // -------------------------------- rectángulo rgb
  m = grObjects.back ()->getModelMat ();
  m = rotate (m, radians (90.0), dvec3 { 1.0, 0.0, 0.0 });
  grObjects.back()->setModelMat(m);


//grObjects.push_back(new RectanguloRGB(500, 500));
//grObjects.push_back(new Estrella3D(100, 6, 150));



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

