#include "contexte.h"
#include "draw.h"
int main(int argc,char **argv) {

  	// initialisation  des paramètres de GLUT en fonction
  	// des arguments sur la ligne de commande
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);

	// définition de la taille de la fenêtre et de sa position
	glutInitWindowSize(WIDTH, HEIGHT); 
	glutInitWindowPosition(POS_X, POS_Y); 

	// création de la fenêtre graphique en lui attribuant un titre
	glutCreateWindow("Drawing");


	// Initialisation d'openGl et de la Scène
  	initGL();  
  	init_scene();
	
  	// Définition des trois fcts de callback 

	// fct 1 = glutDisplayFunc est appelée chaque fois que l'on doit redissener la fenêtre
  	glutDisplayFunc(&window_display);
 
	// fct 2 = glutReshapeFunc est appelée chaque fois que l'on redimensionne la fenêtre
	glutReshapeFunc(&window_reshape);

	// fct 3= glutKeyboardFunc est appelée chaque fois qu'une touche du clavier est pressé
	glutKeyboardFunc(&window_key);

	// la boucle prinicipale de gestion des événements utilisateur
  	glutMainLoop();
	
	// FIN
  	return(0);
}
