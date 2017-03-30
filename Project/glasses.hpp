// Dhruv Kapoor
// #3236690
// Project
// Generates glasses and allows them to be saved as a display list.

#ifndef glasses_hpp
#define glasses_hpp

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Creates glasses.
class Glasses {
public:
	// Colours needed for the glasses.
	static GLfloat GLASSES_COLOUR[3]; // Deep blue.
	static GLfloat LENS_COLOUR[3];    // Icy blue.

	// Ear hooks. Each hook is a reverse pyramid made up of 4 triangles.
	// Each row of each pyramid is in the order front, left, back, right.
	static GLfloat RIGHT_EAR[4][3][3];
	static GLfloat LEFT_EAR[4][3][3];

	// Glasses walls. Each wall is a cuboid (3D rectangle) made up of 6 rectangles.
	// Each row of each cuboid is in the order bottom, back, right, left, front, top.
	static GLfloat RIGHT_BAR[6][4][3];
	static GLfloat LEFT_BAR[6][4][3];
	static GLfloat RIGHT_FRAME[6][4][3];
	static GLfloat LEFT_FRAME[6][4][3];
	static GLfloat CONNECTOR[6][4][3];
	static GLfloat RIGHT_LENS[6][4][3];
	static GLfloat LEFT_LENS[6][4][3];

	// Stores the glasses in a display list.
	void save(GLint index);

private:
	// Shape making functions.
	void cuboid(GLfloat const vertices[][4][3], bool lens);
	void pyramid(GLfloat const vertices[][3][3]);
};

#endif /* glasses_hpp */
