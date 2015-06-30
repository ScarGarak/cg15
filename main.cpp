/*
 * main.cpp
 *
 *  Created on: 23.06.2015
 *      Author: Adam, Olli
 */

// libs
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>

// header files
#include "vec3.hpp"
#include "Planets.hpp"
#include "Ship.hpp"

using namespace::std;

static double alpha_ = 0, beta_=0;
static double zoom_ = -12.0;
static double window_width_ = 1024;
static double window_height_ = 768;

vector<Planet*> thePlanets;
vector<Ship*> theShip;

void initShip() {
	// init object vector for Ship
	theShip = *new vector<Ship*>;
	// generate an Ship object
	Ship a;

	a.draw();
}

void initPlanets() {
	// init object vector for Planet
	thePlanets = *new vector<Planet*>;
	// generate an Planet object
	Planet a;
	// set position & color
	a.setXPos(-25);
	a.setYPos(6);
//	a.setMaterialColor(3, 1, 0, 0);

	Planet b;
//	b.setMaterialColor(3, 1, 2, 0);
	b.setXPos(25);
	b.setYPos(-5);
	// push Planet objects to vector
	thePlanets.push_back(&a);
	thePlanets.push_back(&b);
	// draw Planets
	a.draw(Vec3(a.getXPos(),a.getYPos(),a.getZPos()),a.getSize());
	b.draw(Vec3(b.getXPos(),b.getYPos(),b.getZPos()),b.getSize());
}

// Brings the game back to the beginning
void resetGame() {
	// code
}


//const GLfloat spShip [] = {
//		{0f,0f,0f}
//};

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

    if (key == GLFW_KEY_D /*&& action == GLFW_PRESS*/) {
    	std::cout << "D pressed!\n";
        beta_+=1;
        }
    if (key == GLFW_KEY_A /*&& action == GLFW_PRESS*/) {
    	std::cout << "A pressed!\n";
       	beta_-=1;
        }
    if (key == GLFW_KEY_W /*&& action == GLFW_PRESS*/) {
    	std::cout << "W pressed!\n";
    	alpha_-=1;
        }
    if (key == GLFW_KEY_S /*&& action == GLFW_PRESS*/) {
    	std::cout << "S pressed!\n";
       	alpha_+=1;
        }
    if (key == GLFW_KEY_KP_SUBTRACT /*&& action == GLFW_PRESS*/) {
    	std::cout << "MINUS pressed!\n";
        zoom_-=.5;
        }
    if (key == GLFW_KEY_KP_ADD /*&& action == GLFW_PRESS*/) {
    	std::cout << "PLUS pressed!\n";
        zoom_+=.5;
    }
    if (key == GLFW_KEY_ESCAPE /*&& action == GLFW_PRESS*/) {
    	std::cout << "ESCAPE pressed!\n";
        glfwTerminate();
        }
        //activate_airship();
}


void DrawQuads(/*Parameter um Position zu beeinflussen(x,y,z)*/) {
	glBegin(GL_QUADS);            // Start Drawing Quads

	// Spielfeld
	glNormal3f( 0.0, 0.0, 0.0);			// Set Top Point Of Quad To Red
	glVertex3f(-50.0, 50.0,-4.0);      // First Point Of The Quad
	glVertex3f(-50.0,-50.0,-4.0);      // Second Point Of The Quad
	glVertex3f( 50.0,-50.0,-4.0);      // Third Point Of The Quad
	glVertex3f( 50.0, 50.0,-4.0);      // Fourth Point Of The Quad

	glEnd();
}

void SetMaterialColor(int side, double r, double g, double b) {
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



// set viewport transformations and draw objects
void InitLighting() {
  GLfloat lp1[4]  = { 10,  5,  10,  0};
  GLfloat lp2[4]  = { -5,  5, -10,  0};
  GLfloat red[4]  = {1.0, .8,  .8,  1};
  GLfloat blue[4] = { .8, .8, 1.0,  1};

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glShadeModel(GL_SMOOTH);
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 1);
  glEnable(GL_LIGHTING);

  glLightfv(GL_LIGHT1, GL_POSITION, lp1);
  glLightfv(GL_LIGHT1, GL_DIFFUSE,  red);
  glLightfv(GL_LIGHT1, GL_SPECULAR, red);
  glEnable(GL_LIGHT1);

  glLightfv(GL_LIGHT2, GL_POSITION, lp2);
  glLightfv(GL_LIGHT2, GL_DIFFUSE,  blue);
  glLightfv(GL_LIGHT2, GL_SPECULAR, blue);
  glEnable(GL_LIGHT2);

  glClearColor(1, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // init viewport to canvassize
  glViewport(0, 0, window_width_, window_height_);

  // init coordinate system
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-55, 55,-55, 55,-100, 100);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}



// draw the entire scene
void Preview() {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();						    // Reset The Current Modelview Matrix

  glPushMatrix();

	  glTranslated(0, 0, zoom_);      // Move 10 units backwards in z,
									  // since camera is at origin
	  glRotated(alpha_, 1, 0, 0);
	  glRotatef(beta_, 0, 1, 0);

	  // draw the planets
	  initPlanets();

	  //Aufruf DrawQuads();
	  SetMaterialColor(3, 0, 0, 0);
	  DrawQuads();

	  glPushMatrix();
	  	  initShip();
	  glPopMatrix();
  glPopMatrix();
}

int main() {

  GLFWwindow* window = NULL;

  printf("Here we go!\n");

//  DrawSphere() mySphere;

  if(!glfwInit()){
    return -1;
  }

  window = glfwCreateWindow(window_width_, window_height_,
                            "Simple 3D Animation", NULL, NULL);
  if(!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  while(!glfwWindowShouldClose(window)) {
    // switch on lighting (or you don't see anything)
    InitLighting();

    // set background color
    glClearColor(0.8, 0.8, 0.8, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // draw the scene
    Preview();
    glfwSetKeyCallback(window, key_callback);

    // make it appear (before this, it's hidden in the rear buffer)
    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  glfwTerminate();

  printf("Goodbye!\n");

  return 0;
}
