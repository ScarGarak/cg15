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

	float posPeak[3] = {0,0,0};
	float posBL[3] = {0,0,0};
	float posFL[3] = {0,0,0};
	float posBR[3] = {0,0,0};
	float posFR[3] = {0,0,0};

	float mass = 1;

	void setMaterialColor(int side, double r, double g, double b);

public:
	// (de)constructor
	Ship();
	~Ship();

	// getter/setter declaration
	float getPosPeak();
	float getPosBL();
	float getPosFL();
	float getPosBR();
	float getPosFR();

	float setPosPeak(float posPeak[]);
	float setPosBL(float posBR[]);
	float setPosBR(float posBR[]);
	float setPosFL(float posFL[]);
	float setPosFR(float posFR[]);

	void draw();
};



#endif /* SHIP_HPP_ */
