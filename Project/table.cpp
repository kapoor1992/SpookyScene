// Dhruv Kapoor
// #3236690
// Project
// Generates a table and allows it to be saved as a display list.

#include "table.hpp"

GLfloat Table::LEG_COLOUR[3] = { 0.545f, 0.271f, 0.075f };
GLfloat Table::TOP_COLOUR[3] = { 0.491f, 0.244f, 0.068f };

GLfloat Table::TOP[6][4][3] = { { { 1.5f, 1.8f, -0.5f }, { 1.5f, 1.8f, 2.5f }, { -1.5f, 1.8f, 2.5f }, { -1.5f, 1.8f, -0.5f } },
{ { 1.5f, 1.8f, -0.5f }, { -1.5f, 1.8f, -0.5f }, { -1.5f, 2.0f, -0.5f }, { 1.5f, 2.0f, -0.5f } },
{ { 1.5f, 1.8f, 2.5f }, { 1.5f, 1.8f, -0.5f }, { 1.5f, 2.0f, -0.5f }, { 1.5f, 2.0f, 2.5f } },
{ { -1.5f, 1.8f, 2.5f }, { -1.5f, 1.8f, -0.5f }, { -1.5f, 2.0f, -0.5f }, { -1.5f, 2.0f, 2.5f } },
{ { 1.5f, 1.8f, 2.5f }, { -1.5f, 1.8f, 2.5f }, { -1.5f, 2.0f, 2.5f }, { 1.5f, 2.0f, 2.5f } },
{ { 1.5f, 2.0f, -0.5f }, { 1.5f, 2.0f, 2.5f }, { -1.5f, 2.0f, 2.5f }, { -1.5f, 2.0f, -0.5f } } };

GLfloat Table::B_RIGHT[6][4][3] = { { { 1.0f, 0.0f, 0.0f }, { 1.0f, 0.0f, 0.5f }, { 0.5f, 0.0f, 0.5f }, { 0.5f, 0.0f, 0.0f } },
{ { 1.0f, 0.0f, 0.0f }, { 0.5f, 0.0f, 0.0f }, { 0.5f, 1.8f, 0.0f }, { 1.0f, 1.8f, 0.0f } },
{ { 1.0f, 0.0f, 0.5f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 1.8f, 0.0f }, { 1.0f, 1.8f, 0.5f } },
{ { 0.5f, 0.0f, 0.5f }, { 0.5f, 0.0f, 0.0f }, { 0.5f, 1.8f, 0.0f }, { 0.5f, 1.8f, 0.5f } },
{ { 1.0f, 0.0f, 0.5f }, { 0.5f, 0.0f, 0.5f }, { 0.5f, 1.8f, 0.5f }, { 1.0f, 1.8f, 0.5f } },
{ { 1.0f, 1.8f, 0.0f }, { 1.0f, 1.8f, 0.5f }, { 0.5f, 1.8f, 0.5f }, { 0.5f, 1.8f, 0.0f } } };

GLfloat Table::F_RIGHT[6][4][3] = { { { 1.0f, 0.0f, 1.5f }, { 1.0f, 0.0f, 2.0f }, { 0.5f, 0.0f, 2.0f }, { 0.5f, 0.0f, 1.5f } },
{ { 1.0f, 0.0f, 1.5f }, { 0.5f, 0.0f, 1.5f }, { 0.5f, 1.8f, 1.5f }, { 1.0f, 1.8f, 1.5f } },
{ { 1.0f, 0.0f, 2.0f }, { 1.0f, 0.0f, 1.5f }, { 1.0f, 1.8f, 1.5f }, { 1.0f, 1.8f, 2.0f } },
{ { 0.5f, 0.0f, 2.0f }, { 0.5f, 0.0f, 1.5f }, { 0.5f, 1.8f, 1.5f }, { 0.5f, 1.8f, 2.0f } },
{ { 1.0f, 0.0f, 2.0f }, { 0.5f, 0.0f, 2.0f }, { 0.5f, 1.8f, 2.0f }, { 1.0f, 1.8f, 2.0f } },
{ { 1.0f, 1.8f, 1.5f }, { 1.0f, 1.8f, 2.0f }, { 0.5f, 1.8f, 2.0f }, { 0.5f, 1.8f, 1.5f } } };

GLfloat Table::B_LEFT[6][4][3] = { { { -0.5f, 0.0f, 0.0f }, { -0.5f, 0.0f, 0.5f }, { -1.0f, 0.0f, 0.5f }, { -1.0f, 0.0f, 0.0f } },
{ { -0.5f, 0.0f, 0.0f }, { -1.0f, 0.0f, 0.0f }, { -1.0f, 1.8f, 0.0f }, { -0.5f, 1.8f, 0.0f } },
{ { -0.5f, 0.0f, 0.5f }, { -0.5f, 0.0f, 0.0f }, { -0.5f, 1.8f, 0.0f }, { -0.5f, 1.8f, 0.5f } },
{ { -1.0f, 0.0f, 0.5f }, { -1.0f, 0.0f, 0.0f }, { -1.0f, 1.8f, 0.0f }, { -1.0f, 1.8f, 0.5f } },
{ { -0.5f, 0.0f, 0.5f }, { -1.0f, 0.0f, 0.5f }, { -1.0f, 1.8f, 0.5f }, { -0.5f, 1.8f, 0.5f } },
{ { -0.5f, 1.8f, 0.0f }, { -0.5f, 1.8f, 0.5f }, { -1.0f, 1.8f, 0.5f }, { -1.0f, 1.8f, 0.0f } } };

GLfloat Table::F_LEFT[6][4][3] = { { { -0.5f, 0.0f, 1.5f }, { -0.5f, 0.0f, 2.0f }, { -1.0f, 0.0f, 2.0f }, { -1.0f, 0.0f, 1.5f } },
{ { -0.5f, 0.0f, 1.5f }, { -1.0f, 0.0f, 1.5f }, { -1.0f, 1.8f, 1.5f }, { -0.5f, 1.8f, 1.5f } },
{ { -0.5f, 0.0f, 2.0f }, { -0.5f, 0.0f, 1.5f }, { -0.5f, 1.8f, 1.5f }, { -0.5f, 1.8f, 2.0f } },
{ { -1.0f, 0.0f, 2.0f }, { -1.0f, 0.0f, 1.5f }, { -1.0f, 1.8f, 1.5f }, { -1.0f, 1.8f, 2.0f } },
{ { -0.5f, 0.0f, 2.0f }, { -1.0f, 0.0f, 2.0f }, { -1.0f, 1.8f, 2.0f }, { -0.5f, 1.8f, 2.0f } },
{ { -0.5f, 1.8f, 1.5f }, { -0.5f, 1.8f, 2.0f }, { -1.0f, 1.8f, 2.0f }, { -1.0f, 1.8f, 1.5f } } };

// Calls table elements and saves the built table in a display list.
void Table::save(GLint index) {
	glNewList(index, GL_COMPILE);
	cuboid(B_LEFT, false);
	cuboid(B_RIGHT, false);
	cuboid(F_LEFT, false);
	cuboid(F_RIGHT, false);
	cuboid(TOP, true);
	glEndList();
}

// Makes cuboid.
void Table::cuboid(GLfloat const vertices[][4][3], bool top) {
	// Grab the appropriate colour.
	if (top)
		glColor3f(TOP_COLOUR[0], TOP_COLOUR[1], TOP_COLOUR[2]);
	else
		glColor3f(LEG_COLOUR[0], LEG_COLOUR[1], LEG_COLOUR[2]);

	// Goes through each of the six wall rectangles.
	for (int i = 0; i < 6; i++) {
		glBegin(GL_QUADS);

		// Goes through a rectangle's vertices.
		for (int j = 0; j < 4; j++)
			glVertex3f(vertices[i][j][0], vertices[i][j][1], vertices[i][j][2]);

		glEnd();
	}
}

