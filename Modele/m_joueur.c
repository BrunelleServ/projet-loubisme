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
#include "data.h"
#include "m_joueur.h"
#include "m_pion.h"
#include "m_plateau.h"

#include "v_plateau.h"
#include "v_menu.h"
#include "p_lecture.h"
#include "p_ecriture.h"
#include "gestion_evenement.h"



// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LARGEUR_FENETRE 850
#define HAUTEUR_FENETRE 600
#define TAILLE_CASE 60
#define NB_CASES 10
#define ID_PION_1 2
#define ID_PION_2 3
#define ID_SOL_NOIR 0
#define ID_SOL_BLANC 1
#define ID_JOUEUR_1 4
#define ID_JOUEUR_2 5


#define TEMPO_MILLIS 20
#define TEMPO_SECS 0.025
#define NOMBRE_SKINS 2



/** -----------------------------------------------------------
 *                PARTIE JOUEUR 
 *  -----------------------------------------------------------
 */

/**
 *   Constructeur d'un nouveau joueur
 */

Joueur * nouveau_joueur (Data * donnees, int id, char pseudo [32], bool est_joueur,int skin_index) {
	Joueur * joueur = NULL;
	joueur = (Joueur *) malloc(sizeof(Joueur));
	if (joueur == NULL)
		return NULL;
	joueur->id = id;
	strcpy(joueur->pseudo,pseudo);
	
		joueur->skin_nmb = skin_index;

	
	joueur->skins = donnees->skins[skin_index];// association du skin au personnage

	joueur->est_joueur = est_joueur;
		
	joueur->perso_tenue_courante = joueur->skins->perso_tenue;

	
	++donnees->joueur_crees;
	return joueur;
}


/**
 *   Constructeur d'une nouvelle tenue pour un joueur
 */

Skin * nouveau_skin(char t_pion [256],  char t_dame [256],char t_tenue [256]) {
	Skin * skin = NULL;
	skin = (Skin *) malloc(sizeof(Skin));
	if (skin == NULL)
		return NULL;

	skin->skin_pion = lisBMPRGB(t_pion);
	skin->skin_dame = lisBMPRGB(t_dame);
	skin->perso_tenue = lisBMPRGB(t_tenue);
	
	return skin;
}

void init_skins (Data * donnees) {
	donnees->skins[1] = nouveau_skin ("images/pion_blanc.bmp", "images/dame_blanche.bmp","images/perso_tenue_1.bmp");
	donnees->skins[0] = nouveau_skin ("images/pion_noir.bmp", "images/dame_noir.bmp","images/perso_tenue_2.bmp");
	
}



int get_indice_skins(Data * donnees, Joueur * a) {
	for (int i = 0; i < NOMBRE_SKINS; ++i)
	{
		if (a->skins->skin_pion == donnees->skins[i]->skin_pion){
			printf("tenue : %d\n", i);
			return i;
		}
	}
	return 9;
}


int nb_joueurs (Data * donnees) {
	int cpt = 0;
	for (int i = 0; i < donnees->joueur_crees; ++i)
	{
		if (donnees->joueurs[i]->est_joueur) ++cpt;
	}
	return cpt;
}



