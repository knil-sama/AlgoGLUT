#include "contexte.h"
#include "draw.h"
// initialisation du fond de la fenêtre graphique : couleur noir opaque 
GLvoid initGL(void){
	glClearColor(0, 0, 0, 1);        
}

void init_scene(void){
}

// le tracé graphique (le Carré blanc)
// Consiste à définir une couleur(le blanc) et une forme (carré)
void render_scene(void){

	float colorseg[3] = {0.7,0.0,0.5};
	float colorcircle[3] = {0.0,0.7,0.3};
	bresenhamG(0,0,640,480,colorseg);
	traceCercle(400,400,100,colorcircle);
}

// fonction de call-back pour l'affichage dans la fenêtre
GLvoid window_display(void){
	
	// a l'initialisation, on définit la couleur du fond qui sera utilisée 
	// lorsqu'on effacera le fond par glClear
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	render_scene();

	// trace la scène grapnique qui vient juste d'être définie
	glFlush();
}

// fonction de call-back pour le redimensionnement de la fenêtre
GLvoid window_reshape(GLsizei width, GLsizei height){  

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 640, 480, 0, 0, 640);

	// toutes les transformations suivantes s 'appliquent au modèle de vue 
	glMatrixMode(GL_MODELVIEW);
}

// fonction de call-back pour la gestion des événements clavier
GLvoid window_key(unsigned char key, int x, int y){  

	switch (key) {    
		case KEY_ESC:  exit(1);                    
    				break;  
		default: printf ("La touche %d n ' est pas active.\n", key);
			 break;
  	}     
}