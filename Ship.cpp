/*
 * Ship.cpp
 *
 *  Created on: 30.06.2015
 *      Author: Oliver Thummerer
 */

#include "Ship.hpp"
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// constructor
Ship::Ship() {

}

// deconstructor
Ship::~Ship() {

}

// getter
float Ship::getPosPeak() {
	for(int i=0;i<3;i++) {
		return this->posPeak[i];
	};
}

float Ship::getPosBL() {
	for(int i=0;i<3;i++) {
		return this->posBL[i];
	}
}

float Ship::getPosBR() {
	for(int i=0;i<3;i++) {
		return this->posBR[i];
	}
}

float Ship::getPosFL() {
	for(int i=0;i<3;i++) {
		return this->posFL[i];
	}
}

float Ship::getPosFR() {
	for(int i=0;i<3;i++) {
		return this->posFR[i];
	}
}

// setter
float Ship::setPosPeak(float posPeak[]) {
	for(int i=0;i<3;i++) {
		this->posPeak[i] = posPeak[i];
	}
}

float Ship::setPosBL(float posBL[]) {
	for(int i=0;i<3;i++) {
		this->posBL[i] = posBL[i];
	}
}

float Ship::setPosBR(float posBR[]) {
	for(int i=0;i<3;i++) {
		this->posBR[i] = posBR[i];
	}
}

float Ship::setPosFL(float posFL[]) {
	for(int i=0;i<3;i++) {
		this->posFL[i] = posFL[i];
	}
}

float Ship::setPosFR(float posFR[]) {
	for(int i=0;i<3;i++) {
		this->posFR[i] = posFR[i];
	}
}

// set the Spaceship color
void Ship::setMaterialColor(int side, double r, double g, double b) {
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

void Ship::draw() {

	this->setMaterialColor(3,0,0,198);

	glBegin(GL_TRIANGLES);

	// triangles
	glNormal3f( 0.0, 0.0, 0.0);			// Set Top Point Of Triangle To Red
	glVertex3f(-2.0, 0.0,-2.0);      // First Point Of The Triangle
	glVertex3f( 2.0, 0.0,-2.0);      // Second Point Of The Triangle
	glVertex3f( 0.0, 5.0, 0.0);		 // Third Point Of The Triangle

	glNormal3f( 0.0, 0.0, 0.0);			// Set Top Point Of Triangle To Red
	glVertex3f( 2.0, 0.0,-2.0);      // First Point Of The Triangle
	glVertex3f( 2.0, 0.0, 2.0);      // Second Point Of The Triangle
	glVertex3f( 0.0, 5.0, 0.0);		 // Third Point Of The Triangle

	glNormal3f( 0.0, 0.0, 0.0);			// Set Top Point Of Triangle To Red
	glVertex3f( 2.0, 0.0, 2.0);      // First Point Of The Triangle
	glVertex3f(-2.0, 0.0, 2.0);      // Second Point Of The Triangle
	glVertex3f( 0.0, 5.0, 0.0);		 // Third Point Of The Triangle

	glNormal3f( 0.0, 0.0, 0.0);			// Set Top Point Of Triangle To Red
	glVertex3f(-2.0, 0.0, 2.0);      // First Point Of The Triangle
	glVertex3f(-2.0, 0.0,-2.0);      // Second Point Of The Triangle
	glVertex3f( 0.0, 5.0, 0.0);		 // Third Point Of The Triangle

	glEnd();

	glBegin(GL_QUADS);

	glNormal3f( 0.0, 0.0, 0.0);
	glVertex3f(-2.0, 0.0,-2.0);
	glVertex3f( 2.0, 0.0,-2.0);
	glVertex3f( 2.0, 0.0, 2.0);
	glVertex3f(-2.0, 0.0, 2.0);

	glEnd();
}
