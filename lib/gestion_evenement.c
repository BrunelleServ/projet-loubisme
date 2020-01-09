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
#include "m_joueur.h"
#include "m_pion.h"
#include "m_plateau.h"
#include "v_plateau.h"
#include "v_menu.h"
#include "p_lecture.h"
#include "v_plateau.h"
#include "v_menu.h"
#include "p_ecriture.h"
#include "gestion_evenement.h"
#include "data.h"

#define TEMPO_MILLIS 20




void gestionEvenement(EvenementGfx evenement)
{
	static Data * donnees = NULL;

	switch (evenement)
	{
		case Initialisation:
			donnees = initialisation_des_donnees();
			demandeTemporisation(TEMPO_MILLIS);
			break;
		
		case Temporisation:
			rafraichisFenetre();
			break;
			
		case Affichage:	
			maj_bool(donnees); //initialisation des booleens necessaire au jeu
			if (donnees->lancerJeu) {
	   			if (!donnees->plateau_initialise) {
	   				initialise_plateau(donnees);
	   			}

	   			lancer_chrono(donnees);
	   			decremente_chrono(donnees);
				afficher_images_plateau(donnees);
		
			    mettre_a_jour_chrono(donnees);
			    afficheBarLat(donnees);
			
				
			}

			decremente_latence(donnees);

			if (donnees->fin_partie_win || donnees->fin_partie_loose || donnees->fin_partie_multi1 || donnees->fin_partie_multi2)
				gestion_fin_partie(donnees);

			gestion_menu(donnees);

			break;
			
		case Clavier:

		
			if(donnees->menu) clavier_saisiepseudo(donnees);	
			break;
			
		case ClavierSpecial:
			
			break;

		case BoutonSouris:
			break;
		
		case Souris: // Si la souris est deplacee
			break;
		
		case Inactivite: // Si la souris est deplacee
			break;
		
		case Redimensionnement: // Si la souris est deplacee
			break;
	}
}
