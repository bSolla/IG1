#include "Scene.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>

using namespace glm;

//-------------------------------------------------------------------------

void Scene::init()
{ // OpenGL basic setting
  glClearColor(0.2, 0.2, 0.2, 1.0);  // background color (alpha=1 -> opaque)
  glEnable(GL_DEPTH_TEST);  // enable Depth test 
     
  // lights
  glEnable(GL_LIGHTING);
  glEnable(GL_NORMALIZE);
  dirLight = new DirLight();
  dirLight->setDir(fvec3(0, -0.25, -1));
  dirLight->enable();

  camLight = new SpotLight();
  camLight->setPos(fvec3(0.0, 0.0, 0.0));
  camLight->setDir(fvec4(0.0, 0.0, -1.0, 0.0));
  camLight->enable();

  // textures  
    glEnable(GL_TEXTURE_2D);
	for (uint i = 0; i < 6; ++i) {
		textArray[i] = new Texture;
	}
	textArray[0]->load ("..\\Bmps\\sun.bmp");
	textArray[1]->load ("..\\Bmps\\mars.bmp");
	textArray[2]->load ("..\\Bmps\\moon.bmp");
	textArray[3]->load("..\\Bmps\\earth.bmp");
	textArray[4]->load("..\\Bmps\\lego.bmp");
	textArray[5]->load("..\\Bmps\\terrenoG.bmp");
  // meshes

  // Graphics objects (entities) of the scene
  
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

  //scene2d();



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
  
  //scene3d();



  // ---------------------------------------------
  // --			E S C E N A  Q U A D   			--
  // ---------------------------------------------
	sceneQuad ();
}
//-------------------------------------------------------------------------

Scene::~Scene()
{ // free memory and resources   
  for (uint i = 0; i < 3; ++i) {
	  delete textArray[i]; textArray[i] = nullptr;
  }
  for (Entity* el: grObjects)
  {
	  delete el;  el = nullptr;
  }
}
//-------------------------------------------------------------------------

void Scene::render(Camera const& cam)
{
	cam.getVP()->upload();
	//glm::fvec4 camDir = cam.getCamDir();
	//glm::fvec3 camPos = cam.getCamPos();
	//camLight->setPos(camPos);
	//camLight->setDir(camDir);
	camLight->upload(glm::dmat4(1.0)); // si ponemos que use la viewMat de cam, no funciona correctamente cuando se cambia el eye de la cam (consejo de Antonio)
	
	dirLight->upload(cam.getViewMat());
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


void Scene::update (GLuint elapsedTime) {
	for (Entity* el : grObjects) {
		el->update(elapsedTime);
	}
}
//-------------------------------------------------------------------------

void Scene::changeScene(bool its3d) {
	int size = grObjects.size();
	for (int i = 0; i < size; ++i) {
		grObjects.back()->~Entity();
		grObjects.pop_back();
	}

	if (its3d) {
		scene3d();
	}
	else {
		scene2d();
	}
}

void Scene::enableCamLight(bool enable)
{
	if (enable) {
		camLight->enable();
	}
	else
		camLight->disable();
}

void Scene::enableDirLight(bool enable)
{
	if (enable) {
		dirLight->enable();
	}
	else
		dirLight->disable();
}

void Scene::scene2d() {
	dmat4 m;
	grObjects.push_back(new EjesRGB(200.0)); // ------------------------------------------ ejes RGB
	grObjects.push_back(new TrianguloAnimado(85.0)); // ---------------------------------- triangulo animado
	grObjects.push_back(new TrianguloRGB(120.0)); // ------------------------------------- triangulo rgb
	m = grObjects.back()->getModelMat();
	m = translate(dmat4(1), dvec3{ -300.0, 180.0, 0.0 });
	m = rotate(m, radians(70.0), dvec3{ 0.0, 0.0, 1.0 });
	grObjects.back()->setModelMat(m);
	grObjects.push_back(new Dragon(3500)); //--------------------------------------------- dragon
	m = grObjects.back()->getModelMat();
	m = translate(dmat4(1), dvec3{ -100.0, -60.0, 0.0 });
	m = rotate(m, radians(130.0), dvec3{ 0.0, 0.0, 1.0 });
	m = scale(m, dvec3{ 20.0, 20.0, 20.0 });
	grObjects.back()->setModelMat(m);
	grObjects.push_back(new RectanguloRGB(250, 150)); // -------------------------------- rectangulo rgb
	m = grObjects.back()->getModelMat();
	m = translate(dmat4(1), dvec3{ 200.0, 100.0, 0.0 });
	m = rotate(m, radians(60.0), dvec3{ 0.0, 0.0, 1.0 });
	grObjects.back()->setModelMat(m);
	grObjects.push_back(new Poliespiral(dvec2{ 0.0, 0.0 }, 0, 72.0, 30.0, 2.0, 400)); // poliespiral
	m = grObjects.back()->getModelMat();
	m = translate(dmat4(1), dvec3{ 50.0, -30.0, 0.0 });
	m = rotate(m, radians(-10.0), dvec3{ 0.0, 0.0, 1.0 });
	grObjects.back()->setModelMat(m);

}



void Scene::scene3d() {
	dmat4 m;

	grObjects.push_back(new Estrella3D(50, 4, 50)); // ------------------------------------ Estrella 3D
	m = grObjects.back()->getModelMat();
	m = translate(dmat4(1), dvec3(-100, 200, -100));
	grObjects.back()->setModelMat(m);


	grObjects.push_back(new Caja(100)); // ------------------------------------------------ Caja
	m = grObjects.back()->getModelMat();
	m = translate(dmat4(1), dvec3(-100, 50.2, -100));
	m = rotate(m, radians(90.0), dvec3(0.0, 1.0, 0.0));
	grObjects.back()->setModelMat(m);

	grObjects.push_back(new RectanguloRGB(500, 500)); // -------------------------------- Rectángulo rgb
	m = grObjects.back()->getModelMat();
	m = rotate(m, radians(90.0), dvec3{ 1.0, 0.0, 0.0 });
	grObjects.back()->setModelMat(m);

	grObjects.push_back(new Foto(80, 40)); // --------------------------------------------- Foto
	m = grObjects.back()->getModelMat();
	m = translate(dmat4(1), dvec3(0.0, 1, 0.0));
	m = rotate(m, radians(90.0), dvec3{ 1.0, 0.0, 0.0 });
	grObjects.back()->setModelMat(m);

	grObjects.push_back(new Cristalera(500)); // ------------------------------------------ Cristalera
	m = grObjects.back()->getModelMat();
	m = translate(dmat4(1), dvec3(0, 250, 0));
	grObjects.back()->setModelMat(m);
}

void Scene::sceneQuad () {
	glEnable (GL_CULL_FACE);
	glDisable(GL_BLEND);

	dmat4 m;

	grObjects.push_back(new EjesRGB(200.0)); // ----------------------------------------- ejes RGB
	
	//grObjects.push_back(new RectanguloRGB(500, 500)); // -------------------------------- Rectángulo rgb
	//m = grObjects.back()->getModelMat();
	//m = rotate(m, radians(90.0), dvec3{ 1.0, 0.0, 0.0 });
	//grObjects.back()->setModelMat(m);

	/*grObjects.push_back (new Esfera (75));
	static_cast<Esfera*>(grObjects.back())->setMaterial(MaterialList::gold);
	static_cast<Esfera*>(grObjects.back ())->setTexture (textArray[0]);
	m = grObjects.back()->getModelMat();
	m = translate(dmat4(1), dvec3(0, 200, 0));
	grObjects.back()->setModelMat(m);*/

	grObjects.push_back (new Esfera (20));
	static_cast<Esfera*>(grObjects.back ())->setTexture (textArray[1]);
	static_cast<Esfera*>(grObjects.back())->setMaterial(MaterialList::brass);
	m = grObjects.back()->getModelMat();
	m = translate(dmat4(1), dvec3(150, 80, 200));
	grObjects.back()->setModelMat(m);

	grObjects.push_back (new Esfera (10));
	static_cast<Esfera*>(grObjects.back ())->setTexture (textArray[2]);
	static_cast<Esfera*>(grObjects.back())->setMaterial(MaterialList::pewter);
	m = grObjects.back()->getModelMat();
	m = translate(dmat4(1), dvec3(-100, 50, 100));
	grObjects.back()->setModelMat(m);

	grObjects.push_back(new Esfera(300));
	static_cast<Esfera*>(grObjects.back())->setTexture(textArray[3]);
	static_cast<Esfera*>(grObjects.back())->setMaterial(MaterialList::pewter);
	m = grObjects.back()->getModelMat();
	m = translate(dmat4(1), dvec3(0, -350, 0));
	grObjects.back()->setModelMat(m);

	esferaLuz = new EsferaLuz(50);
	m = esferaLuz->getModelMat();
	m = translate(dmat4(1), dvec3(0, 100, 0));
	esferaLuz->setModelMat(m);
	esferaLuz->setMaterial(MaterialList::pewter);
	esferaLuz->setTexture(textArray[4]);
	grObjects.push_back(esferaLuz);

	Superficie* superficie = new Superficie(100, 4, 90);
	superficie->setTexture(textArray[5]);
	superficie->setMaterial(MaterialList::brass);
	grObjects.push_back(superficie);
}
