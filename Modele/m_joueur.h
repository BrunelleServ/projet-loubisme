#ifndef M_joueur
#define M_joueur

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
#include "m_pion.h"
#include "m_plateau.h"

#include "v_plateau.h"
#include "v_menu.h"
#include "p_lecture.h"
#include "p_ecriture.h"
#include "gestion_evenement.h"




typedef struct Data Data;
typedef struct Pion Pion;
typedef struct Joueur Joueur;

struct Joueur{
	int id;
	char pseudo [32]; 
	
	long timer;
	long timer1;
	int skin_nmb;
	
	bool est_joueur; 
	DonneesImageRGB *perso_tenue_courante; 
	struct Skin * skins; // tenue vestimentaire du personnage

	
} ;

typedef struct Skin Skin ; 
struct Skin{
	DonneesImageRGB * skin_pion;
		DonneesImageRGB * skin_dame;
		DonneesImageRGB * perso_tenue;

};
Joueur * nouveau_joueur (Data * donnees, int id, char pseudo [32], bool est_joueur,int skin_index) ;

Skin * nouveau_skin(char t_pion [256],  char t_dame [256],char t_tenue [256]);
void init_skins (Data * donnees);
int get_indice_skins( Data * donnees, Joueur * a);


/**

* \fn int nb_joueurs ( Data * donnees)

* \brief Fonction qui compte le nombre de joueur
	
* \param donnees Données stockées dans la structure Data

* \return le nombre de joueur

*/
int nb_joueurs ( Data * donnees);

#endif
