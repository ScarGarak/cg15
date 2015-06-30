/*
 * Planets.hpp
 *
 *  Created on: 29.06.2015
 *      Author: Oliver Thummerer
 */

#ifndef PLANETS_H
#define PLANETS_H

#define Planet_Radius 2

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

class Planet {

protected:
	// Position
	float xPos = 0;
	float yPos = 0;
	float zPos = 0;
	double size = 4;

	// weight
	float mass = 1;

	// Set color
	virtual void setMaterialColor(int side, double r, double g, double b);

	float radius = Planet_Radius;

public:
	// (de)constructor
	Planet();
	~Planet();

	// getter/setter declaration
	float getXPos();
	float getYPos();
	float getZPos();
	double getSize();
	void setXPos(float);
	void setYPos(float);
	void setZPos(float);

	void draw(const Vec3 & ctr, double r);

//	void setMaterialColor(int side, double r, double g, double b);

	// own methods
	float getMass();

};

#endif /* PLANETS_H */
