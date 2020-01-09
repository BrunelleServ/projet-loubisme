#ifndef M_PLATEAU
#define M_PLATEAU

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

#include "v_plateau.h"
#include "v_menu.h"
#include "p_lecture.h"
#include "p_ecriture.h"
#include "gestion_evenement.h"


#define NB_CASES 10
/**

* \fn int get_j_coords(int abs)

* \brief Fonction qui transforme une coordonnée graphiques (Pixels) en coordonnée matricielle pour l'axe des abscisses  
	
* \param abs abscisse en pixel

* \return abscisse matricielle

*/
int get_j_coords(int abs);

/**

* \fn int get_j_coords(int abs)

* \brief Fonction qui transforme une coordonnée graphiques (Pixels) en coordonnée matricielle pour l'axe des ordonnées 
	
* \param ord ordonnée en pixel

* \return ordonnée matricielle

*/
int get_i_coords(int ord);

/**

* \fn int choix_amelioration ()

* \brief Fonction qui fait un random entre les deux types d'améliorations possible pour en choisir une aléatoirement
 
* \return entre 8 et 9, chacun associé à une amélioration

*/

void mettre_a_jour_chrono (Data * donnees);


/**

* \fn void MatriceChargement(Data * donnees, char * fileName)

* \brief Fonction qui initialise la matrice du plateau à partir d'un fichier txt

* \param donnees Données stockées dans la structure Data

* \param fileName nom du fichier txt contenant la matrice

*/
void MatriceChargement(int tab[NB_CASES][NB_CASES], char * fileName);




/**

* \fn void lancer_chrono(Data * donnees)

* \brief Fonction lançant le chrono

* \param donnees Données stockées dans la structure Data


*/
void lancer_chrono(Data * donnees);

/**

* \fn void decremente_chrono(Data * donnees)

* \brief Fonction décrémentant le chrono

* \param donnees Données stockées dans la structure Data

*/
void decremente_chrono(Data * donnees);

/**

* \fn int get_identifiant_case (Data * donnees, int i, int j)

* \brief Fonction qui retourne l'ID d'une case selon i et j

* \param donnees Données stockées dans la structure Data

* \param i position matricielle

* \param j position matricielle
 
* \return l'idientifiant de la case

*/
int get_identifiant_case (Data * donnees, int i, int j);

/**

* \fn void initialise_plateau (Data * donnees)

* \brief Fonction qui initialise le plateau (avec la définition d'une cible pour chaque bot)

* \param donnees Données stockées dans la structure Data

*/
void initialise_plateau (Data * donnees);

/**

* \fn void reinitialise_plateau(Data * donnees)

* \brief Fonction qui reinitialise le plateau

* \param donnees Données stockées dans la structure Data


*/
void reinitialise_plateau(Data * donnees);

#endif

