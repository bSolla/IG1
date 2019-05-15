//#include <Windows.h>
//#include <gl/GL.h>    // OpenGL
//#include <gl/GLU.h>   // OpenGL Utility Library
//#include <GL/glut.h>  // OpenGL Utility Toolkit

#include <GL/freeglut.h>  // Free OpenGL Utility Toolkit for creating windows, initializing OpenGL contexts, and handling input events
#include <glm.hpp>  // OpenGL Mathematics. A C++ mathematics library for graphics programming 

#include "Viewport.h"
#include "Camera.h"
#include "Scene.h"

#include <iostream>

using namespace std;

//---------- Global variables -------------------------------------------------------------

// Viewport position and size
Viewport viewPort(400, 600);   
Viewport viewportAux(200, 300);

// Camera position, view volume and projection
Camera camera(&viewPort);    
Camera cameraAux(&viewportAux);

// Graphics objects of the scene
Scene scene;   

// Update management
GLuint lastTick = 0;
const GLuint TICKS_BETWEEN_UPDATES = 50;
bool autoUpdate = false;

// Scene change
bool its3D = false;

// screenShot
Texture screenShot;

// Mouse
glm::dvec2 mCoord;
int mBot;

// Lightning bools
bool camLightEnabled = true;
bool dirLightEnabled = true;
bool sphereLightEnabled = true;

//----------- Callbacks ----------------------------------------------------

void display();
void resize(int newWidth, int newHeight);
void key(unsigned char key, int x, int y);
void specialKey(int key, int x, int y);
void update ();

void mouse(int button, int state, int x, int y);
void motion(int x, int y);
void mouseWheel(int n, int d, int x, int y);

//-------------------------------------------------------------------------

int main(int argc, char *argv[])
{
  cout << "Starting console..." << '\n';

  // Initialization
  glutInit(&argc, argv);

  glutInitContextVersion(3, 3);
  glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);  // GLUT_CORE_PROFILE
  glutInitContextFlags(GLUT_DEBUG);   // GLUT_FORWARD_COMPATIBLE
 
  glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS); 
  
  glutInitWindowSize(800, 600);   // window size
  //glutInitWindowPosition (140, 140);

  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH /*| GLUT_STENCIL*/); // RGBA colors, double buffer, depth buffer and stencil buffer   
  
  int win = glutCreateWindow("IG1App");  // window's identifier
  
  // Callback registration
  glutReshapeFunc(resize);
  glutKeyboardFunc(key);
  glutSpecialFunc(specialKey);
  glutDisplayFunc(display);
  glutIdleFunc (update);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);
  glutMouseWheelFunc(mouseWheel);
 
  cout << glGetString(GL_VERSION) << '\n';
  cout << glGetString(GL_VENDOR) << '\n';

  // after creating the context
  camera.set2D();
  cameraAux.set2D();
  cameraAux.setCameraTopView();
  scene.init();    
  
  glutMainLoop(); 
    
  //cin.ignore(INT_MAX, '\n');  cin.get();  
  glutDestroyWindow(win);  // Destroy the context 
 
  return 0;
}
//-------------------------------------------------------------------------


void display()   // double buffering
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   
  
  scene.render(camera);

  scene.render(cameraAux);
    
  glutSwapBuffers();  
}
//-------------------------------------------------------------------------

void resize(int newWidth, int newHeight)
{
  // Resize Viewport 
  viewPort.uploadSize(newWidth / 2, newHeight);  
  viewportAux.uploadSize(newWidth / 2, newHeight);

  viewPort.uploadPos(0, 0);
  viewportAux.uploadPos(newWidth / 2, 0);

  // Resize Scene Visible Area 
  camera.uploadSize(viewPort.getW(), viewPort.getH());    // scale unchanged
  cameraAux.uploadSize(viewportAux.getW(), viewportAux.getH());
}
//-------------------------------------------------------------------------

void key(unsigned char key, int x, int y)
{
  bool need_redisplay = true;

  switch (key) {
  case 27:  // Escape key 
    glutLeaveMainLoop();  // Freeglut's sentence for stopping glut's main loop 
    break;
  case '+': 
    camera.uploadScale(+0.01);   // zoom in  (increases the scale)
    break;
  case '-':
    camera.uploadScale(-0.01);   // zoom out (decreases the scale)
    break;
  case 'l':
	camera.set3D(); 
	break;
  case 'o':
	camera.set2D();
	break;
	
	// manual update ----------------------
  case 'u':
	  if (!autoUpdate) {
		  scene.update ();
	  }
	  break;
  case 'U':
	  autoUpdate = !autoUpdate;
	  break;
  case '3':
	  its3D = !its3D;
	  scene.changeScene(its3D);
	  break;
  case 'F':
	  screenShot.save("Screenshot");
	  break;
  case 'p':
	  camera.orto = !camera.orto;
	  camera.changePrj();
	  cameraAux.orto = !cameraAux.orto;
	  cameraAux.changePrj ();
	  break;
  case 'b':
	  sphereLightEnabled = !sphereLightEnabled;
	  scene.enableSphereLight(sphereLightEnabled);
	  break;
  case 'c':
	  camLightEnabled = !camLightEnabled;
	  scene.enableCamLight(camLightEnabled);
	  break;
  case 'v':
	  dirLightEnabled = !dirLightEnabled;
	  scene.enableDirLight(dirLightEnabled);
	  break;
  default:
	need_redisplay = false;
    break;
  } //switch

  if (need_redisplay)
    glutPostRedisplay();
}
//-------------------------------------------------------------------------

void specialKey(int key, int x, int y)
{
  bool need_redisplay = true;

  switch (key) {
  //case GLUT_KEY_RIGHT:
  //  //camera.pitch(1);   // rotate 1 on the X axis
  //  break;
  //case GLUT_KEY_LEFT:
  //  //camera.yaw(1);     // rotate 1 on the Y axis 
  //  break;
  //case GLUT_KEY_UP:
  //  //camera.roll(1);    // rotate 1 on the Z axis
  //  break;
  //case GLUT_KEY_DOWN:
  //  //camera.roll(-1);   // rotate -1 on the Z axis
  //  break;
  default:
    need_redisplay = false;
    break;
  }//switch

  if (need_redisplay)
    glutPostRedisplay();
}


void update () {
	if (autoUpdate) {
		bool need_redisplay = false;
		GLuint elapsedTime = glutGet (GLUT_ELAPSED_TIME) - lastTick;

		if (elapsedTime > TICKS_BETWEEN_UPDATES) {
			lastTick = glutGet (GLUT_ELAPSED_TIME);
			need_redisplay = true;
			scene.update (elapsedTime);
		}

		if (need_redisplay) {
			glutPostRedisplay ();
		}
	}
}

void mouse(int button, int state, int x, int y)
{
	mBot = button;
	mCoord = glm::dvec2(x, y);
}

void motion(int x, int y)
{
	if (mBot == GLUT_LEFT_BUTTON)
	{
		glm::dvec2 mp = mCoord;
		mCoord = glm::dvec2(x, y);
		mp = (mCoord - mp);
		camera.orbit(mp.x * 0.05, mp.y);
		glutPostRedisplay();
	}

	else if (mBot == GLUT_RIGHT_BUTTON)
	{
		glm::dvec2 mp = mCoord;
		mCoord = glm::dvec2(x, y);
		mp = (mCoord - mp);
		camera.moveLR(mp.x);
		camera.moveUD(mp.y);
		glutPostRedisplay();
	}
}

void mouseWheel(int n, int d, int x, int y)
{
	int m = glutGetModifiers();

	//if (m == 0)
	//{
		if (d == 1)
		{
			camera.moveFB(5);
		}
		else
		{
			camera.moveFB(-5);
		}
	//}

	glutPostRedisplay();
}

//-------------------------------------------------------------------------

