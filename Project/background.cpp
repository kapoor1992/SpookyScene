// Dhruv Kapoor
// #3236690
// Project
// Library used for the background.
// BMP loader is used from section 9.1.2.

#include "background.hpp"

// Background loading variables.
GLubyte *image;
GLubyte * l_texture;
BITMAPFILEHEADER fileheader;
BITMAPINFOHEADER infoheader;
RGBTRIPLE rgb;
GLuint texName;

// From 9.1.2 example of loading a BMP file.
void makeImage() {
	int i, j = 0;
	FILE *l_file;
	string fn = "background.bmp";

	const char * filename = fn.c_str();

	// open image file, return if error
	fopen_s(&l_file, filename, "rb");

	if (l_file == NULL)
		return;

	// read file header and header info
	fread(&fileheader, sizeof(fileheader), 1, l_file);
	fseek(l_file, sizeof(fileheader), SEEK_SET);
	fread(&infoheader, sizeof(infoheader), 1, l_file);

	// allocate space for the image file
	l_texture = (GLubyte *)malloc(infoheader.biWidth * infoheader.biHeight * 4);
	memset(l_texture, 0, infoheader.biWidth * infoheader.biHeight * 4);

	// read da data
	j = 0;

	for (i = 0; i < infoheader.biWidth*infoheader.biHeight; i++) {
		fread(&rgb, sizeof(rgb), 1, l_file);

		l_texture[j + 0] = (GLubyte)rgb.rgbtRed; // Red component
		l_texture[j + 1] = (GLubyte)rgb.rgbtGreen; // Green component
		l_texture[j + 2] = (GLubyte)rgb.rgbtBlue; // Blue component
		l_texture[j + 3] = (GLubyte)255; // Alpha value
		j += 4; // Go to the next position
	}

	fclose(l_file); // Closes the file stream
}

// Image processor takes lighting into account.
void processImage() {
	makeImage();
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glGenTextures(1, &texName);
	glBindTexture(GL_TEXTURE_2D, texName);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, infoheader.biWidth, infoheader.biHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);
	glEnable(GL_TEXTURE_2D);
}
