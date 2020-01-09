#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include <time.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "ESLib.h" // Pour utiliser valeurAleatoire()
#include "m_joueur.h"
#include "m_pion.h"
#include "m_plateau.h"

#include "v_plateau.h"
#include "v_menu.h"
#include "p_lecture.h"
#include "p_ecriture.h"
#include "gestion_evenement.h"
#include "data.h"
// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LARGEUR_FENETRE 850
#define HAUTEUR_FENETRE 600




int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	prepareFenetreGraphique("Ladies And GentleDames", LARGEUR_FENETRE, HAUTEUR_FENETRE);
	srand(time(NULL)); // Changement de la valeur de la graine du générateur de nb aléatoire
	lanceBoucleEvenements(); //lance le jeu via le controleur
	return 0;
}










