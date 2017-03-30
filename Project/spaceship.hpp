// Dhruv Kapoor
// #3236690
// Project
// Generates a spacehip and allows it to be saved as a display list.

#ifndef spaceship_hpp
#define spaceship_hpp

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Creates spaceship.
class Spaceship {
public:
	// Colours needed for the spaceship.
	static GLfloat BASE_COLOUR[3];    // Grey.
	static GLfloat PYRAMID_COLOUR[3]; // Red.

	// Ship top. A pyramid made up of 4 triangles.
	// Each row is in the order front, left, back, right.
	static GLfloat TOP[4][3][3];

	// Ship wings. Each wing is a pyramid made up of 3 triangles.
	// Each row of each wing is in the order bottom, left, right (from the tip).
	static GLfloat RIGHT_WING[3][3][3];
	static GLfloat BACK_WING[3][3][3];
	static GLfloat LEFT_WING[3][3][3];
	static GLfloat FRONT_WING[3][3][3];

	// Ship walls. A cuboid (3D rectangle) made up of 6 rectangles.
	// Each row is in the order bottom, back, right, left, front, top.
	static GLfloat BASE[6][4][3];

	// Stores the ship in a display list.
	void save(GLint index);

private:
	// Shape making functions.
	void cuboid(GLfloat const vertices[][4][3]);
	void pyramid(GLfloat const vertices[][3][3], bool wing);
};

#endif /* spaceship_hpp */
