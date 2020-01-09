#ifndef GESTION_H
#define GESTION_H

#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
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




/**

* \fn void gestionEvenement(EvenementGfx evenement)

* \brief Fonction qui lance la boucle d'évenements de Gfxlib

* \param evenement de type EvenementGfx permet de lancer le switch evenement de Gfxlib


*/

void gestionEvenement(EvenementGfx evenement);

#endif
