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
#define MAX_PIONS 40


#define NOMBRE_SKINS 2
#define NOMBRE_JOUEURS 2
#define TEMPO_MILLIS 20
#define TEMPO_SECS 0.025
#define CHRONO 180

#define HAUTEUR_SKIN 330
#define LARGEUR_SKIN 140

/**
 *   Transforme une coordonnée graphiques (Pixels) en coordonnée matricielle pour l'axe des abscisses  
 */

int get_j_coords(int abs) {
	if (abs >= LARGEUR_FENETRE)
		return (NB_CASES-1);
	else if (abs <= 0)
		return 0;
	else 
		return (abs / TAILLE_CASE);
}


/**
 *   Transforme une coordonnée graphiques (Pixels) en coordonnée matricielle pour l'axe des ordonnées 
 */

int get_i_coords(int ord) {
	if (ord >= HAUTEUR_FENETRE)
		return 0;
	else if (ord <= 0)
		return (NB_CASES-1);
	else 
		return ((HAUTEUR_FENETRE / TAILLE_CASE) - ord / TAILLE_CASE - 1);
}




/** -----------------------------------------------------------
 *               PARTIE PLATEAU 
 *  -----------------------------------------------------------
 */

/**
 *   Met à jour le chronomètre de la partie et vérifie si la partie est terminée ou non
 */

void mettre_a_jour_chrono (Data * donnees) {
	donnees->mini_chrono += (TEMPO_SECS);
	if (donnees->mini_chrono >=  1) { // si une seconde est passé
		donnees->chrono_partie--; // on enlève une seconde au chrono de la partie
		
		donnees->mini_chrono = 0;
	}
	 for (int i=0;i < donnees->joueur_crees;i++){
	if (donnees->joueurs[i]->timer <= 0) {
		printf("Le chrono est terminé, partie terminée\n");
		exit(1);
	}
	 }
}


/**
 *   Initialise la matrice du plateau à partir d'un fichier txt
 */

void MatriceChargement(int tab[NB_CASES][NB_CASES], char * fileName){

  FILE *MapPath = NULL;
  MapPath =fopen(fileName,"r");
  if(MapPath !=NULL){
    fseek(MapPath,0,SEEK_SET);
    for (int i=0; i<NB_CASES;i++){
      for(int k=0; k<NB_CASES; k++){
        if(fscanf(MapPath,"%d",&tab[i][k]) == 1){
 
        }
      }
    }
  }

  fclose(MapPath);
}

/**
 * Fonction lançant le chrono
 */
void lancer_chrono(Data * donnees){
	if (donnees->timeron==true){
			 for (int i=0;i < donnees->joueur_crees;i++){
				
		donnees->joueurs[i]->timer1=((double)time(NULL)+donnees->tempscourant);
		printf("Temps de départ %ld\n",donnees->joueurs[i]->timer1);
		
			 }
			 donnees->timeron=false;
	}
}


/**
 * Fonction décrémentant le chrono
 */
void decremente_chrono(Data * donnees){
	 for (int i=0;i < donnees->joueur_crees;i++){
	donnees->joueurs[i]->timer=donnees->joueurs[i]->timer1-(double)time(NULL);
	 }
}

int get_identifiant_case (Data * donnees, int i, int j) {
	// int identifiant = donnees->tab[i][j];
	// if (identifiant > 9) identifiant = ID_PION_1; // les autres identifiants sont inutiles à sauvegarder

	// for (int k = 0; k < donnees->joueur_crees; ++k)
	// {
	// 	if (donnees->joueurs[k]->x_coord_joueur == i && donnees->joueurs[k]->y_coord_joueur == j) {
	// 		identifiant = donnees->joueurs[k]->id;
	// 	}
	// }

	// return identifiant;
}


void initialise_plateau (Data * donnees) {
	// retirer_joueur_innexistant_a_l_init(donnees);
	// for (int i = 0; i < donnees->joueur_crees; ++i)
	// {
	// 	if (!donnees->joueurs[i]->est_joueur)
	// 		definir_cible(donnees, donnees->joueurs[i]); // définition d'une cible à chaque bot
	// }
	// donnees->plateau_initialise = true;
}

void reinitialise_plateau(Data * donnees){

	char nom_temp[32] = "";
	strcpy(donnees->nomComplet,nom_temp);
	free(donnees->skins);
	donnees->skins = (Skin **) malloc(NOMBRE_SKINS * sizeof(Skin *));
	init_skins(donnees);
	donnees->joueurs = NULL;
	donnees->joueurs = (Joueur **) malloc(NOMBRE_JOUEURS * sizeof(Joueur *));
	MatriceChargement(donnees->tab, donnees->nomMap);
	MatriceChargement(donnees->partie, donnees->nomPartie);
	donnees->tempscourant = CHRONO;
	donnees->fin_partie_win=false;
	donnees->fin_partie_loose=false;
	donnees->fin_partie_multi1=false;
	donnees->fin_partie_multi2=false;
	donnees->timeron = true;
	donnees->joueur_crees = 0;
	donnees->pions_dans_plateau = 0;
	donnees->plateau_initialise = false;

}


