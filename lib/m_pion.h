#ifndef M_pion
#define M_pion

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
#include "m_plateau.h"
#include "m_pion.h"
#include "v_plateau.h"
#include "v_menu.h"
#include "p_lecture.h"
#include "p_ecriture.h"
#include "gestion_evenement.h"

typedef struct Pion Pion;
typedef struct Joueur joueur;
struct Pion{
	int id;
	
	
	int x_coord_pion;
	int y_coord_pion;
	int joueur_associe;
	int couleur;
struct Dame * dame;
};

typedef struct Dame Dame ; 
struct Dame{
	DonneesImageRGB * skin_dame;
	bool dameon;
		

};

Pion * creer_pion (int id,  Data * donnees,int joueur_associe, int i, int j, int couleur);
void get_nbrPion_joueur(Data * donnees);
#endif
