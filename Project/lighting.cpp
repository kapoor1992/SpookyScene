// Dhruv Kapoor
// #3236690
// Project
// Library used for lighting effects.

#include "lighting.hpp"

// Lights are initially off.
void initLighting() {
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH);

	glEnable(GL_LIGHTING);

	// The lamp is quite dim (it attenuates linearly).
	glLightfv(GL_LIGHT0, GL_POSITION, lamp_position);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.05f);

	// Sunlight does not attenuate locally.
	glLightfv(GL_LIGHT1, GL_POSITION, window_position);
}

// Sets lamp.
void lampOption(GLint option) {
	glEnable(GL_LIGHT0);

	switch (option) {
	case 1: glLightfv(GL_LIGHT0, GL_DIFFUSE, red_light);
		glLightfv(GL_LIGHT0, GL_SPECULAR, red_light);
		break;
	case 2: glLightfv(GL_LIGHT0, GL_DIFFUSE, green_light);
		glLightfv(GL_LIGHT0, GL_SPECULAR, green_light);
		break;
	case 3: glLightfv(GL_LIGHT0, GL_DIFFUSE, blue_light);
		glLightfv(GL_LIGHT0, GL_SPECULAR, blue_light);
		break;
	case 4: glDisable(GL_LIGHT0);
		break;
	}

	glutPostRedisplay();
}

// Sets sunlight.
void sunOption(GLint option) {
	glEnable(GL_LIGHT1);

	switch (option) {
	case 1: glLightfv(GL_LIGHT1, GL_DIFFUSE, noon_light);
		glLightfv(GL_LIGHT1, GL_SPECULAR, noon_light);
		break;
	case 2: glLightfv(GL_LIGHT1, GL_DIFFUSE, evening_light);
		glLightfv(GL_LIGHT1, GL_SPECULAR, evening_light);
		break;
	case 3: glDisable(GL_LIGHT1);
		break;
	}

	glutPostRedisplay();
}

// Only button on main menu is used for exiting.
void mainMenu(GLint option) {
	exit(0);
}

void makeMenu() {
	// Lamp submenu.
	GLint lamp = glutCreateMenu(lampOption);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	glutAddMenuEntry("Off", 4);

	// Sunlight submenu.
	GLint sun = glutCreateMenu(sunOption);
	glutAddMenuEntry("Noon", 1);
	glutAddMenuEntry("Evening", 2);
	glutAddMenuEntry("Nighttime", 3);

	// Main menu.
	glutCreateMenu(mainMenu);
	glutAddSubMenu("Lamp", lamp);
	glutAddSubMenu("Time of Day", sun);
	glutAddMenuEntry("Quit", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
