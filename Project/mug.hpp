// Dhruv Kapoor
// #3236690
// Project
// Generates a mug and allows it to be saved as a display list.

#ifndef mug_hpp
#define mug_hpp

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Creates a mug.
class Mug {
public:
	// Colours needed for the mug.
	static GLfloat LIQUID_COLOUR[3]; // Coffee colour.
	static GLfloat MUG_COLOUR[3];    // Dark green.
	static GLfloat HANDLE_COLOUR[3]; // Black.

	// Liquid dimensions. It is simply a coloured rectangle sitting in the mug.
	static GLfloat LIQUID[4][3];

	// Mug walls. Each wall is a cuboid (3D rectangle) made up of 6 rectangles except for the bottom, which is a single rectangle.
	// Each row of each cuboid is in the order bottom, back, right, left, front, top.
	static GLfloat BOT[4][3];
	static GLfloat RIGHT[6][4][3];
	static GLfloat LEFT[6][4][3];
	static GLfloat BACK[6][4][3];
	static GLfloat FRONT[6][4][3];

	// Mug handle walls. Each are also cuboids and in the same order as the mug walls.
	static GLfloat H_TOP[6][4][3];
	static GLfloat H_BOT[6][4][3];
	static GLfloat H_VERT[6][4][3];

	// Stores the mug in a display list.
	void save(GLint index);

private:
	// Shape making functions.
	void cuboid(GLfloat const vertices[][4][3], bool handle);
	void rectangle(GLfloat const vertices[][3], bool liquid);
};

#endif /* mug_hpp */
