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
#include "data.h"
#include "m_joueur.h"
#include "m_pion.h"
#include "m_plateau.h"

#include "v_plateau.h"
#include "v_menu.h"
#include "p_ecriture.h"
#include "gestion_evenement.h"




#define NOMBRE_JOUEUR 2
#define CHRONO 500
#define NOMBRE_SKIN 2

#define MAX_PIONS 40


Data * initialisation_des_donnees () {

	Data * donnees = (Data *) malloc(sizeof(Data));
	donnees->joueurs = (Joueur **) malloc(NOMBRE_JOUEUR  * sizeof(Joueur *));
	donnees->pions = (Pion **) malloc(MAX_PIONS  * sizeof(Pion *));
	donnees->skins = (Skin **) malloc(NOMBRE_SKIN * sizeof(Skin *)); 
	donnees->pions_dans_plateau = 0;
	
	donnees->joueur_crees = 0;
	donnees->chrono_partie = CHRONO;
	donnees->tempscourant = CHRONO;
	donnees->mini_chrono = 0;
	donnees->fond_blanc = lisBMPRGB("images/fond_1.bmp");
	
	donnees->fond_noir = lisBMPRGB("images/fond_2.bmp");

	

	donnees->plateau_initialise = false;
	
	donnees->timeron=true;
	donnees->fin_partie_loose=false;
	donnees->fin_partie_win =false;
	
	donnees->fin_partie_multi1 =false;
	donnees->fin_partie_multi2 =false;
	donnees->latence = 200;
	donnees->fond_menu = lisBMPRGB("images/fond-menu.bmp");
	donnees->img_regles = lisBMPRGB("images/regles.bmp");
	donnees->fond_bouton = lisBMPRGB("images/boutonpetit.bmp");
	donnees->pion_noir_skin = lisBMPRGB("images/pion_2.bmp");
	donnees->pion_blanc_skin = lisBMPRGB("images/pion_1.bmp");
	donnees->pion_noir = lisBMPRGB("images/pion_noir.bmp");
	donnees->pion_blanc = lisBMPRGB("images/pion_blanc.bmp");

	donnees->temps =  lisBMPRGB("images/chrono.bmp");

	donnees->mort= lisBMPRGB("images/mort.bmp");
	donnees->bouton_retour = lisBMPRGB("images/bouton-retour.bmp");

		donnees->fond_vide =lisBMPRGB("images/vide.bmp");
	
	donnees->pion0 = true;
	donnees->pion1 = true;


	strcpy(donnees->nomComplet, "Joueur1");
	strcpy(donnees->nomCompletJ2, "Joueur2");
	strcpy(donnees->nomMap, "map.txt");
	strcpy(donnees->nomPartie, "partie.txt");
	donnees->toucheEntree=false;
	donnees->toucheAppuyee=false;
	


	init_skins(donnees);
	init_bool(donnees);
	maj_bool(donnees);
	return donnees;
}

