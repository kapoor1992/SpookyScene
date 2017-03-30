// Dhruv Kapoor
// #3236690
// Project
// Generates a book and allows it to be saved as a display list.

#include "book.hpp"

GLfloat Book::LABEL_COLOUR[3] = { 1.0f, 0.647f, 0.0f };
GLfloat Book::BOOK_COLOUR[3] = { 0.702f, 0.0f, 0.0f };
GLfloat Book::PAGE_COLOUR[3] = { 0.702f, 0.384f, 0.0f };

GLfloat Book::LABEL[4][3] = { { 0.2f, 0.8f, 0.2f },
{ 0.2f, 0.8f, 0.8f },
{ 0.8f, 0.8f, 0.8f },
{ 0.8f, 0.8f, 0.2f } };

GLfloat Book::PAGES[6][4][3] = { { { 0.2f, 0.2f, 0.0f }, { 0.2f, 0.2f, 2.0f }, { 0.9f, 0.2f, 2.0f }, { 0.9f, 0.2f, 0.0f } },
{ { 0.2f, 0.2f, 0.0f }, { 0.9f, 0.2f, 0.0f }, { 0.9f, 0.6f, 0.0f }, { 0.2f, 0.6f, 0.0f } },
{ { 0.9f, 0.2f, 2.0f }, { 0.9f, 0.2f, 0.0f }, { 0.9f, 0.6f, 0.0f }, { 0.9f, 0.6f, 2.0f } },
{ { 0.2f, 0.2f, 2.0f }, { 0.2f, 0.2f, 0.0f }, { 0.2f, 0.6f, 0.0f }, { 0.2f, 0.6f, 2.0f } },
{ { 0.2f, 0.2f, 2.0f }, { 0.9f, 0.2f, 2.0f }, { 0.9f, 0.6f, 2.0f }, { 0.2f, 0.6f, 2.0f } },
{ { 0.2f, 0.6f, 0.0f }, { 0.2f, 0.6f, 2.0f }, { 0.9f, 0.6f, 2.0f }, { 0.9f, 0.6f, 0.0f } } };

GLfloat Book::SPINE[6][4][3] = { { { 0.2f, 0.2f, 0.0f }, { 0.2f, 0.2f, 2.0f }, { 0.0f, 0.2f, 2.0f }, { 0.0f, 0.2f, 0.0f } },
{ { 0.2f, 0.2f, 0.0f }, { 0.0f, 0.2f, 0.0f }, { 0.0f, 0.6f, 0.0f }, { 0.2f, 0.6f, 0.0f } },
{ { 0.2f, 0.2f, 2.0f }, { 0.2f, 0.2f, 0.0f }, { 0.2f, 0.6f, 0.0f }, { 0.2f, 0.6f, 2.0f } },
{ { 0.0f, 0.2f, 2.0f }, { 0.0f, 0.2f, 0.0f }, { 0.0f, 0.6f, 0.0f }, { 0.0f, 0.6f, 2.0f } },
{ { 0.2f, 0.2f, 2.0f }, { 0.0f, 0.2f, 2.0f }, { 0.0f, 0.6f, 2.0f }, { 0.2f, 0.6f, 2.0f } },
{ { 0.2f, 0.6f, 0.0f }, { 0.2f, 0.6f, 2.0f }, { 0.0f, 0.6f, 2.0f }, { 0.0f, 0.6f, 0.0f } } };

GLfloat Book::TOP[6][4][3] = { { { 1.0f, 0.6f, 0.0f }, { 1.0f, 0.6f, 2.0f }, { 0.0f, 0.6f, 2.0f }, { 0.0f, 0.6f, 0.0f } },
{ { 1.0f, 0.6f, 0.0f }, { 0.0f, 0.6f, 0.0f }, { 0.0f, 0.8f, 0.0f }, { 1.0f, 0.8f, 0.0f } },
{ { 1.0f, 0.6f, 2.0f }, { 1.0f, 0.6f, 0.0f }, { 1.0f, 0.8f, 0.0f }, { 1.0f, 0.8f, 2.0f } },
{ { 0.0f, 0.6f, 2.0f }, { 0.0f, 0.6f, 0.0f }, { 0.0f, 0.8f, 0.0f }, { 0.0f, 0.8f, 2.0f } },
{ { 1.0f, 0.6f, 2.0f }, { 0.0f, 0.6f, 2.0f }, { 0.0f, 0.8f, 2.0f }, { 1.0f, 0.8f, 2.0f } },
{ { 1.0f, 0.8f, 0.0f }, { 1.0f, 0.8f, 2.0f }, { 0.0f, 0.8f, 2.0f }, { 0.0f, 0.8f, 0.0f } } };

GLfloat Book::BOT[6][4][3] = { { { 1.0f, 0.0f, 0.0f }, { 1.0f, 0.0f, 2.0f }, { 0.0f, 0.0f, 2.0f }, { 0.0f, 0.0f, 0.0f } },
{ { 1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.2f, 0.0f }, { 1.0f, 0.2f, 0.0f } },
{ { 1.0f, 0.0f, 2.0f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 0.2f, 0.0f }, { 1.0f, 0.2f, 2.0f } },
{ { 0.0f, 0.0f, 2.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.2f, 0.0f }, { 0.0f, 0.2f, 2.0f } },
{ { 1.0f, 0.0f, 2.0f }, { 0.0f, 0.0f, 2.0f }, { 0.0f, 0.2f, 2.0f }, { 1.0f, 0.2f, 2.0f } },
{ { 1.0f, 0.2f, 0.0f }, { 1.0f, 0.2f, 2.0f }, { 0.0f, 0.2f, 2.0f }, { 0.0f, 0.2f, 0.0f } } };

// Calls mug elements and saves the built mug in a display list.
void Book::save(GLint index) {
	glNewList(index, GL_COMPILE);
	cuboid(BOT, false);
	cuboid(PAGES, true);
	cuboid(SPINE, false);
	cuboid(TOP, false);
	rectangle(LABEL);
	glEndList();
}

// Makes cuboid.
void Book::cuboid(GLfloat const vertices[][4][3], bool pages) {
	// Grab the appropriate colour.
	if (pages)
		glColor3f(PAGE_COLOUR[0], PAGE_COLOUR[1], PAGE_COLOUR[2]);
	else
		glColor3f(BOOK_COLOUR[0], BOOK_COLOUR[1], BOOK_COLOUR[2]);

	// Goes through each of the six wall rectangles.
	for (int i = 0; i < 6; i++) {
		glBegin(GL_QUADS);

		// Goes through a rectangle's vertices.
		for (int j = 0; j < 4; j++)
			glVertex3f(vertices[i][j][0], vertices[i][j][1], vertices[i][j][2]);

		glEnd();
	}
}

// Makes the label.
void Book::rectangle(GLfloat const vertices[][3]) {
	glColor3f(LABEL_COLOUR[0], LABEL_COLOUR[1], LABEL_COLOUR[2]);

	glBegin(GL_QUADS);

	// Goes through each of the label's vertices.
	for (int i = 0; i < 4; i++)
		glVertex3f(vertices[i][0], vertices[i][1], vertices[i][2]);

	glEnd();
}
