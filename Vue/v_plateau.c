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


#define TAILLE_CASE 60
#define NB_CASES 10
#define ID_PION_1 2
#define ID_PION_2 3
#define ID_SOL_NOIR 1
#define ID_SOL_BLANC 0
#define ID_JOUEUR_1 4
#define ID_JOUEUR_2 5



#define NOMBRE_SKINS 2
#define NOMBRE_JOUEURS 2
#define TEMPO_MILLIS 20
#define TEMPO_SECS 0.025
#define CHRONO 180
#define TAILLE_TEXT 40
#define LARGEUR_BOUTON 226
#define HAUTEUR_BOUTON 100
#define LARGEUR_BOUTON1 240
#define HAUTEUR_BOUTON1 240
#define HAUTEUR_SKIN 330
#define LARGEUR_SKIN 140

#define LIMITE_PARCOURS 4




/** -----------------------------------------------------------
 *               PARTIE AFFICHAGES 
 *  -----------------------------------------------------------
 */

/**
 *   Affiche les pions avec leurs chronos
 */

void afficher_liste_pions (Data * donnees) {
	// printf("liste des pions : \n");
	// for (int i = 0; i < donnees->pions_dans_plateau; ++i)
	// {	
	// 	if (donnees->pions[i] != NULL)
	// 		printf(" - pion avec chrono à %f sec\n", donnees->pions[i]->timer);
	// }
	// printf("\n");
}

/**
 *   Affiche les IDs de toutes les pions présentes
 */

void afficher_pions_tableau(Data * donnees) {
	printf("|");
	for (int i = 0; i < donnees->pions_dans_plateau; ++i)
	{
		if (donnees->pions[i] == NULL) {
			printf(" NULL |");
		} else {

			printf(" %d |", donnees->pions[i]->id);
		}
	}
	printf("\n");
}

/**
 *   Affiche le contenu de chaque case du tableau
 */

void afficher_plateau(Data * donnees) {
	for (int i=0; i<NB_CASES;i++){
	    for(int k=0; k<NB_CASES; k++){
	    	printf("%d ", donnees->tab[i][k]);
	    }
	    printf("\n");
	}
}







/**
 * Affiche la barre latérale avec les infos des joueurs
 **/

void afficheBarLat(Data * donnees){
		get_nbrPion_joueur(donnees);
	couleurCourante(255, 255, 255);
	rectangle(600, 600, 850, 0);
	epaisseurDeTrait(3);
	creer_bouton(donnees, "Save & Quit",610,15,28);
	if(donnees->latence == 0 && abscisseSouris()<610+LARGEUR_BOUTON && abscisseSouris()>610 && ordonneeSouris()> 15 && ordonneeSouris()<15+HAUTEUR_BOUTON && etatBoutonSouris() == GaucheAppuye){
				sauvegarder_structures(donnees, "sauvegarde_structures.txt");
				sauvegarder_plateau(donnees, "sauvegarde_map.txt");
				exit(1);
			}
	
	
    char *carac="/";
   
    
    int distanceAffichage = 100;
    for (int i=0;i < donnees->joueur_crees;i++){
		epaisseurDeTrait(0.5);

	     char *varTempo=(char *)malloc(sizeof(char*));
	    sprintf(varTempo,"%d",i+1);
		ecrisImage(620, 565-distanceAffichage*i, donnees->joueurs[i]->perso_tenue_courante->largeurImage, donnees->joueurs[i]->perso_tenue_courante->hauteurImage, donnees->joueurs[i]->perso_tenue_courante->donneesRGB); // affichage
	    afficheChaine(donnees->joueurs[i]->pseudo,17, 660,570-distanceAffichage*i);
	    
	    
	   char *nbPions=(char*)malloc(sizeof(char*));
	    sprintf(nbPions,"%d",donnees->nbPions_joueur1);
	 afficheChaine(nbPions,17, 790,515-distanceAffichage*i);
	    afficheChaine(carac,13,810,515-distanceAffichage*i);
		 afficheChaine("20",13,820,515-distanceAffichage*i);

	
	  couleurCourante(0,0,0);
	
    char *chronoAffichage=(char*)malloc(sizeof(char *));
    sprintf(chronoAffichage,"%ld",donnees->joueurs[i]->timer);
    //printf(" Chrono char%s\n",chronoAffichage);
    ecrisImage(620,515-distanceAffichage*i,donnees->temps->largeurImage,donnees->temps->hauteurImage,donnees->temps->donneesRGB);
    
    afficheChaine(chronoAffichage,20,655,520-distanceAffichage*i);

	    epaisseurDeTrait(5);
	    couleurCourante(0,0,0);
	    ligne(605,500-distanceAffichage*i,845,500-distanceAffichage*i);

	}
}

void afficher_images_plateau(Data * donnees){
	effaceFenetre (255, 255, 255);

	
	for (int i=0; i<NB_CASES;i++){
	      for(int k=0; k<NB_CASES; k++){
			if (donnees->tab[i][k] == ID_SOL_NOIR) {
ecrisImage(k*TAILLE_CASE, (NB_CASES*TAILLE_CASE)-(i+1)*TAILLE_CASE, donnees->fond_noir->largeurImage, donnees->fond_noir->hauteurImage, donnees->fond_noir->donneesRGB);
		

			}
					else if (donnees->tab[i][k] == ID_SOL_BLANC){
ecrisImage(k*TAILLE_CASE, (NB_CASES*TAILLE_CASE)-(i+1)*TAILLE_CASE, donnees->fond_blanc->largeurImage, donnees->fond_blanc->hauteurImage, donnees->fond_blanc->donneesRGB);
		

			}
				
			if (donnees->partie[i][k] == ID_PION_1) {
				ecrisImage(k*TAILLE_CASE, (NB_CASES*TAILLE_CASE)-(i+1)*TAILLE_CASE, donnees->skins[1]->skin_pion->largeurImage, donnees->skins[1]->skin_pion->hauteurImage, donnees->skins[1]->skin_pion->donneesRGB);
		
			}
				else if (donnees->partie[i][k] == ID_PION_2){
				ecrisImage(k*TAILLE_CASE, (NB_CASES*TAILLE_CASE)-(i+1)*TAILLE_CASE, donnees->skins[0]->skin_pion->largeurImage, donnees->skins[0]->skin_pion->hauteurImage, donnees->skins[0]->skin_pion->donneesRGB);
		  }
			

		  }
	}

			

}

