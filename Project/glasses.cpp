// Dhruv Kapoor
// #3236690
// Project
// Generates glasses and allows them to be saved as a display list.

#include "glasses.hpp"

GLfloat Glasses::GLASSES_COLOUR[3] = { 0.0f, 0.0f, 0.2f };
GLfloat Glasses::LENS_COLOUR[3] = { 0.788f, 0.859f, 0.863f };

GLfloat Glasses::RIGHT_EAR[4][3][3] = { { { 0.9f, 0.4f, 0.1f }, { 0.8f, 0.8f, 0.2f }, { 1.0f, 0.8f, 0.2f } },
{ { 0.9f, 0.4f, 0.1f }, { 0.8f, 0.8f, 0.0f }, { 0.8f, 0.8f, 0.2f } },
{ { 0.9f, 0.4f, 0.1f }, { 1.0f, 0.8f, 0.0f }, { 0.8f, 0.8f, 0.0f } },
{ { 0.9f, 0.4f, 0.1f }, { 1.0f, 0.8f, 0.2f }, { 1.0f, 0.8f, 0.0f } } };

GLfloat Glasses::LEFT_EAR[4][3][3] = { { { -0.9f, 0.4f, 0.1f }, { -1.0f, 0.8f, 0.2f }, { -0.8f, 0.8f, 0.2f } },
{ { -0.9f, 0.4f, 0.1f }, { -1.0f, 0.8f, 0.0f }, { -1.0f, 0.8f, 0.2f } },
{ { -0.9f, 0.4f, 0.1f }, { -0.8f, 0.8f, 0.0f }, { -1.0f, 0.8f, 0.0f } },
{ { -0.9f, 0.4f, 0.1f }, { -0.8f, 0.8f, 0.2f }, { -0.8f, 0.8f, 0.0f } } };

GLfloat Glasses::RIGHT_BAR[6][4][3] = { { { 0.8f, 0.8f, 0.0f }, { 0.8f, 0.8f, 2.0f }, { 1.0f, 0.8f, 2.0f }, { 1.0f, 0.8f, 0.0f } },
{ { 0.8f, 0.8f, 0.0f }, { 1.0f, 0.8f, 0.0f }, { 1.0f, 1.0f, 0.0f }, { 0.8f, 1.0f, 0.0f } },
{ { 1.0f, 0.8f, 2.0f }, { 1.0f, 0.8f, 0.0f }, { 1.0f, 1.0f, 0.0f }, { 1.0f, 1.0f, 2.0f } },
{ { 0.8f, 0.8f, 0.0f }, { 0.8f, 1.0f, 0.0f }, { 0.8f, 1.0f, 2.0f }, { 0.8f, 0.8f, 2.0f } },
{ { 0.8f, 0.8f, 2.0f }, { 1.0f, 0.8f, 2.0f }, { 1.0f, 1.0f, 2.0f }, { 0.8f, 1.0f, 2.0f } },
{ { 1.0f, 1.0f, 2.0f }, { 1.0f, 1.0f, 0.0f }, { 0.8f, 1.0f, 0.0f }, { 0.8f, 1.0f, 2.0f } } };

GLfloat Glasses::LEFT_BAR[6][4][3] = { { { -1.0f, 0.8f, 0.0f }, { -1.0f, 0.8f, 2.0f }, { -0.8f, 0.8f, 2.0f }, { -0.8f, 0.8f, 0.0f } },
{ { -1.0f, 0.8f, 0.0f }, { -0.8f, 0.8f, 0.0f }, { -0.8f, 1.0f, 0.0f }, { -1.0f, 1.0f, 0.0f } },
{ { -0.8f, 0.8f, 2.0f }, { -0.8f, 0.8f, 0.0f }, { -0.8f, 1.0f, 0.0f }, { -0.8f, 1.0f, 2.0f } },
{ { -1.0f, 0.8f, 0.0f }, { -1.0f, 1.0f, 0.0f }, { -1.0f, 1.0f, 2.0f }, { -1.0f, 0.8f, 2.0f } },
{ { -1.0f, 0.8f, 2.0f }, { -0.8f, 0.8f, 2.0f }, { -0.8f, 1.0f, 2.0f }, { -1.0f, 1.0f, 2.0f } },
{ { -0.8f, 1.0f, 2.0f }, { -0.8f, 1.0f, 0.0f }, { -1.0f, 1.0f, 0.0f }, { -1.0f, 1.0f, 2.0f } } };

GLfloat Glasses::RIGHT_FRAME[6][4][3] = { { { 1.0f, 0.2f, 2.0f }, { 1.0f, 0.2f, 2.2f }, { 0.2f, 0.2f, 2.2f }, { 0.2f, 0.2f, 2.0f } },
{ { 1.0f, 0.2f, 2.0f }, { 0.2f, 0.2f, 2.0f }, { 0.2f, 1.0f, 2.0f }, { 1.0f, 1.0f, 2.0f } },
{ { 1.0f, 0.2f, 2.2f }, { 1.0f, 0.2f, 2.0f }, { 1.0f, 1.0f, 2.0f }, { 1.0f, 1.0f, 2.2f } },
{ { 0.2f, 0.2f, 2.2f }, { 0.2f, 0.2f, 2.0f }, { 0.2f, 1.0f, 2.0f }, { 0.2f, 1.0f, 2.2f } },
{ { 1.0f, 0.2f, 2.2f }, { 0.2f, 0.2f, 2.2f }, { 0.2f, 1.0f, 2.2f }, { 1.0f, 1.0f, 2.2f } },
{ { 1.0f, 1.0f, 2.0f }, { 1.0f, 1.0f, 2.2f }, { 0.2f, 1.0f, 2.2f }, { 0.2f, 1.0f, 2.0f } } };

GLfloat Glasses::LEFT_FRAME[6][4][3] = { { { -0.2f, 0.2f, 2.0f }, { -0.2f, 0.2f, 2.2f }, { -1.0f, 0.2f, 2.2f }, { -1.0f, 0.2f, 2.0f } },
{ { -0.2f, 0.2f, 2.0f }, { -1.0f, 0.2f, 2.0f }, { -1.0f, 1.0f, 2.0f }, { -0.2f, 1.0f, 2.0f } },
{ { -0.2f, 0.2f, 2.2f }, { -0.2f, 0.2f, 2.0f }, { -0.2f, 1.0f, 2.0f }, { -0.2f, 1.0f, 2.2f } },
{ { -1.0f, 0.2f, 2.2f }, { -1.0f, 0.2f, 2.0f }, { -1.0f, 1.0f, 2.0f }, { -1.0f, 1.0f, 2.2f } },
{ { -0.2f, 0.2f, 2.2f }, { -1.0f, 0.2f, 2.2f }, { -1.0f, 1.0f, 2.2f }, { -0.2f, 1.0f, 2.2f } },
{ { -0.2f, 1.0f, 2.0f }, { -0.2f, 1.0f, 2.2f }, { -1.0f, 1.0f, 2.2f }, { -1.0f, 1.0f, 2.0f } } };

GLfloat Glasses::CONNECTOR[6][4][3] = { { { -0.2f, 0.6f, 2.0f }, { -0.2f, 0.6f, 2.2f }, { 0.2f, 0.6f, 2.2f }, { 0.2f, 0.6f, 2.0f } },
{ { -0.2f, 0.6f, 2.0f }, { 0.2f, 0.6f, 2.0f }, { 0.2f, 0.7f, 2.0f }, { -0.2f, 0.7f, 2.0f } },
{ { -0.2f, 0.6f, 2.0f }, { -0.2f, 0.7f, 2.0f }, { -0.2f, 0.7f, 2.2f }, { -0.2f, 0.6f, 2.2f } },
{ { 0.2f, 0.6f, 2.0f }, { 0.2f, 0.7f, 2.0f }, { 0.2f, 0.7f, 2.2f }, { 0.2f, 0.6f, 2.2f } },
{ { -0.2f, 0.6f, 2.2f }, { 0.2f, 0.6f, 2.2f }, { 0.2f, 0.7f, 2.2f }, { -0.2f, 0.7f, 2.2f } },
{ { -0.2f, 0.7f, 2.0f }, { -0.2f, 0.7f, 2.2f }, { 0.2f, 0.7f, 2.2f }, { 0.2f, 0.7f, 2.0f } } };

GLfloat Glasses::RIGHT_LENS[6][4][3] = { { { 0.3f, 0.3f, 2.0f }, { 0.3f, 0.3f, 2.2f }, { 0.9f, 0.3f, 2.2f }, { 0.9f, 0.3f, 2.0f } },
{ { 0.3f, 0.3f, 2.0f }, { 0.9f, 0.3f, 2.0f }, { 0.9f, 0.9f, 2.0f }, { 0.3f, 0.9f, 2.0f } },
{ { 0.3f, 0.3f, 2.0f }, { 0.3f, 0.9f, 2.0f }, { 0.3f, 0.9f, 2.2f }, { 0.3f, 0.3f, 2.2f } },
{ { 0.9f, 0.3f, 2.0f }, { 0.9f, 0.9f, 2.0f }, { 0.9f, 0.9f, 2.2f }, { 0.9f, 0.3f, 2.2f } },
{ { 0.3f, 0.3f, 2.2f }, { 0.9f, 0.3f, 2.2f }, { 0.9f, 0.9f, 2.2f }, { 0.3f, 0.9f, 2.2f } },
{ { 0.3f, 0.9f, 2.0f }, { 0.3f, 0.9f, 2.2f }, { 0.9f, 0.9f, 2.2f }, { 0.9f, 0.9f, 2.0f } } };

GLfloat Glasses::LEFT_LENS[6][4][3] = { { { -0.9f, 0.3f, 2.0f }, { -0.9f, 0.3f, 2.2f }, { -0.3f, 0.3f, 2.2f }, { -0.3f, 0.3f, 2.0f } },
{ { -0.9f, 0.3f, 2.0f }, { -0.3f, 0.3f, 2.0f }, { -0.3f, 0.9f, 2.0f }, { -0.9f, 0.9f, 2.0f } },
{ { -0.9f, 0.3f, 2.0f }, { -0.9f, 0.9f, 2.0f }, { -0.9f, 0.9f, 2.2f }, { -0.9f, 0.3f, 2.2f } },
{ { -0.3f, 0.3f, 2.0f }, { -0.3f, 0.9f, 2.0f }, { -0.3f, 0.9f, 2.2f }, { -0.3f, 0.3f, 2.2f } },
{ { -0.9f, 0.3f, 2.2f }, { -0.3f, 0.3f, 2.2f }, { -0.3f, 0.9f, 2.2f }, { -0.9f, 0.9f, 2.2f } },
{ { -0.9f, 0.9f, 2.0f }, { -0.9f, 0.9f, 2.2f }, { -0.3f, 0.9f, 2.2f }, { -0.3f, 0.9f, 2.0f } } };

// Calls glasses elements and saves the built glasses in a display list.
void Glasses::save(GLint index) {
	glNewList(index, GL_COMPILE);
	pyramid(LEFT_EAR);
	pyramid(RIGHT_EAR);
	cuboid(LEFT_BAR, false);
	cuboid(RIGHT_BAR, false);
	cuboid(CONNECTOR, false);
	cuboid(LEFT_FRAME, false);
	cuboid(RIGHT_FRAME, false);
	cuboid(RIGHT_LENS, true);
	cuboid(LEFT_LENS, true);
	glEndList();
}

// Makes cuboid.
void Glasses::cuboid(GLfloat const vertices[][4][3], bool lens) {
	// Grab the appropriate colour.
	if (lens)
		glColor3f(LENS_COLOUR[0], LENS_COLOUR[1], LENS_COLOUR[2]);
	else
		glColor3f(GLASSES_COLOUR[0], GLASSES_COLOUR[1], GLASSES_COLOUR[2]);

	// Goes through each of the six wall rectangles.
	for (int i = 0; i < 6; i++) {
		glBegin(GL_QUADS);

		// Goes through a rectangle's vertices.
		for (int j = 0; j < 4; j++)
			glVertex3f(vertices[i][j][0], vertices[i][j][1], vertices[i][j][2]);

		glEnd();
	}
}

// Makes reverse pyramid.
void Glasses::pyramid(GLfloat const vertices[][3][3]) {
	glColor3f(GLASSES_COLOUR[0], GLASSES_COLOUR[1], GLASSES_COLOUR[2]);

	// Goes through each of the 4 triangles.
	for (int i = 0; i < 4; i++) {
		glBegin(GL_POLYGON);

		// Goes through a triangle's vertices.
		for (int j = 0; j < 3; j++)
			glVertex3f(vertices[i][j][0], vertices[i][j][1], vertices[i][j][2]);

		glEnd();
	}
}
