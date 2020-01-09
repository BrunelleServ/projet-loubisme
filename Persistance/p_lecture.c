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


void initialiser_joueurs_sauvegarde (Data * donnees, char * nomFic) {
	FILE * fp=NULL;
    fp=fopen(nomFic,"r");

    if (fp==NULL) {
        fclose(fp);
        return;
    }

    char * line = NULL;
    size_t len = 0;
    size_t read;
    const char s[2] = " ";

    donnees->joueur_crees = 0;

	char * ligne_joueur = "";
	char mot [32];

	int i = 0;
	int etape = 0;

	int id;
	char pseudo [32];
	
	bool est_joueur;



	while ((read = getline(&line, &len, fp)) != -1) {

		etape = 0;
    	ligne_joueur = strtok(line, s);
		bool bonne_ligne = false;

    	while( ligne_joueur != NULL ) {    //incrémente les colonnes
    		if (etape == 0) {
    			if (strcmp(ligne_joueur, "joueur") == 0) {
		       	 	bonne_ligne = true;
		    	}
	    		ligne_joueur = strtok( NULL, s);
		    	++etape;
		    	continue;
    		}
    		if (bonne_ligne) {
				strcpy(mot, ligne_joueur);

	    		if (etape == 1) {
	    			id = atoi(mot);
	    		} else if (etape == 2) {
	    			strcpy(pseudo,mot);
	    		}  else if (etape == 5) {
	    			est_joueur = (atoi(mot) == 0) ? false : true;
	    		}  
    		}
    		
	    	ligne_joueur = strtok( NULL, s);

		    ++etape;
			
       } 
	   etape = 0;
    }
}
void initialiser_pions_sauvegarde (Data * donnees, char * nomFic) {
	// FILE * fp=NULL;

    // char * line = NULL;
    // size_t len = 0;
    // size_t read;
    // const char s[2] = " ";
  
    // fp=fopen(nomFic,"r");

    // if (fp==NULL) {
    //     fclose(fp);
    //     return;
    // }

    // donnees->pions_dans_plateau = 0;

	// char * ligne_pion = "";
	// char mot [32];

	// int i = 0;
	// int etape = 0;

	// Joueur joueur_source;
	// float timer;
	// int x_coord_pion;
	// int y_coord_pion;

	// while ((read = getline(&line, &len, fp)) != -1) {

	// 	etape = 0;
    // 	ligne_pion = strtok(line, s);
	// 	bool bonne_ligne = false;

    // 	while( ligne_pion != NULL ) { 
    // 		if (etape == 0) {
    // 			if (strcmp(ligne_pion, "pion") == 0) {
	// 	       	 	bonne_ligne = true;
	// 	    	}
	//     		ligne_pion = strtok( NULL, s);
	// 	    	++etape;
	// 	    	continue;
    // 		}
    // 		if (bonne_ligne) {
	// 			strcpy(mot, ligne_pion);

	//     		if (etape == 1) {
	//     			int id_act = atoi(mot);

	//     			for (int i = 0; i < donnees->joueur_crees; ++i)
	//     				if (donnees->joueurs[i]->id == id_act)
	//     					joueur_source = donnees->joueurs[i];

	//     		} else if (etape == 2) {
	//     			timer = atof(mot);
	//     		} else if (etape == 3) {
	//     			x_coord_pion = atoi(mot);
	//     		} else if (etape == 4) {
	//     			y_coord_pion = atoi(mot);
	//     		}
    // 		}
    // 		if (etape == 5 && bonne_ligne) {
    // 			creer_pion(donnees, joueur_source, x_coord_pion, y_coord_pion);

    // 			pion * pion_creee = chercher_pion_dans_tout_le_plateau(donnees, x_coord_pion, y_coord_pion);
    // 			pion_creee->timer = timer;
	//     		++i;
    // 			break;
    // 		}
	//     	ligne_pion = strtok( NULL, s);

	// 	    ++etape;
			
    //    } 
	//    etape = 0;
    // }

    // afficher_liste_pions(donnees);
}

void initialiser_chrono_sauvegarde (Data * donnees, char * nomFic) {
	FILE * fp=NULL;
    fp=fopen(nomFic,"r");

    if (fp==NULL) {
        fclose(fp);
        return;
    }

    char * line = NULL;
    size_t len = 0;
    size_t read;
    const char s[2] = " ";

	char * ligne_chrono = "";
	char mot [32];

	int etape = 0;

	while ((read = getline(&line, &len, fp)) != -1) {
		etape = 0;
    	ligne_chrono = strtok(line, s);
		bool bonne_ligne = false;

    	while( ligne_chrono != NULL ) { 
    		if (etape == 0) {
    			if (strcmp(ligne_chrono, "CHRONO") == 0) {
		       	 	bonne_ligne = true;
		    	}
	    		ligne_chrono = strtok( NULL, s);
		    	++etape;
		    	continue;
    		}
    		if (bonne_ligne) {
				strcpy(mot, ligne_chrono);

				donnees->tempscourant=atoi(mot);
				printf("donnees->temps courant : %d\n",  donnees->tempscourant);
    		}
	    	ligne_chrono = strtok( NULL, s);
       } 
    }
}

void charger_partie(Data * donnees, char  * nomFicMap, char * nomFicStruct) {
	MatriceChargement(donnees, nomFicMap);
	initialiser_joueurs_sauvegarde(donnees, nomFicStruct);
	initialiser_pions_sauvegarde(donnees, nomFicStruct);
	initialiser_chrono_sauvegarde(donnees, nomFicStruct);
	printf("ok1\n");
	initialise_plateau(donnees);
	donnees->plateau_initialise = true;
	printf("ok2\n");
	donnees->timeron = true;
	lancer_chrono(donnees);
	printf("ok3\n");
}

