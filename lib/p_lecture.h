
#ifndef P_LECTURE
#define P_LECTURE


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
#include "p_ecriture.h"
#include "gestion_evenement.h"

/**

* \fn void initialiser_joueurs_sauvegarde (Data * donnees, char * nomFic)

* \brief Fonction qui initiliase les joueurs sauvegardés

* \param donnees Données stockées dans la structure Data

* \param nomFic Nom du fichier dans lequel est récupéré la sauvegarde


*/
void initialiser_joueurs_sauvegarde (Data * donnees, char * nomFic);


/**

* \fn  void initialiser_pions_sauvegarde (Data * donnees, char * nomFic)

* \brief Fonction qui initiliase les pions sauvegardées

* \param donnees Données stockées dans la structure Data

* \param nomFic Nom du fichier dans lequel est récupéré la sauvegarde


*/
void initialiser_pions_sauvegarde (Data * donnees, char * nomFic);


/**

* \fn  void initialiser_chrono_sauvegarde (Data * donnees, char * nomFic)

* \brief Fonction qui initiliase le chrono sauvegardé

* \param donnees Données stockées dans la structure Data

* \param nomFic Nom du fichier dans lequel est récupéré la sauvegarde


*/
void initialiser_chrono_sauvegarde (Data * donnees, char * nomFic);

/**

* \fn  void charger_partie(Data * donnees, char  * nomFicMap, char * nomFicStruct)

* \brief Fonction qui appelle les 3 fonctions précédentes ainsi que MatriceChargement pour charger une partie

* \param donnees Données stockées dans la structure Data

* \param nomFicMap Nom du fichier dans lequel la matrice générant la map est stockée

* \param nomFicStruct Nom du fichier dans lequel est récupéré la sauvegarde

*/
void charger_partie(Data * donnees, char  * nomFicMap, char * nomFicStruct);
#endif
