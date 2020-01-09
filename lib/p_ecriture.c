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




int sauvegarder_plateau (Data * donnees, char * nomFic) {
    FILE * fp=NULL;
    fp=fopen(nomFic,"w");

    if (fp==NULL) {
        fclose(fp);
        return -1;
    }

    for (int i = 0; i < NB_CASES; ++i)
    {
    	char sauvegarde [42] = "";
    	for (int j = 0; j < NB_CASES; ++j)
    	{
    		char caract[2];

    		int identifiant = get_identifiant_case(donnees, i, j);
    		sprintf(caract, "%d", identifiant);
    		strcat(sauvegarde,caract);
    		if (j != NB_CASES-1)
    			strcat(sauvegarde," ");
    	}
    	strcat(sauvegarde,"\n");
    	fputs(sauvegarde,fp);
    }

    fclose(fp);
    return 1;
}



int sauvegarder_structures (Data * donnees, char * nomFic) {
    FILE * fp=NULL;
    fp=fopen(nomFic,"w");

    if (fp==NULL) {
        fclose(fp);
        return -1;
    }

    for (int i = 0; i < donnees->joueur_crees; ++i)
    {
    	char sauvegarde [500] = "";
    	char chaine_tempo[100] = ""; // chaine temporaire

    	strcat(sauvegarde,"joueur ");

    	sprintf(chaine_tempo, "%d", donnees->joueurs[i]->id);
    	strcat(sauvegarde,chaine_tempo);
    	strcpy(chaine_tempo, ""); // réinitialisation de la chaine
    	strcat(sauvegarde," ");

    	strcat(sauvegarde, donnees->joueurs[i]->pseudo);
    	strcat(sauvegarde," ");



    	int est_joueur = (donnees->joueurs[i]->est_joueur) ? 1 : 0;
    	sprintf(chaine_tempo, "%d", est_joueur);
    	strcat(sauvegarde,chaine_tempo);
    	strcpy(chaine_tempo, ""); // réinitialisation de la chaine
    	strcat(sauvegarde," ");


    	// sprintf(chaine_tempo, "%i", donnees->joueurs[i]->touche_placer_pion);
    	// strcat(sauvegarde, chaine_tempo);
    	// strcpy(chaine_tempo, ""); // réinitialisation de la chaine
		// strcat(sauvegarde," ");

    	sprintf(chaine_tempo, "%d", get_indice_skins(donnees, donnees->joueurs[i]));
    	strcat(sauvegarde,chaine_tempo);
    	strcpy(chaine_tempo, ""); // réinitialisation de la chaine
    	strcat(sauvegarde," ");

    	strcat(sauvegarde,"\n");
    	fputs(sauvegarde,fp);
    }

    for (int i = 0; i < donnees->pions_dans_plateau; ++i)
    {
    	char sauvegarde [500] = "";
    	char chaine_tempo[100] = ""; // chaine temporaire

    	strcat(sauvegarde,"pion ");

    	// sprintf(chaine_tempo, "%d", donnees->pions[i]->joueur_source->id);
    	// strcat(sauvegarde,chaine_tempo);
    	// strcpy(chaine_tempo, ""); // réinitialisation de la chaine
    	// strcat(sauvegarde," ");

    	// sprintf(chaine_tempo, "%f", donnees->pions[i]->timer);
    	// strcat(sauvegarde,chaine_tempo);
    	// strcpy(chaine_tempo, ""); // réinitialisation de la chaine
    	// strcat(sauvegarde," ");

    	sprintf(chaine_tempo, "%d", donnees->pions[i]->x_coord_pion);
    	strcat(sauvegarde,chaine_tempo);
    	strcpy(chaine_tempo, ""); // réinitialisation de la chaine
    	strcat(sauvegarde," ");

    	sprintf(chaine_tempo, "%d", donnees->pions[i]->y_coord_pion);
    	strcat(sauvegarde,chaine_tempo);
    	strcpy(chaine_tempo, ""); // réinitialisation de la chaine
    	strcat(sauvegarde," ");

    	strcat(sauvegarde,"\n");
    	fputs(sauvegarde,fp);
    }

    char sauvegarde [500] = "";
	char chaine_tempo[100] = ""; // chaine temporaire

	strcat(sauvegarde,"CHRONO ");
	strcpy(chaine_tempo, " "); // réinitialisation de la chaine
	 for (int i=0;i < donnees->joueur_crees;i++){
	sprintf(chaine_tempo, "%ld",donnees->joueurs[i]->timer);
	strcat(sauvegarde,chaine_tempo);
	strcat(sauvegarde,"\n");
	fputs(sauvegarde,fp);
	 }
    fclose(fp);
    return 1;
}
void effacer_sauvegarde() {
	remove("sauvegarde_map.txt");
	remove("sauvegarde_structures.txt");
}


