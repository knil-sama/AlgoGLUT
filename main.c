#include "contexte.h"
#include "draw.h"
int main(int argc,char **argv) {

  	// initialisation  des param�tres de GLUT en fonction
  	// des arguments sur la ligne de commande
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);

	// d�finition de la taille de la fen�tre et de sa position
	glutInitWindowSize(WIDTH, HEIGHT); 
	glutInitWindowPosition(POS_X, POS_Y); 

	// cr�ation de la fen�tre graphique en lui attribuant un titre
	glutCreateWindow("Drawing");


	// Initialisation d'openGl et de la Sc�ne
  	initGL();  
  	init_scene();
	
  	// D�finition des trois fcts de callback 

	// fct 1 = glutDisplayFunc est appel�e chaque fois que l'on doit redissener la fen�tre
  	glutDisplayFunc(&window_display);
 
	// fct 2 = glutReshapeFunc est appel�e chaque fois que l'on redimensionne la fen�tre
	glutReshapeFunc(&window_reshape);

	// fct 3= glutKeyboardFunc est appel�e chaque fois qu'une touche du clavier est press�
	glutKeyboardFunc(&window_key);

	// la boucle prinicipale de gestion des �v�nements utilisateur
  	glutMainLoop();
	
	// FIN
  	return(0);
}
