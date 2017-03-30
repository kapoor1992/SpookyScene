// Dhruv Kapoor
// #3236690
// Project
// Generates a mug and allows it to be saved as a display list.

#include "mug.hpp"

GLfloat Mug::LIQUID_COLOUR[3] = { 0.435f, 0.306f, 0.216f };
GLfloat Mug::MUG_COLOUR[3] = { 0.0f, 0.2f, 0.0f };
GLfloat Mug::HANDLE_COLOUR[3] = { 0.0f, 0.0f, 0.0f };

GLfloat Mug::LIQUID[4][3] = { { -0.75f, 1.75f, 0.75f },
{ -0.75f, 1.75f, 1.75f },
{ 0.75f, 1.75f, 1.75f },
{ 0.75f, 1.75f, 0.75f } };

GLfloat Mug::BOT[4][3] = { { -1.0f, 0.0f, 0.0f },
{ -1.0f, 0.0f, 2.0f },
{ 1.0f, 0.0f, 2.0f },
{ 1.0f, 0.0f, 0.0f } };

GLfloat Mug::RIGHT[6][4][3] = { { { 0.75f, 0.0f, 0.0f }, { 0.75f, 0.0f, 2.0f }, { 1.0f, 0.0f, 2.0f }, { 1.0f, 0.0f, 0.0f } },
{ { 0.75f, 0.0f, 0.0f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 2.0f, 0.0f }, { 0.75f, 2.0f, 0.0f } },
{ { 1.0f, 0.0f, 2.0f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 2.0f, 0.0f }, { 1.0f, 2.0f, 2.0f } },
{ { 0.75f, 0.0f, 0.0f }, { 0.75f, 2.0f, 0.0f }, { 0.75f, 2.0f, 2.0f }, { 0.75f, 0.0f, 2.0f } },
{ { 0.75f, 0.0f, 2.0f }, { 1.0f, 0.0f, 2.0f }, { 1.0f, 2.0f, 2.0f }, { 0.75f, 2.0f, 2.0f } },
{ { 1.0f, 2.0f, 2.0f }, { 1.0f, 2.0f, 0.0f }, { 0.75f, 2.0f, 0.0f }, { 0.75f, 2.0f, 2.0f } } };

GLfloat Mug::LEFT[6][4][3] = { { { -0.75f, 0.0f, 0.0f }, { -0.75f, 0.0f, 2.0f }, { -1.0f, 0.0f, 2.0f }, { -1.0f, 0.0f, 0.0f } },
{ { -0.75f, 0.0f, 0.0f }, { -1.0f, 0.0f, 0.0f }, { -1.0f, 2.0f, 0.0f }, { -0.75f, 2.0f, 0.0f } },
{ { -1.0f, 0.0f, 2.0f }, { -1.0f, 0.0f, 0.0f }, { -1.0f, 2.0f, 0.0f }, { -1.0f, 2.0f, 2.0f } },
{ { -0.75f, 0.0f, 0.0f }, { -0.75f, 2.0f, 0.0f }, { -0.75f, 2.0f, 2.0f }, { -0.75f, 0.0f, 2.0f } },
{ { -0.75f, 0.0f, 2.0f }, { -1.0f, 0.0f, 2.0f }, { -1.0f, 2.0f, 2.0f }, { -0.75f, 2.0f, 2.0f } },
{ { -1.0f, 2.0f, 2.0f }, { -1.0f, 2.0f, 0.0f }, { -0.75f, 2.0f, 0.0f }, { -0.75f, 2.0f, 2.0f } } };

GLfloat Mug::BACK[6][4][3] = { { { 1.0f, 0.0f, 0.0f }, { 1.0f, 0.0f, 0.25f }, { -1.0f, 0.0f, 0.25f }, { -1.0f, 0.0f, 0.0f } },
{ { 1.0f, 0.0f, 0.0f }, { -1.0f, 0.0f, 0.0f }, { -1.0f, 2.0f, 0.0f }, { 1.0f, 2.0f, 0.0f } },
{ { 1.0f, 0.0f, 0.25f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 2.0f, 0.0f }, { 1.0f, 2.0f, 0.25f } },
{ { -1.0f, 0.0f, 0.25f }, { -1.0f, 0.0f, 0.0f }, { -1.0f, 2.0f, 0.0f }, { -1.0f, 2.0f, 0.25f } },
{ { 1.0f, 0.0f, 0.25f }, { -1.0f, 0.0f, 0.25f }, { -1.0f, 2.0f, 0.25f }, { 1.0f, 2.0f, 0.25f } },
{ { 1.0f, 2.0f, 0.0f }, { 1.0f, 2.0f, 0.25f }, { -1.0f, 2.0f, 0.25f }, { -1.0f, 2.0f, 0.0f } } };

GLfloat Mug::FRONT[6][4][3] = { { { 1.0f, 0.0f, 1.75f }, { 1.0f, 0.0f, 2.0f }, { -1.0f, 0.0f, 2.0f }, { -1.0f, 0.0f, 1.75f } },
{ { 1.0f, 0.0f, 1.75f }, { -1.0f, 0.0f, 1.75f }, { -1.0f, 2.0f, 1.75f }, { 1.0f, 2.0f, 1.75f } },
{ { 1.0f, 0.0f, 2.0f }, { 1.0f, 0.0f, 1.75f }, { 1.0f, 2.0f, 1.75f }, { 1.0f, 2.0f, 2.0f } },
{ { -1.0f, 0.0f, 2.0f }, { -1.0f, 0.0f, 1.75f }, { -1.0f, 2.0f, 1.75f }, { -1.0f, 2.0f, 2.0f } },
{ { 1.0f, 0.0f, 2.0f }, { -1.0f, 0.0f, 2.0f }, { -1.0f, 2.0f, 2.0f }, { 1.0f, 2.0f, 2.0f } },
{ { 1.0f, 2.0f, 1.75f }, { 1.0f, 2.0f, 2.0f }, { -1.0f, 2.0f, 2.0f }, { -1.0f, 2.0f, 1.75f } } };

GLfloat Mug::H_TOP[6][4][3] = { { { 1.0f, 1.5f, 0.75f }, { 1.0f, 1.5f, 1.25f }, { 1.5f, 1.5f, 1.25f }, { 1.5f, 1.5f, 0.75f } },
{ { 1.0f, 1.5f, 0.75f }, { 1.5f, 1.5f, 0.75f }, { 1.5f, 1.75f, 0.75f }, { 1.0f, 1.75f, 0.75f } },
{ { 1.0f, 1.5f, 0.75f }, { 1.0f, 1.75f, 0.75f }, { 1.0f, 1.75f, 1.25f }, { 1.0f, 1.5f, 1.25f } },
{ { 1.5f, 1.5f, 0.75f }, { 1.5f, 1.75f, 0.75f }, { 1.5f, 1.75f, 1.25f }, { 1.5f, 1.5f, 1.25f } },
{ { 1.0f, 1.5f, 1.25f }, { 1.5f, 1.5f, 1.25f }, { 1.5f, 1.75f, 1.25f }, { 1.0f, 1.75f, 1.25f } },
{ { 1.0f, 1.75f, 0.75f }, { 1.0f, 1.75f, 1.25f }, { 1.5f, 1.75f, 1.25f }, { 1.5f, 1.75f, 0.75f } } };

GLfloat Mug::H_BOT[6][4][3] = { { { 1.0f, 0.25f, 0.75f }, { 1.0f, 0.25f, 1.25f }, { 1.5f, 0.25f, 1.25f }, { 1.5f, 0.25f, 0.75f } },
{ { 1.0f, 0.25f, 0.75f }, { 1.5f, 0.25f, 0.75f }, { 1.5f, 0.5f, 0.75f }, { 1.0f, 0.5f, 0.75f } },
{ { 1.0f, 0.25f, 0.75f }, { 1.0f, 0.25f, 0.75f }, { 1.0f, 0.5f, 1.25f }, { 1.0f, 0.25f, 1.25f } },
{ { 1.5f, 0.25f, 0.75f }, { 1.5f, 0.5f, 0.75f }, { 1.5f, 0.5f, 1.25f }, { 1.5f, 0.25f, 1.25f } },
{ { 1.0f, 0.25f, 1.25f }, { 1.5f, 0.25f, 1.25f }, { 1.5f, 0.5f, 1.25f }, { 1.0f, 0.5f, 1.25f } },
{ { 1.0f, 0.5f, 0.75f }, { 1.0f, 0.5f, 1.25f }, { 1.5f, 0.5f, 1.25f }, { 1.5f, 0.5f, 0.75f } } };

GLfloat Mug::H_VERT[6][4][3] = { { { 1.25f, 0.25f, 0.75f }, { 1.25f, 0.25f, 1.25f }, { 1.5f, 0.25f, 1.25f }, { 1.5f, 0.25f, 0.75f } },
{ { 1.25f, 0.25f, 0.75f }, { 1.5f, 0.25f, 0.75f }, { 1.5f, 1.75f, 0.75f }, { 1.25f, 1.75f, 0.75f } },
{ { 1.25f, 0.25f, 0.75f }, { 1.25f, 0.25f, 0.75f }, { 1.25f, 1.75f, 1.25f }, { 1.25f, 0.25f, 1.25f } },
{ { 1.5f, 0.25f, 0.75f }, { 1.5f, 1.75f, 0.75f }, { 1.5f, 1.75f, 1.25f }, { 1.5f, 0.25f, 1.25f } },
{ { 1.25f, 0.25f, 1.25f }, { 1.5f, 0.25f, 1.25f }, { 1.5f, 1.75f, 1.25f }, { 1.25f, 1.75f, 1.25f } },
{ { 1.25f, 1.75f, 0.75f }, { 1.25f, 1.75f, 1.25f }, { 1.5f, 1.75f, 1.25f }, { 1.5f, 1.75f, 0.75f } } };

// Calls mug elements and saves the built mug in a display list.
void Mug::save(GLint index) {
	glNewList(index, GL_COMPILE);
	cuboid(RIGHT, false);
	cuboid(BACK, false);
	rectangle(BOT, false);
	cuboid(H_TOP, true);
	cuboid(H_BOT, true);
	cuboid(H_VERT, true);
	cuboid(LEFT, false);
	rectangle(LIQUID, true);
	cuboid(FRONT, false);
	glEndList();
}

// Makes cuboid.
void Mug::cuboid(GLfloat const vertices[][4][3], bool handle) {
	// Grab the appropriate colour.
	if (handle)
		glColor3f(HANDLE_COLOUR[0], HANDLE_COLOUR[1], HANDLE_COLOUR[2]);
	else
		glColor3f(MUG_COLOUR[0], MUG_COLOUR[1], MUG_COLOUR[2]);

	// Goes through each of the six wall rectangles.
	for (int i = 0; i < 6; i++) {
		glBegin(GL_QUADS);

		// Goes through a rectangle's vertices.
		for (int j = 0; j < 4; j++)
			glVertex3f(vertices[i][j][0], vertices[i][j][1], vertices[i][j][2]);

		glEnd();
	}
}

// Makes the mug bottom and liquid.
void Mug::rectangle(GLfloat const vertices[][3], bool liquid) {
	// Grab the appropriate colour.
	if (liquid)
		glColor3f(LIQUID_COLOUR[0], LIQUID_COLOUR[1], LIQUID_COLOUR[2]);
	else
		glColor3f(MUG_COLOUR[0], MUG_COLOUR[1], MUG_COLOUR[2]);

	glBegin(GL_QUADS);

	// Goes through each of the rectangle's vertices.
	for (int i = 0; i < 4; i++)
		glVertex3f(vertices[i][0], vertices[i][1], vertices[i][2]);

	glEnd();
}
