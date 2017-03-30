// Dhruv Kapoor
// #3236690
// Project
// Draws a scene with lighting effects, a background, and atmospheric attenuation (option 1).
//
// Scene Components:
//      table     - five 3D shapes
//      spaceship - five 3D shapes
//      glasses   - nine 3D shapes
//      mug       - eight 3D shapes, one 2D shape
//      book      - four 3D shapes, one 2D shape
//
// Lighting Components:
//      lamp - red, green, or blue
//      time - noon (white), evening (orange), or night (black)
//
// Background Components:
//		room wallpaper - positioned behind table
//
// Notes:
//      - lighting effects are triggered through the menu
//      - menu is visible by right-clicking
//      - there is no ambient lighting in the scene at any point
//      - lamp light attenuates
//      - background colour varies with lighting
//      - there is an atmospheric attenuation fog effect
//      - fog varies the lighting

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "table.hpp"
#include "spaceship.hpp"
#include "glasses.hpp"
#include "mug.hpp"
#include "book.hpp"
#include "lighting.hpp"
#include "background.hpp"

// Holds display list indices.
// Order is table, spaceship, glasses, mug, and lastly book.
GLint objects[5];

// Sets up window and view.
void setup(GLint maxX, GLint maxY) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(maxX, maxY);
	glutCreateWindow("PROJECT");
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Empty space is black.

	glEnable(GL_FOG);              // Turn on atmospheric attenuation.
	glFogf(GL_FOG_DENSITY, 0.05f);

	glMatrixMode(GL_PROJECTION);
	glFrustum(-1.0f, 1.0f, -1.0f, 1.0f, 2.0f, 50.0f);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_COLOR_MATERIAL); // Make sure object colours are kept.

	initLighting();
}

// Grabs objects and stores them in the global array.
void getObjects() {
	Table table;
	Spaceship spaceship;
	Glasses glasses;
	Mug mug;
	Book book;

	GLint index = glGenLists(5);

	table.save(index);
	objects[0] = index++;

	spaceship.save(index);
	objects[1] = index++;

	glasses.save(index);
	objects[2] = index++;

	mug.save(index);
	objects[3] = index++;

	book.save(index);
	objects[4] = index;
}

// Transforms objects and draws them.
void drawObjects() {
	// Transformation arrays.
	GLfloat scales[5][3] = { { 2.0f, 1.5f, 1.5f },
	{ 0.5f, 0.7f, 0.5f },
	{ 0.5f, 0.5f, 0.5f },
	{ 0.4f, 0.6f, 0.4f },
	{ 0.7f, 0.7f, 0.7f } };
	GLfloat translations[5][3] = { { 0.7f, -1.5f, 0.0f },
	{ 2.0f, 0.0f, -5.0f },
	{ -4.5f, 0.0f, -2.5f },
	{ 4.0f, 0.0f, 1.5f },
	{ -3.0f, 0.0f, 2.0f } };
	GLfloat rotations[5][4] = { { -60.0f, 0.0f, 1.0f, 0.0f },
	{ -10.0f, 0.0f, 1.0f, 0.0f },
	{ 50.0f, 0.0f, 1.0f, 0.0f },
	{ -5.0f, 0.0f, 1.0f, 0.0f },
	{ 35.0f, 0.0f, 1.0f, 0.0f } };

	// Transform and draw each object.
	for (int i = 0; i < sizeof(objects) / sizeof(objects[0]); i++) {
		glPushMatrix();
		glScalef(scales[i][0], scales[i][1], scales[i][2]);
		glTranslatef(translations[i][0], translations[i][1], translations[i][2]);
		glRotatef(rotations[i][0], rotations[i][1], rotations[i][2], rotations[i][3]);
		glCallList(objects[i]);
		glPopMatrix();
	}
}

// Draws background
void drawBackground() {
	processImage();

	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2d(0.0, 0.0); glVertex3f(-8.0f, 0.0f, 1.0f);
	glTexCoord2d(0.0, 1.0); glVertex3f(-8.0f, 7.0f, 1.0f);
	glTexCoord2d(1.0, 1.0); glVertex3f(8.0f, 7.0f, -2.0f);
	glTexCoord2d(1.0, 0.0); glVertex3f(8.0f, 0.0f, -2.0f);
	glEnd();
	glPopMatrix();

	// Leave objects unaltered.
	glBindTexture(GL_TEXTURE_2D, 0);
}

// Top-level drawing function.
void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // Draw objects as solid.

	glLoadIdentity();
	gluLookAt(0.0f, 6.0f, 10.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f);

	drawBackground();
	getObjects();
	drawObjects();

	glutSwapBuffers();
}

// Entry point.
int main(int argc, char* argv[]) {
	GLint maxX = 500;
	GLint maxY = 500;

	glutInit(&argc, argv);
	setup(maxX, maxY);

	glutDisplayFunc(render);

	makeMenu();

	glutMainLoop();

	return 0;
}
