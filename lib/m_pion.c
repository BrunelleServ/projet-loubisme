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



#define MAX_PIONS 40 // max 40 pions sur le terrain a la fois (10 par joueurs)



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



Pion * creer_pion (int id,  Data * donnees,int joueur_associe, int couleur) {
        Pion * pion = NULL;
        pion = (Pion *) malloc(sizeof(Pion));
	
	
	pion->id = id;
	pion->joueur_associe = joueur_associe;
    pion->couleur = couleur;
    pion->onlive = true;
	++donnees->pion_increment_id;
return pion;

	
}
void init_coord_pions(Pion * pion, int i, int j)
{


}


void get_nbrPion_joueur(Data * donnees){

        donnees->nbPions_joueur1 = 0;
         donnees->nbPions_joueur2 = 0;
      
    for(int i= 0; i<40; i++){
        if(donnees->pions[i]->joueur_associe == 0 && donnees->pions[i]->onlive == true){
        
            ++donnees->nbPions_joueur1;
        
    }
    else if (donnees->pions[i]->joueur_associe == 1 && donnees->pions[i]->onlive == true){
            ++donnees->nbPions_joueur2;
    }
}
 

}