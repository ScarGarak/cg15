/*
 * Ship.hpp
 *
 *  Created on: 30.06.2015
 *      Author: Oliver Thummerer
 */

#ifndef SHIP_HPP_
#define SHIP_HPP_

#include <GLFW/glfw3.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <iterator>
#include "vec3.hpp"

using namespace std;

class Ship {

protected:

	// Hilfsvariable zum berechnen des Richtungsvektors
	float posCenter[3] = {0,0,0};

	float posPeak[3] = {0,5.0,0};
	float posBL[3] = {-2.0,0, 2.0};
	float posFL[3] = { 2.0,0,-2.0};
	float posBR[3] = { 2.0,0, 2.0};
	float posFR[3] = {-2.0,0,-2.0};

	float nextPosCenter[3] = {0,0,0};
	float nextPosPeak[3] = {0,5.0,0};
	float nextPosBL[3] = {-2.0,0, 2.0};
	float nextPosFL[3] = { 2.0,0,-2.0};
	float nextPosBR[3] = { 2.0,0, 2.0};
	float nextPosFR[3] = {-2.0,0,-2.0};

	bool moving = false;
	float speed = 0.5;
	float mass = 1;

	void setMaterialColor(int side, double r, double g, double b);

public:
	// (de)constructor
	Ship();
	~Ship();

	// getter/setter declaration
	float getPosCenterX();
	float getPosCenterY();
	float getPosPeakX();
	float getPosPeakY();
	float getPosBLX();
	float getPosBLY();
	float getPosFLX();
	float getPosFLY();
	float getPosBRX();
	float getPosBRY();
	float getPosFRX();
	float getPosFRY();

	float getNextPosCenterX();
	float getNextPosCenterY();
	float getNextPosPeakX();
	float getNextPosPeakY();
	float getNextPosBLX();
	float getNextPosBLY();
	float getNextPosFLX();
	float getNextPosFLY();
	float getNextPosBRX();
	float getNextPosBRY();
	float getNextPosFRX();
	float getNextPosFRY();

	float getDirection();
	bool getMovement();

	void setPosCenterX(float posCenterX);
	void setPosCenterY(float posCenterY);
	void setPosPeakX(float posPeakX);
	void setPosPeakY(float posPeakY);
	void setPosBLX(float posBRX);
	void setPosBLY(float posBRY);
	void setPosBRX(float posBRX);
	void setPosBRY(float posBRY);
	void setPosFLX(float posFLX);
	void setPosFLY(float posFLY);
	void setPosFRX(float posFRX);
	void setPosFRY(float posFRY);

	void setNextPosCenterX(float nextPosCenterX);
	void setNextPosCenterY(float nextPosCenterY);
	void setNextPosPeakX(float nextPosPeakX);
	void setNextPosPeakY(float nextPosPeakY);
	void setNextPosBLX(float nextPosBRX);
	void setNextPosBLY(float nextPosBRY);
	void setNextPosBRX(float nextPosBRX);
	void setNextPosBRY(float nextPosBRY);
	void setNextPosFLX(float nextPosFLX);
	void setNextPosFLY(float nextPosFLY);
	void setNextPosFRX(float nextPosFRX);
	void setNextPosFRY(float nextPosFRY);

	void setMovement(bool m);

	void draw();
	void move();
};



#endif /* SHIP_HPP_ */
