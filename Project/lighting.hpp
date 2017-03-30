// Dhruv Kapoor
// #3236690
// Project
// Library used for lighting effects.

#ifndef lighting_hpp
#define lighting_hpp

#include <cstdlib>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

const GLfloat lamp_position[] = { -0.7f, 4.0f, 1.0f, 1.0f }; // Above table.
const GLfloat red_light[] = { 1.0f, 0.0f, 0.0f, 0.0f };      // Red lamp.
const GLfloat green_light[] = { 0.0f, 1.0f, 0.0f, 0.0f };    // Green lamp.
const GLfloat blue_light[] = { 0.0f, 0.0f, 1.0f, 0.0f };     // Blue lamp.

const GLfloat window_position[] = { 0.0f, 0.6f, 10.0f, 1.0f };  // Behind viewer.
const GLfloat noon_light[] = { 1.0f, 1.0f, 1.0f, 0.0f };        // White sunlight.
const GLfloat evening_light[] = { 1.0f, 0.576f, 0.161f, 0.0f }; // Orange sunlight.

// Initializes lighting.
void initLighting();

// Light menus.
void lampOption(GLint option);
void sunOption(GLint option);

// Main menu control.
void mainMenu(GLint option);

// Menu maker.
void makeMenu();

#endif /* lighting_hpp */
