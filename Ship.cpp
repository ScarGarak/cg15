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

float Ship::getAbX() {
	return this->abX;
}

float Ship::getAbY() {
	return this->abY;
}

float Ship::getBcX() {
	return this->bcX;
}

float Ship::getBcY() {
	return this->bcY;
}

float Ship::getAcX() {
	return this->acX;
}

float Ship::getAcY() {
	return this->acY;
}

float Ship::getshipTransX_() {
	return this->shipTransX_;
}

float Ship::getshipTransY_() {
	return this->shipTransY_;
}

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

// setter

void Ship::setAbX(float abX) {
	this->abX = abX;
}

void Ship::setAbY(float abY) {
	this->abY = abY;
}

void Ship::setBcX(float bcX) {
	this->bcX = bcX;
}

void Ship::setBcY(float bcY) {
	this->bcY = bcY;
}

void Ship::setAcX(float acX) {
	this->acX = acX;
}

void Ship::setAcY(float acY) {
	this->acY = acY;
}

void Ship::setShipTransX_(float shipTransX_) {
	this->shipTransX_ = shipTransX_;
}
void Ship::setShipTransY_(float shipTransY_) {
	this->shipTransY_ = shipTransY_;
}

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
	this->posBR[1] = posBRY;
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
	this->nextPosBR[1] = nextPosBRY;
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
    this->setAbX(getPosBRX() - getPosCenterX());
    this->setAbY(getPosBRY() - getPosCenterY());
    // BC = C - B
    this->setBcX(getPosPeakX() - getPosBRX());
    this->setBcY(getPosPeakY() - getPosBRY());

    this->setAcX(getAbX() + getBcX());
    this->setAcY(getAbY() + getBcY());

    // setzen der nextPos X/Y Koordinaten
    // Position(t+1)=position(t)+richtungsvektor*geschwindigkeit
    this->setNextPosCenterX(getNextPosCenterX() + getAcX() * speed);
    this->setNextPosCenterY(getNextPosCenterY() + getAcY() * speed);

    this->setNextPosPeakX(getPosPeakX() + getAcX() * speed);
    this->setNextPosPeakY(getPosPeakY() + getAcY() * speed);

    this->setNextPosBLX(getPosBLX() + getAcX() * speed);
    this->setNextPosBLY(getPosBLY() + getAcY() * speed);
    this->setNextPosFLX(getPosFLX() + getAcX() * speed);
    this->setNextPosFLY(getPosFLY() + getAcY() * speed);
    this->setNextPosBRX(getPosBRX() + getAcX() * speed);
    this->setNextPosBRY(getPosBRY() + getAcY() * speed);
    this->setNextPosFRX(getPosFRX() + getAcX() * speed);
    this->setNextPosFRY(getPosFRY() + getAcY() * speed);

    this->setPosCenterX(getNextPosCenterX());
    this->setPosCenterY(getNextPosCenterY());
//    setzen der rotationsparameter

	std::cout << this->getPosCenterY();
	std::cout << "/n";

    this->setPosPeakX(getNextPosPeakX());
    this->setPosPeakY(getNextPosPeakY());

    this->setPosBLX(getNextPosBLX());
    this->setPosBLY(getNextPosBLY());
    this->setPosFLX(getNextPosFLX());
    this->setPosFLY(getNextPosFLY());
    this->setPosBRX(getNextPosBRX());
    this->setPosBRY(getNextPosBRY());
    this->setPosFRX(getNextPosFRX());
    this->setPosFRY(getNextPosFRY());

}
