/*
 * Planets.cpp
 *
 *  Created on: 29.06.2015
 *      Author: Oliver Thummerer
 */



#include "Planets.hpp"
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>

// constructor
Planet::Planet() {

}

// deconstructor
Planet::~Planet() {

}

// getter
float Planet::getXPos(){
    return this->xPos;
}

float Planet::getYPos(){
    return this->yPos;
}

float Planet::getZPos(){
    return this->zPos;
}

double Planet::getSize(){
	return this->size;
}

// setter

void Planet::setXPos(float xPos){
	this->xPos = xPos;
}

void Planet::setYPos(float yPos){
	this->yPos = yPos;
}

void Planet::setZPos(float zPos){
	this->zPos = zPos;
}

// set the sphere color
void Planet::setMaterialColor(int side, double r, double g, double b) {
	float	amb[4], dif[4], spe[4];
	  int mat;

	  dif[0] = r;
	  dif[1] = g;
	  dif[2] = b;

	  for(int i = 0; i < 3; i++) {
	    amb[i] = .1 * dif[i];
	    spe[i] = .5;
	  }
	  amb[3] = dif[3] = spe[3] = 1.0;

	  switch(side){
	    case 1:	mat = GL_FRONT;
	      break;
	    case 2:	mat = GL_BACK;
	      break;
	    default: mat = GL_FRONT_AND_BACK;
	  }

	  glMaterialfv(mat, GL_AMBIENT, amb);
	  glMaterialfv(mat, GL_DIFFUSE, dif);
	  glMaterialfv(mat, GL_SPECULAR, spe);
	  glMaterialf( mat, GL_SHININESS, 20);
}

// draw a sphere composed of triangles
void Planet::draw(const Vec3& ctr, double r){

  this->setMaterialColor(1,0,155,0);

  int     i, j,
          n1 = 6, n2 = 12;
  Vec3    normal, v1;
  double  a1, a1d = M_PI / n1,
          a2, a2d = M_PI / n2,
          s1, s2,
          c1, c2;

  glShadeModel(GL_SMOOTH);
  for(i = 0; i < n1; i++){
    a1 = i * a1d;

    glBegin(GL_TRIANGLE_STRIP);
    for(j = 0; j <= n2; j++){
      a2 = (j + .5 * (i % 2)) * 2 * a2d;

      s1 = sin(a1);
      c1 = cos(a1);
      s2 = sin(a2);
      c2 = cos(a2);
      normal = c1 * XVec3 + s1 * (c2 * YVec3 + s2 * ZVec3);
      v1 = ctr + r * normal;
      glNormal3dv(normal.p);
      glVertex3dv(v1.p);

      s1 = sin(a1 + a1d);
      c1 = cos(a1 + a1d);
      s2 = sin(a2 + a2d);
      c2 = cos(a2 + a2d);
      normal = c1 * XVec3 + s1 * (c2 * YVec3 + s2 * ZVec3);
      v1 = ctr + r * normal;
      glNormal3dv(normal.p);
      glVertex3dv(v1.p);
    }
    glEnd();
  }
}
