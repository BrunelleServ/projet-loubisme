
#ifndef V_PLATEAU
#define V_PLATEAU

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

#include "v_menu.h"
#include "p_lecture.h"
#include "p_ecriture.h"
#include "gestion_evenement.h"



typedef struct Data Data;
typedef struct Joueur joueur;

/**

* \fn void afficher_liste_pions ( Data * donnees)

* \brief Fonction qui affiche les pions avec leurs chronos

* \param donnees Données stockées dans la structure Data

*/
void afficher_liste_pions ( Data * donnees);

/**

* \fn void afficher_pions_tableau( Data * donnees)

* \brief Fonction qui  affiche les IDs de toutes les pions présentes

* \param donnees Données stockées dans la structure Data

*/
void afficher_pions_tableau( Data * donnees);

/**

* \fn void afficher_plateau( Data * donnees)

* \brief Fonction qui affiche le contenu de chaque case du tableau

* \param donnees Données stockées dans la structure Data


*/
void afficher_plateau( Data * donnees);




/**

* \fn void afficheBarLat( Data * donnees)

* \brief Fonction qui affiche la barre latérale contenant le temps, un bouton de sauvegarde et les informations des joueurs présente lors du lancement du jeu

* \param donnees Données stockées dans la structure Data


*/
void afficheBarLat( Data * donnees);

/**

* \fn void afficher_images_plateau( Data * donnees)

* \brief Fonction qui associe une image à chaque entier de la matrice

* \param donnees Données stockées dans la structure Data


*/
void afficher_images_plateau( Data * donnees);

#endif
