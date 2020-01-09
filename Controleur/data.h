#ifndef DATA_H
#define DATA_H

#include <stdlib.h>
#include <stdio.h> 
#include <math.h> 
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
#include "p_lecture.h"
#include "m_joueur.h"
#include "m_pion.h"
#include "m_plateau.h"

#include "v_plateau.h"
#include "v_menu.h"
#include "p_ecriture.h"
#include "gestion_evenement.h"


#define MAX_PION 40 
#define TAILLE_CASE 60
#define NB_CASES 10


typedef struct Data Data;

struct Data {

	/* structures */
	
	struct Pion ** pions; 
	struct Joueur** joueurs;
	struct Skin ** skins;

	
	char lettreCourante;
	char lettreCouranteJ2;
	char t1;
	char t2;
	char t3;
	char t4;
	char t5;
	char t6;
	char t7;
	char t8;
	int nbPions_joueur1;
	int nbPions_joueur2;
	char text_choix[32];
	char nomComplet[32];
	char nomCompletJ2[32];
	char nomMap[32];
	char nomPartie[32];


	/* entiers, long et flottants */

	int tab[NB_CASES][NB_CASES];	
	int partie[NB_CASES][NB_CASES];
	int pions_dans_plateau;

	int joueur_crees;
	int chrono_partie;
	int tempscourant;

	int latence;
	int indice_pion_1;
	int indice_pion_2;





 	float mini_chrono;


	/* booléens */

	bool plateau_initialise;
	bool choix;
	bool menu;
	bool lancerJeu;
	bool jouer;
	bool quitter;
	int pion_increment_id;
	
	bool lancer;
	bool regle_jeu;
	bool menu_principal;

	bool choix_pion_2;
	bool choix_pion_1;
	bool choix_pion;
	
	bool timeron;
	bool fin_partie_loose;
	bool fin_partie_win;
	bool choix_map;

	bool fin_partie_multi1;
	bool fin_partie_multi2;

	bool pion0;
	bool pion1;
	
	bool choix_pseudoJ2;
	bool toucheEntree;
	bool toucheAppuyee;

	/* images  */

DonneesImageRGB *fond_menu;
	DonneesImageRGB *fond_vide;
	DonneesImageRGB *fond_bouton;
	DonneesImageRGB *pion_noir_skin ;
	DonneesImageRGB *pion_blanc_skin ;
	DonneesImageRGB *pion_noir;
	DonneesImageRGB *pion_blanc;
	DonneesImageRGB *temps;
	
	DonneesImageRGB *bonus2;
	DonneesImageRGB *mort;
	DonneesImageRGB *bouton_retour;

	DonneesImageRGB *img_regles;
	DonneesImageRGB *fond_blanc;

	DonneesImageRGB *fond_noir;
	DonneesImageRGB *bombe;
	
};


/**

* \fn Data * initialisation_des_donnees ()

* \brief Fonction où les données stockées dans la structure Data sont initiliasiées


* \return donnees, un pointeur de type Data contenant les variables initialisées de la structure Data

*/

Data * initialisation_des_donnees ();
#endif
