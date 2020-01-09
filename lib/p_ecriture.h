
#ifndef P_ECRITURE
#define P_ECRITURE

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
#include "gestion_evenement.h"

typedef struct Data Data;
/**

* \fn int sauvegarder_plateau (Data * donnees, char * nomFic)

* \brief Fonction qui sauvegarde la map dans un fichier txt 

* \param donnees Données stockées dans la structure Data

* \param nomFic Nom du fichier dans lequel va être fait la sauvegarde

* \return 1 si le fichier n'exsite pas et -1 sinon

*/

int sauvegarder_plateau (Data * donnees, char * nomFic);


/**

* \fn int sauvegarder_structures (Data * donnees, char * nomFic)

* \brief Fonction qui sauvegarde la structure (joueur, pion et chrono) dans un fichier txt 

* \param donnees Données stockées dans la structure Data

* \param nomFic Nom du fichier dans lequel va être fait la sauvegarde

* \return 1 si le fichier n'exsite pas et -1 sinon

*/
int sauvegarder_structures (Data * donnees, char * nomFic);


/**

* \fn void effacer_sauvegarde()

* \brief Fonction qui supprime les deux fichiers de sauvegarde 


*/
void effacer_sauvegarde();

#endif
