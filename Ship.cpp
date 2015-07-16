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
#include <iostream>

// constructor
Ship::Ship() {

}

// deconstructor
Ship::~Ship() {

}

// getter
float Ship::getPosCenterX() {
	return this->posCenter[0];
}

float Ship::getPosCenterY() {
	return this->posCenter[1];
}

float Ship::getPosPeakX() {
	return this->posPeak[0];
}

float Ship::getPosPeakY() {
	return this->posPeak[1];
}

float Ship::getPosBLX() {
	return this->posBL[0];
}

float Ship::getPosBLY() {
	return this->posBL[1];
}

float Ship::getPosBRX() {
	return this->posBR[0];
}

float Ship::getPosBRY() {
	return this->posBR[1];
}

float Ship::getPosFLX() {
	return this->posBL[0];
}

float Ship::getPosFLY() {
	return this->posBL[1];
}

float Ship::getPosFRX() {
	return this->posFR[0];
}

float Ship::getPosFRY() {
	return this->posFR[1];
}

float Ship::getNextPosCenterX() {
	return this->nextPosCenter[0];
}

float Ship::getNextPosCenterY() {
	return this->nextPosCenter[1];
}

float Ship::getNextPosPeakX() {
	return this->nextPosPeak[0];
}
float Ship::getNextPosPeakY() {
	return this->nextPosPeak[1];
}

float Ship::getNextPosBLX() {
	return this->nextPosBL[0];
}

float Ship::getNextPosBLY() {
	return this->nextPosBL[1];
}

float Ship::getNextPosFLX() {
	return this->nextPosFL[0];
}

float Ship::getNextPosFLY() {
	return this->nextPosFL[1];
}

float Ship::getNextPosBRX() {
	return this->nextPosBR[0];
}

float Ship::getNextPosBRY() {
	return this->nextPosBR[1];
}

float Ship::getNextPosFRX() {
	return this->nextPosFR[0];
}

float Ship::getNextPosFRY() {
	return this->nextPosFR[1];
}

bool Ship::getMovement() {
    return this->moving;
}

// getter/setter für die speed Variable

// setter
void Ship::setPosCenterX(float posCenterX) {
	this->posCenter[0] = posCenterX;
}

void Ship::setPosCenterY(float posCenterY) {
	this->posCenter[1] = posCenterY;
}

void Ship::setPosPeakX(float posPeakX) {
	this->posPeak[0] = posPeakX;
}

void Ship::setPosPeakY(float posPeakY) {
	this->posPeak[1] = posPeakY;
}

void Ship::setPosBLX(float posBLX) {
	this->posBL[0] = posBLX;
}

void Ship::setPosBLY(float posBLY) {
	this->posBL[1] = posBLY;
}

void Ship::setPosBRX(float posBRX) {
	this->posBR[0] = posBRX;
}

void Ship::setPosBRY(float posBRY) {
	this->posBR[0] = posBRY;
}

void Ship::setPosFLX(float posFLX) {
	this->posFL[0] = posFLX;
}

void Ship::setPosFLY(float posFLY) {
	this->posFL[1] = posFLY;
}

void Ship::setPosFRX(float posFRX) {
	this->posFR[0] = posFRX;
}

void Ship::setPosFRY(float posFRY) {
	this->posFR[1] = posFRY;
}

void Ship::setNextPosCenterX(float nextPosCenterX) {
	this->nextPosCenter[0] = nextPosCenterX;
}

void Ship::setNextPosCenterY(float nextPosCenterY) {
	this->nextPosCenter[1] = nextPosCenterY;
}

void Ship::setNextPosPeakX(float nextPosPeakX) {
	this->nextPosPeak[0] = nextPosPeakX;
}

void Ship::setNextPosPeakY(float nextPosPeakY) {
	this->nextPosPeak[1] = nextPosPeakY;
}

void Ship::setNextPosBLX(float nextPosBRX) {
	this->nextPosBL[0] = nextPosBRX;
}

void Ship::setNextPosBLY(float nextPosBRY) {
	this->nextPosBL[1] = nextPosBRY;
}

void Ship::setNextPosBRX(float nextPosBRX) {
	this->nextPosBR[0] = nextPosBRX;
}

void Ship::setNextPosBRY(float nextPosBRY) {
	this->nextPosBR[0] = nextPosBRY;
}

void Ship::setNextPosFLX(float nextPosFLX) {
	this->nextPosFL[0] = nextPosFLX;
}

void Ship::setNextPosFLY(float nextPosFLY) {
	this->nextPosFL[1] = nextPosFLY;
}

void Ship::setNextPosFRX(float nextPosFRX) {
	this->nextPosFR[0] = nextPosFRX;
}

void Ship::setNextPosFRY(float nextPosFRY) {
	this->nextPosFR[1] = nextPosFRY;
}

void Ship::setMovement(bool m) {
	this->moving = m;
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
	glVertex3f(posFR[0],posFR[1],posFR[2]);      // First Point Of The Triangle
	glVertex3f(posFL[0],posFL[1],posFL[2]);      // Second Point Of The Triangle
	glVertex3f(posPeak[0],posPeak[1],posPeak[2]);		 // Third Point Of The Triangle

	glNormal3f( 0.0, 0.0, 0.0);			// Set Top Point Of Triangle To Red
	glVertex3f(posFL[0],posFL[1],posFL[2]);      // First Point Of The Triangle
	glVertex3f(posBR[0],posBR[1],posBR[2]);      // Second Point Of The Triangle
	glVertex3f(posPeak[0],posPeak[1],posPeak[2]);		 // Third Point Of The Triangle

	glNormal3f( 0.0, 0.0, 0.0);			// Set Top Point Of Triangle To Red
	glVertex3f(posBR[0],posBR[1],posBR[2]);      // First Point Of The Triangle
	glVertex3f(posBL[0],posBL[1],posBL[2]);      // Second Point Of The Triangle
	glVertex3f(posPeak[0],posPeak[1],posPeak[2]);		 // Third Point Of The Triangle

	glNormal3f( 0.0, 0.0, 0.0);			// Set Top Point Of Triangle To Red
	glVertex3f(posBL[0],posBL[1],posBL[2]);      // First Point Of The Triangle
	glVertex3f(posFR[0],posFR[1],posFR[2]);      // Second Point Of The Triangle
	glVertex3f(posPeak[0],posPeak[1],posPeak[2]);		 // Third Point Of The Triangle

	glEnd();

	glBegin(GL_QUADS);

	glNormal3f( 0.0, 0.0, 0.0);
	glVertex3f(posFR[0],posFR[1],posFR[2]);
	glVertex3f(posFL[0],posFL[1],posFL[2]);
	glVertex3f(posBR[0],posBR[1],posBR[2]);
	glVertex3f(posBL[0],posBL[1],posBL[2]);

	glEnd();
}

void Ship::move() {
    	// AB = B - A
    	float abX = getPosBRX() - getPosCenterX();
    	float abY = getPosBRY() - getPosCenterY();
    	// BC = C - B
    	float bcX = getPosPeakX() - getPosBRX();
    	float bcY = getPosPeakY() - getPosBRY();
    	float acX = abX + bcX;
    	float acY = abY + bcY;

    	// setzen der nextPos X/Y Koordinaten
    	// Position(t+1)=position(t)+richtungsvektor*geschwindigkeit
    	setNextPosCenterX(getNextPosCenterX() + acX * 0.5);
    	setNextPosCenterY(getNextPosCenterY() + acX * 0.5);
    	setNextPosPeakX(getPosPeakX() + acX * 0.5);
    	setNextPosPeakY(getPosPeakY() + acY * 0.5);
//    	setNextPosBLX(getPosBLX() + acY * 0.5);
//    	setNextPosBLY(getPosBLY() + acY * 0.5);
//    	setNextPosFLX(getPosFLX() + acY * 0.5);
//    	setNextPosFLY(getPosFLY() + acY * 0.5);
//    	setNextPosBRX(getPosBLX() + acY * 0.5);
//    	setNextPosBRY(getPosBLY() + acY * 0.5);
//    	setNextPosFRX(getPosFLX() + acY * 0.5);
//    	setNextPosFRY(getPosFLY() + acY * 0.5);

    	this->setPosCenterX(getNextPosCenterX());
    	this->setPosCenterY(getNextPosCenterY());
        this->setPosPeakX(getNextPosPeakX());
        this->setPosPeakY(getNextPosPeakY());
//        this->setPosBLX(getNextPosBLX());
//        this->setPosBLY(getNextPosBLY());
//        this->setPosFLX(getNextPosFLX());
//        this->setPosFLY(getNextPosFLY());
//        this->setPosBRX(getNextPosBRX());
//        this->setPosBRY(getNextPosBRY());
//        this->setPosFRX(getNextPosFRX());
//        this->setPosFRY(getNextPosFRY());


//        this->setPosBL(nextPosBL);
//		this->setPosFL(nextPosFL);
//		this->setPosBR(nextPosBR);
//		this->setPosFR(nextPosFR);

	// Position(t+1)=position(t)+richtungsvektor*geschwindigkeit
	// Position(t+1) = posPeak[0]
//	posPeak[0] = posPeak[0] + (LookVec[0] * (Direction * 0.01));
//	posPeak[1] = posPeak[1] + (LookVec[1] * (Direction * 0.01));
//	posPeak[2] = posPeak[2] + (LookVec[2] * (Direction * 0.01));
}
