// Dhruv Kapoor
// #3236690
// Project
// Generates a spaceship and allows it to be saved as a display list.

#include "spaceship.hpp"

GLfloat Spaceship::BASE_COLOUR[3] = { 0.5f, 0.5f, 0.5f };
GLfloat Spaceship::PYRAMID_COLOUR[3] = { 1.0f, 0.0f, 0.0f };

GLfloat Spaceship::TOP[4][3][3] = { { { 0.0f, 2.5f, 0.5f }, { -0.5f, 2.0f, 1.0f }, { 0.5f, 2.0f, 1.0f } },
{ { 0.0f, 2.5f, 0.5f }, { -0.5f, 2.0f, 0.0f }, { -0.5f, 2.0f, 1.0f } },
{ { 0.0f, 2.5f, 0.5f }, { 0.5f, 2.0f, 0.0f }, { -0.5f, 2.0f, 0.0f } },
{ { 0.0f, 2.5f, 0.5f }, { 0.5f, 2.0f, 1.0f }, { 0.5f, 2.0f, 0.0f } } };

GLfloat Spaceship::RIGHT_WING[3][3][3] = { { { 1.0f, 0.0f, 0.5f }, { 0.5f, 0.0f, 0.0f }, { 0.5f, 0.0f, 1.0f } },
{ { 1.0f, 0.0f, 0.5f }, { 0.5f, 1.0f, 0.5f }, { 0.5f, 0.0f, 1.0f } },
{ { 1.0f, 0.0f, 0.5f }, { 0.5f, 0.0f, 0.0f }, { 0.5f, 1.0f, 0.5f } } };

GLfloat Spaceship::BACK_WING[3][3][3] = { { { 0.0f, 0.0f, -0.5f }, { -0.5f, 0.0f, 0.0f }, { 0.5f, 0.0f, 0.0f } },
{ { 0.0f, 0.0f, -0.5f }, { 0.0f, 1.0f, 0.0f }, { 0.5f, 0.0f, 0.0f } },
{ { 0.0f, 0.0f, -0.5f }, { -0.5f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f } } };

GLfloat Spaceship::LEFT_WING[3][3][3] = { { { -1.0f, 0.0f, 0.5f }, { -0.5f, 0.0f, 0.0f }, { -0.5f, 0.0f, 1.0f } },
{ { -1.0f, 0.0f, 0.5f }, { -0.5f, 0.0f, 0.0f }, { -0.5f, 1.0f, 0.5f } },
{ { -1.0f, 0.0f, 0.5f }, { -0.5f, 1.0f, 0.5f }, { -0.5f, 0.0f, 1.0f } } };

GLfloat Spaceship::FRONT_WING[3][3][3] = { { { 0.0f, 0.0f, 1.5f }, { 0.5f, 0.0f, 1.0f }, { -0.5f, 0.0f, 1.0f } },
{ { 0.0f, 0.0f, 1.5f }, { 0.0f, 1.0f, 1.0f }, { -0.5f, 0.0f, 1.0f } },
{ { 0.0f, 0.0f, 1.5f }, { 0.5f, 0.0f, 1.0f }, { 0.0f, 1.0f, 1.0f } } };

GLfloat Spaceship::BASE[6][4][3] = { { { -0.5f, 0.0f, 0.0f }, { -0.5f, 0.0f, 1.0f }, { 0.5f, 0.0f, 1.0f }, { 0.5f, 0.0f, 0.0f } },
{ { -0.5f, 0.0f, 0.0f }, { 0.5f, 0.0f, 0.0f }, { 0.5f, 2.0f, 0.0f }, { -0.5f, 2.0f, 0.0f } },
{ { -0.5f, 0.0f, 0.0f }, { -0.5f, 2.0f, 0.0f }, { -0.5f, 2.0f, 1.0f }, { -0.5f, 0.0f, 1.0f } },
{ { 0.5f, 0.0f, 0.0f }, { 0.5f, 2.0f, 0.0f }, { 0.5f, 2.0f, 1.0f }, { 0.5f, 0.0f, 1.0f } },
{ { -0.5f, 0.0f, 1.0f }, { 0.5f, 0.0f, 1.0f }, { 0.5f, 2.0f, 1.0f }, { -0.5f, 2.0f, 1.0f } },
{ { -0.5f, 2.0f, 0.0f }, { -0.5f, 2.0f, 1.0f }, { 0.5f, 2.0f, 1.0f }, { 0.5f, 2.0f, 0.0f } } };

// Calls ship elements and saves the built ship in a display list.
void Spaceship::save(GLint index) {
	glNewList(index, GL_COMPILE);
	pyramid(TOP, false); // top
	pyramid(BACK_WING, true);
	pyramid(LEFT_WING, true);
	cuboid(BASE); //bulk
	pyramid(RIGHT_WING, true); // right wing
	pyramid(FRONT_WING, true);
	glEndList();
}

// Makes cuboid.
void Spaceship::cuboid(GLfloat const vertices[][4][3]) {
	glColor3f(BASE_COLOUR[0], BASE_COLOUR[1], BASE_COLOUR[2]);

	// Goes through each of the six wall rectangles.
	for (int i = 0; i < 6; i++) {
		glBegin(GL_QUADS);

		// Goes through a rectangle's vertices.
		for (int j = 0; j < 4; j++)
			glVertex3f(vertices[i][j][0], vertices[i][j][1], vertices[i][j][2]);

		glEnd();
	}
}

// Makes pyramid.
void Spaceship::pyramid(GLfloat const vertices[][3][3], bool wing) {
	GLint sides;

	// Get number of pyramid sides.
	if (wing)
		sides = 3;
	else
		sides = 4;

	glColor3f(PYRAMID_COLOUR[0], PYRAMID_COLOUR[1], PYRAMID_COLOUR[2]);

	// Goes through each of the triangles.
	for (int i = 0; i < sides; i++) {
		glBegin(GL_POLYGON);

		// Goes through a triangle's vertices.
		for (int j = 0; j < 3; j++)
			glVertex3f(vertices[i][j][0], vertices[i][j][1], vertices[i][j][2]);

		glEnd();
	}
}
