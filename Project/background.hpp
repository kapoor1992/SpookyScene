// Dhruv Kapoor
// #3236690
// Project
// Library used for the background.
// BMP loader is used from section 9.1.2.

#ifndef background_hpp
#define background_hpp

#include "windows.h"
#include "math.h"
#include <iostream>
#include <fstream>
#include <string>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

// From 9.1.2 example of loading a BMP file.
void makeImage();

// Processes image.
void processImage();

#endif /* background_hpp */
