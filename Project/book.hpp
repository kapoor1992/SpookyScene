// Dhruv Kapoor
// #3236690
// Project
// Generates a book and allows it to be saved as a display list.

#ifndef book_hpp
#define book_hpp

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Creates a book.
class Book {
public:
	// Colours needed for the book.
	static GLfloat LABEL_COLOUR[3]; // Yellowish orange.
	static GLfloat BOOK_COLOUR[3];  // Maroon.
	static GLfloat PAGE_COLOUR[3];  // Brown.

	// Label dimensions. It is simply a coloured rectangle sitting on top of the book.
	static GLfloat LABEL[4][3];

	// Book walls. Each wall is a cuboid (3D rectangle) made up of 6 rectangles.
	// Each row of each cuboid is in the order bottom, back, right, left, front, top.
	static GLfloat PAGES[6][4][3];
	static GLfloat SPINE[6][4][3];
	static GLfloat TOP[6][4][3];
	static GLfloat BOT[6][4][3];

	// Stores the book in a display list.
	void save(GLint index);

private:
	// Shape making functions.
	void cuboid(GLfloat const vertices[][4][3], bool pages);
	void rectangle(GLfloat const vertices[][3]);
};

#endif /* book_hpp */

