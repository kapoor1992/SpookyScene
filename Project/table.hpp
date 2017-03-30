// Dhruv Kapoor
// #3236690
// Project
// Generates a table and allows it to be saved as a display list.

#ifndef table_hpp
#define table_hpp

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Creates a table.
class Table {
public:
	// Colours needed for the table.
	static GLfloat LEG_COLOUR[3]; // Brown.
	static GLfloat TOP_COLOUR[3]; // Slightly deeper brown.

	// Table walls. Each wall is a cuboid (3D rectangle) made up of 6 rectangles.
	// Each row of each cuboid is in the order bottom, back, right, left, front, top.
	static GLfloat TOP[6][4][3];
	static GLfloat B_RIGHT[6][4][3];
	static GLfloat F_RIGHT[6][4][3];
	static GLfloat B_LEFT[6][4][3];
	static GLfloat F_LEFT[6][4][3];

	// Stores the table in a display list.
	void save(GLint index);

private:
	// Shape making function.
	void cuboid(GLfloat const vertices[][4][3], bool top);
};

#endif /* table_hpp */

