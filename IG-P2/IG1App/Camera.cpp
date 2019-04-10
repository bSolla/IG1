#include "Camera.h"

#include <gtc/matrix_transform.hpp>  
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_access.hpp>

using namespace glm;

//-------------------------------------------------------------------------

void Camera::set2D() 
{
	eye = dvec3(0, 0, 500);
	look = dvec3(0, 0, 0);
	up = dvec3(0, 1, 0);
	viewMat = lookAt(eye, look, up);
	ang = 10.0;
}
//-------------------------------------------------------------------------

void Camera::set3D() 
{
	eye = dvec3(500, 500, 500);
	look = dvec3(0, 10, 0);
	up = dvec3(0, 1, 0);
	viewMat = lookAt(eye, look, up);
	ang = 10.0;
}
//-------------------------------------------------------------------------

void Camera::uploadVM() const
{

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(value_ptr(viewMat));
}
//-------------------------------------------------------------------------

//void Camera::pitch(GLdouble a) 
//{  
//	viewMat = rotate(viewMat, glm::radians(-a), glm::dvec3(1.0, 0, 0));
//}
////-------------------------------------------------------------------------
//void Camera::yaw(GLdouble a)
//{
//	viewMat = rotate(viewMat, glm::radians(-a), glm::dvec3(0, 1.0, 0));
//}
////-------------------------------------------------------------------------
//void Camera::roll(GLdouble a)
//{
//	viewMat = rotate(viewMat, glm::radians(-a), glm::dvec3(0, 0, 1.0));
//}
//-------------------------------------------------------------------------

void Camera::uploadSize(GLdouble aw, GLdouble ah)
{
	xRight = aw / 2.0;
	xLeft = -xRight;
	yTop = ah / 2.0;
	yBot = -yTop;

	if (orto) {
		projMat = ortho(xLeft*factScale, xRight*factScale, yBot*factScale, yTop*factScale, nearVal, farVal);
	}
	else {
		GLdouble top = nearVal * tan(90 / 2.0);
		GLdouble bot = -top;
		GLdouble right = top * (4 / 3);
		GLdouble left = -right;
		projMat = glm::frustum(left*factScale, right*factScale, bot*factScale, top*factScale, nearVal, farVal);
	}

	uploadPM();
}
//-------------------------------------------------------------------------

void Camera::uploadScale(GLdouble s)
{
	factScale -= s;
	if (factScale < 0) factScale = 0.01;

	if (orto) {
		projMat = ortho(xLeft*factScale, xRight*factScale, yBot*factScale, yTop*factScale, nearVal, farVal);
	}
	else {
		GLdouble top = nearVal * tan(90 / 2.0);
		GLdouble bot = -top;
		GLdouble right = top * (4 / 3);
		GLdouble left = -right;
		projMat = glm::frustum(left*factScale, right*factScale, bot*factScale, top*factScale, nearVal, farVal);
	}

	uploadPM();
}

void Camera::setAxes()
{
	right = row(viewMat, 0);
	upward = row(viewMat, 1);
	front = -row(viewMat, 2);
}

void Camera::setVM()
{
	viewMat = lookAt(eye, look, up);
	setAxes();
}

void Camera::moveLR(GLdouble cs)
{
	eye += right * cs;
	look += right * cs;
	setVM();
}

void Camera::moveFB(GLdouble cs)
{
	eye += front * cs;
	look += front * cs;
	setVM();
}

void Camera::moveUD(GLdouble cs)
{
	eye += upward * cs;
	look += upward * cs;
	setVM();
}

void Camera::orbit(GLdouble incAng, GLdouble incY)
{
	ang += incAng;
	eye.x = look.x + cos(radians(ang)) * radio;
	eye.z = look.z - sin(radians(ang)) * radio;
	eye.y += incY;
	setVM();

}

void Camera::setCameraTopView()
{
	eye = dvec3(0, 500, 0);
	look = dvec3(0, 0, 0);
	up = dvec3(0, 0, -1);
	setVM();
}

void Camera::changePrj()
{
	if (orto)
	{
		projMat = glm::ortho(xLeft, xRight, yBot, yTop, nearVal, farVal);
	}

	else
	{
		GLdouble top = nearVal * tan(90 / 2.0);
		GLdouble bot = -top;
		GLdouble right = top * (4 / 3);
		GLdouble left = -right;
		projMat = glm::frustum(left, right, bot, top, nearVal, farVal);
	}

	uploadPM();
}

//-------------------------------------------------------------------------

void Camera::uploadPM() const
{
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(value_ptr(projMat));
	glMatrixMode(GL_MODELVIEW);
}
//-------------------------------------------------------------------------


