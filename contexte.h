#ifndef DEF_CONTEXTE
#define DEF_CONTEXTE

#include <stdio.h>
#include <stdlib.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

//Définition des Constantes 
#define WIDTH  640
#define HEIGHT 480
#define POS_X 0
#define POS_Y 0

#define KEY_ESC 27

void init_scene();
void render_scene();
GLvoid initGL();
GLvoid window_display();
GLvoid window_reshape(GLsizei width, GLsizei height); 
GLvoid window_key(unsigned char key, int x, int y); 

#endif