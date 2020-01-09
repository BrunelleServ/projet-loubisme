
#ifndef V_MENU
#define V_MENU

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
#include "p_ecriture.h"
#include "gestion_evenement.h"


typedef struct Data Data;


/**

* \fn void init_bool(Data * donnees)

* \brief Fonction qui initiliase les differents boolens du menu a chaque affichage. 

* \param donnees Données stockées dans la structure Data


*/
void init_bool(Data * donnees);




/**

* \fn void maj_bool(Data * donnees)

* \brief Fonction qui met à jour les differents boolens du menu a chaque affichage. 

* \param donnees Données stockées dans la structure Data


*/
void maj_bool( Data * donnees);

/**

* \fn void affiche_bool( Data * donnees)

* \brief Fonction qui affiche l'état des différents booléens du menu

* \param donnees Données stockées dans la structure Data

*/
void affiche_bool( Data * donnees);

/**

* \fn void creer_bouton( Data * donnees, char* text, int posx, int posy,int police_taille)

* \brief Fonction qui crée un bouton avec un texte centré

* \param donnees Données stockées dans la structure Data

* \param text Texte du bouton

* \param posx position X en pixel du bouton 

* \param posy position Y en pixel du bouton

* \param police_taille Taille de la police pour le texte centré
*/
void creer_bouton( Data * donnees, char* text, int posx, int posy,int police_taille);


/**

* \fn bool creer_bouton_retour( Data * donnees)

* \brief Fonction qui renvoie true si un clique gauche est effectué sur le bouton retour, false sinon

* \param donnees Données stockées dans la structure Data

* \return true ou false

*/
bool creer_bouton_retour( Data * donnees);



/**

* \fn bool creer_bouton_retour_skin( Data * donnees)

* \brief Fonction qui renvoie true si un clique gauche est effectué sur le bouton retour skin, false sinon

* \param donnees Données stockées dans la structure Data

* \return true ou false

*/
bool creer_bouton_retour_pion( Data * donnees);


/**

* \fn void affiche_pion( Data * donnees)

* \brief Fonction qui affiche les images des skins

* \param donnees Données stockées dans la structure Data


*/
void affiche_pion( Data * donnees);


/**

* \fn bool perso_pion( Data * donnees, int * indice_skin_link)

* \brief Fonction qui retourne un booléen à true si un skin est selectionné, false sinon

* \param donnees Données stockées dans la structure Data

* \param indice_skin_link Indice du skin Link choisi, peut prendre 4 valeurs possibles

* \return true ou false

*/
bool perso_pion( Data * donnees, int * indice_skin_link);


/**

* \fn void assign_pion( Data * donnees)

* \brief Fonction permettant d'assigner le skin au joueur, puis au differentes ia  

* \param donnees Données stockées dans la structure Data

*/
void assign_pion( Data * donnees);

/**

* \fn void decremente_latence( Data * donnees)

* \brief Fonction qui décremente la variable latence. Latence permet de faire une pause au programme pour gérer les cliques souris

* \param donnees Données stockées dans la structure Data

*/
void decremente_latence( Data * donnees);


/**

* \fn void clavier_saisiepseudo( Data * donnees)

* \brief Fonction qui initialise le clavier pour saisir un pseudo

* \param donnees Données stockées dans la structure Data


*/
void clavier_saisiepseudo( Data * donnees);

/**

* \fn void saisie_pseudo( Data * donnees)

* \brief Fonction permettant de saisir et d'afficher son pseudo

* \param donnees Données stockées dans la structure Data


*/
void saisie_pseudo( Data * donnees);




/**

* \fn void gestion_menu( Data * donnees)

* \brief Fonction qui gère les différents boutons du menu et lance les fonctions précédentes

* \param donnees Données stockées dans la structure Data

*/
void gestion_menu( Data * donnees);

/**

* \fn void gestion_fin_partie( Data * donnees)

* \brief Fonction qui affiche différents messages de fin de partie (Vous avez gagne !,...)

* \param donnees Données stockées dans la structure Data

*/
void gestion_fin_partie( Data * donnees);

#endif
