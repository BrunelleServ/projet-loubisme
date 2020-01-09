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


#define TAILLE_TEXT 30
#define LARGEUR_BOUTON 226
#define HAUTEUR_BOUTON 100
#define LARGEUR_BOUTON1 240
#define HAUTEUR_BOUTON1 240
#define HAUTEUR_PION 120
#define LARGEUR_PION 120
#define ID_PION_1 2
#define ID_PION_2 3



void init_bool(Data * donnees){

	donnees->menu = true;
	donnees->lancerJeu = false;
	donnees->jouer = false;
	donnees->quitter = false;

	
	donnees->lancer = false;
	donnees->regle_jeu = false;
	donnees->menu_principal = true;

	donnees->choix_pion_1 = false;
	donnees->choix= false;
	donnees->choix_pion_2 = false;
	donnees->choix_pion = false;
	
	donnees->choix_pseudoJ2 = false;

	donnees->fin_partie_win = false;
	donnees->fin_partie_loose = false;
	

}

/**
 *   Met à jour les differents boolens du menu a chaque affichage. 
 *  */

void maj_bool(Data * donnees){
	if(donnees->menu){
		donnees->fin_partie_win =false;
		donnees->fin_partie_loose = false;
	}
	if(donnees->lancerJeu == true){
		donnees->menu = false;
	}
	if(donnees->fin_partie_win){
		donnees->lancerJeu = false;
	}
	if(donnees->fin_partie_loose){
		donnees->lancerJeu = false;
	}
	
	
	if(donnees->menu_principal){
		donnees->jouer=false;
		donnees->lancer = false;
		donnees->regle_jeu = false;
		donnees->choix_pion = false;
		donnees->choix_pion_1 = false;
donnees->choix_pion_2 = false;
donnees->choix= false;
		donnees->choix_map = false;
	}
	if(donnees->jouer == true  || donnees->regle_jeu == true){
		donnees->menu_principal = false;
	donnees->lancer = false;
		donnees->choix= false;
			donnees->choix_pion_2=false;
				donnees->choix_pion_1=false;
		donnees->choix_pion=false;
		
		donnees->choix_pseudoJ2 =false;
		strcpy(donnees->nomComplet, "Joueur1");
	strcpy(donnees->nomCompletJ2, "Joueur2");
			donnees->pion0 = true;
		donnees->pion1 = true;
	}


	if(donnees->choix_pseudoJ2 == true){
		donnees->lancer = false;
	}
	if(donnees->lancer == true){
donnees->jouer = false;
	
		
	}

	if(donnees->choix == true){
	donnees->choix_pseudoJ2 =false;
donnees->lancer = false;
		donnees->choix_pion = true;


	}

if(donnees->choix_pion == true){
	
	donnees->choix_pseudoJ2 =false;
donnees->lancer = false;
		


		
	}
		if(donnees->choix_pion_1 == true){
			donnees->choix_pion =false;
		
	}
		if(donnees->choix_pion_2 == true){

	donnees->choix_pion_1 = false;
	}


}



void affiche_bool(Data * donnees){ //Test unitaire lien logique

	if(donnees->lancerJeu == true)printf("donnees->lancerJeu true\n");
	else printf("donnees->lancerJeu false\n");
	
	if(donnees->jouer == true)printf("jouer true\n");
	else printf("jouer false\n");
	
	if(donnees->quitter == true)printf("quitter true\n");
	else printf("quitter false\n");
	

	
	
	
	if(donnees->lancer == true)printf("multi true\n");
	else printf("multi false\n");
	
	if(donnees->regle_jeu == true)printf("regle_jeu true\n");
	else printf("regle_jeu false\n");
	
	if(donnees->menu_principal == true)printf("menu_principal true\n");
	else printf("menu_principal false\n");
	
	if(donnees->menu == true)printf("menu true\n");
	else printf("menu false\n");

	if(donnees->choix_pion == true)printf("choix_pion true\n");
	else printf("choix_pion false\n");

	


	
	if(donnees->choix_pion_1 == true)printf("choix_pion_1 true\n");
	else printf("choix_pion_1 false\n");
	
	if(donnees->choix_pion_2 == true)printf("choix_pion_2 true\n");
	else printf("choix_pion_2 false\n");
	


}

/**
 *  Creer un bouton avec un texte centré
 */

void creer_bouton(Data * donnees, char* text, int posx, int posy,int police_taille){
	ecrisImage(posx, posy, donnees->fond_bouton->largeurImage, donnees->fond_bouton->hauteurImage, donnees->fond_bouton->donneesRGB);
	float taille = tailleChaine(text, police_taille);
	couleurCourante(0, 0, 0);
	afficheChaine(text, police_taille, posx+((226-taille)/2), posy+30);
}

bool creer_bouton_retour(Data * donnees){

	ecrisImage(5, 530, donnees->bouton_retour->largeurImage, donnees->bouton_retour->hauteurImage, donnees->bouton_retour->donneesRGB);
	if(donnees->latence == 0 && abscisseSouris()<67 && abscisseSouris()>5 && ordonneeSouris()> 530 && ordonneeSouris()<596 && etatBoutonSouris() == GaucheAppuye){
		donnees->latence = 200;
		return true;
	}
	return false;
}




bool creer_bouton_retour_pion(Data * donnees){

	ecrisImage(5, 530, donnees->bouton_retour->largeurImage, donnees->bouton_retour->hauteurImage, donnees->bouton_retour->donneesRGB);
	if(donnees->latence == 0 && abscisseSouris()<67 && abscisseSouris()>5 && ordonneeSouris()> 530 && ordonneeSouris()<596 && etatBoutonSouris() == GaucheAppuye){
		donnees->pion0 = true;
		donnees->pion1 = true;

		donnees->choix_pion_1=false;
		donnees->choix_pion_2=false;
		donnees->choix_pion=false;
				donnees->choix =false;
		donnees->latence = 200;
		
		return true;
	}
	return false;
}

/**
 *  Fonctions permettant d'assigner le pion aux différents joueurs
 */

void affiche_pion(Data * donnees){
	
	ecrisImage(0, 0, donnees->fond_vide->largeurImage, donnees->fond_vide->hauteurImage, donnees->fond_vide->donneesRGB);
		couleurCourante(255, 255, 255);
		afficheChaine(donnees->text_choix, TAILLE_TEXT, 90, 370);
		if (donnees->pion0)
			ecrisImage(300,200, donnees->pion_noir_skin->largeurImage, donnees->pion_noir_skin->hauteurImage, donnees->pion_noir_skin->donneesRGB);
		if (donnees->pion1)
			ecrisImage(500,200, donnees->pion_blanc_skin->largeurImage, donnees->pion_blanc_skin->hauteurImage, donnees->pion_blanc_skin->donneesRGB);


}

bool perso_pion(Data * donnees, int * indice_pion){
	affiche_pion(donnees);

	bool return_val = false;
	if(donnees->pion0 && donnees->latence == 0 && abscisseSouris()<300+LARGEUR_PION && abscisseSouris()>300 && ordonneeSouris()> 200 && ordonneeSouris()<200 + HAUTEUR_PION && etatBoutonSouris() == GaucheAppuye){
		*indice_pion =  1;
		donnees->pion0 = false;
		return_val = true;
		donnees->latence = 200;
	}

	if(donnees->pion1 && donnees->latence == 0 && abscisseSouris()<500+LARGEUR_PION && abscisseSouris()>500 && ordonneeSouris()> 200 && ordonneeSouris()<200 + HAUTEUR_PION && etatBoutonSouris() == GaucheAppuye){
		*indice_pion =  0;
		donnees->pion1 = false;
		return_val = true;
		donnees->latence = 200;
	}

	
	return return_val;


}


void assign_pion(Data * donnees){

	
	if(donnees->choix == true){

	
			if(donnees->choix_pion == true){
			
				donnees->choix_pion_1 = perso_pion(donnees, &donnees->indice_pion_1);
		
					donnees->lancer = creer_bouton_retour_pion(donnees);
			strcpy(donnees->text_choix,"Pion joueur 1?");
			
		}
			else if (donnees->choix_pion_1 == true){
					
		
			donnees->choix_pion_2 = perso_pion(donnees, &donnees->indice_pion_2);
			donnees->lancer = creer_bouton_retour_pion(donnees);
				strcpy(donnees->text_choix,"Pion joueur 2?");
		
			}
			else if(donnees->choix_pion_2 == true) {
		
				MatriceChargement(donnees->tab, donnees->nomMap);
				MatriceChargement(donnees->partie, donnees->nomPartie);
				donnees->lancerJeu = true;
		
			
				if (donnees->lancerJeu) {
					setbuf(stdout, NULL);

				donnees->joueurs[0] = nouveau_joueur(donnees, 0, donnees->nomComplet, true, donnees->indice_pion_1);
				donnees->joueurs[1] = nouveau_joueur(donnees, 1, donnees->nomCompletJ2,true, donnees->indice_pion_2);
				

			
	      for(int k=0; k<20; k++){ 
					if(donnees->indice_pion_1 == donnees->joueurs[0]->id){
donnees->pions[k] = creer_pion (k, donnees,donnees->joueurs[0]->id, donnees->indice_pion_1);
				}else{
donnees->pions[k+20] = creer_pion (k + 20, donnees,donnees->joueurs[1]->id,donnees->indice_pion_2);
				}

				}
				
					
	      for(int k=20; k<40; k++){
if(donnees->indice_pion_2 == donnees->joueurs[1]->id){
			donnees->pions[k] =creer_pion (k, donnees,donnees->joueurs[1]->id, donnees->indice_pion_2);

				}else{
donnees->pions[k-20] = creer_pion (k-20, donnees,donnees->joueurs[0]->id, donnees->indice_pion_1);
				

		  }
		  }
				   
				

		  }
	}


			}
		

}
void decremente_latence(Data * donnees){

	donnees->latence -= 20;

	if(donnees->latence<=0){
		donnees->latence=0;
	}
	
}

void clavier_saisiepseudo(Data * donnees){

	if(donnees->lancer ){
		donnees->lettreCourante=caractereClavier();
		donnees->toucheAppuyee=true;
		printf("%c\n",donnees->lettreCourante);
	}
	if(donnees->choix_pseudoJ2){

		donnees->lettreCouranteJ2=caractereClavier();
		donnees->toucheAppuyee=true;
		printf("%c\n",donnees->lettreCouranteJ2);
	}
}

void saisie_pseudo(Data * donnees){
	epaisseurDeTrait(4);
	if(donnees->lancer ){	
	if (donnees->lettreCourante==8)
		strcpy(donnees->nomComplet,"");
	if (donnees->toucheAppuyee==true && strlen(donnees->nomComplet)<17 && donnees->lettreCourante!=32 && donnees->lettreCourante!=8){
		printf("%c\n",donnees->lettreCourante);
		sprintf(donnees->nomComplet,"%s%c",donnees->nomComplet,donnees->lettreCourante);
		printf("Variable %s\n",donnees->nomComplet);

	}
		couleurCourante(255, 255, 255);
	afficheChaine(donnees->nomComplet,50,360,300);
	donnees->toucheAppuyee=false;
	}
	if(donnees->choix_pseudoJ2){
	if (donnees->lettreCouranteJ2==8)
		strcpy(donnees->nomCompletJ2,"");
	if (donnees->toucheAppuyee==true && strlen(donnees->nomCompletJ2)<17 && donnees->lettreCouranteJ2!=32 && donnees->lettreCouranteJ2!=8){
		printf("%c\n",donnees->lettreCouranteJ2);
		sprintf(donnees->nomCompletJ2,"%s%c",donnees->nomCompletJ2,donnees->lettreCouranteJ2);
		printf("Variable %s\n",donnees->nomCompletJ2);

	}
		couleurCourante(255, 255, 255);
	afficheChaine(donnees->nomCompletJ2,50,360,300);
	donnees->toucheAppuyee=false;
	}
}



void gestion_menu(Data * donnees) {
	if(donnees->menu == true){
		epaisseurDeTrait(4);
		ecrisImage(0, 0, donnees->fond_menu->largeurImage, donnees->fond_menu->hauteurImage, donnees->fond_menu->donneesRGB);

		if(donnees->menu_principal == true){
			creer_bouton(donnees, "JOUER",610, 250,TAILLE_TEXT);
	
			creer_bouton(donnees, "REGLES",610, 130,TAILLE_TEXT);
			creer_bouton(donnees, "QUITTER",610, 15,TAILLE_TEXT);
		
			if(donnees->latence == 0 && abscisseSouris()<610+LARGEUR_BOUTON && abscisseSouris()>610 && ordonneeSouris()> 250 && ordonneeSouris()<360+HAUTEUR_BOUTON && etatBoutonSouris() == GaucheAppuye){

				donnees->jouer = true;
				donnees->latence = 200;
			}
		
			if(donnees->latence == 0 && abscisseSouris()<610+LARGEUR_BOUTON && abscisseSouris()>610 && ordonneeSouris()> 130 && ordonneeSouris()<130+HAUTEUR_BOUTON && etatBoutonSouris() == GaucheAppuye){
		
				donnees->regle_jeu = true;
				donnees->latence = 200;
			}
			if(donnees->latence == 0 && abscisseSouris()<610+LARGEUR_BOUTON && abscisseSouris()>610 && ordonneeSouris()> 15 && ordonneeSouris()<15+HAUTEUR_BOUTON && etatBoutonSouris() == GaucheAppuye){

				donnees->quitter = true;
				donnees->latence = 200;
			}
		}

		if(donnees->quitter == true){
			exit(1);
		}

	

		if(donnees->regle_jeu == true){
			
			//affiche_bool();
			ecrisImage(0, 0, donnees->img_regles->largeurImage, donnees->img_regles->hauteurImage, donnees->img_regles->donneesRGB);
			
			donnees->menu_principal = creer_bouton_retour(donnees);

		}

		if(donnees->jouer == true){
			ecrisImage(0, 0, donnees->fond_vide->largeurImage, donnees->fond_vide->hauteurImage, donnees->fond_vide->donneesRGB);
			
			creer_bouton(donnees, "LANCER", 300, 300,TAILLE_TEXT);
			donnees->menu_principal = creer_bouton_retour(donnees);

			struct stat fileStat;
			struct stat fileStat1;
    			if(stat("sauvegarde_structures.txt",&fileStat) == 0 && stat("sauvegarde_map.txt",&fileStat1) == 0){
    				creer_bouton(donnees, "CHARGER",500,140, TAILLE_TEXT);
    				if(donnees->latence == 0 && abscisseSouris()<500+LARGEUR_BOUTON && abscisseSouris()>500 && ordonneeSouris()> 350 && ordonneeSouris()<350+HAUTEUR_BOUTON && etatBoutonSouris() == GaucheAppuye){
						reinitialise_plateau(donnees);
						donnees->lancerJeu = true;
						charger_partie(donnees, "sauvegarde_map.txt","sauvegarde_structures.txt");
						donnees->lancerJeu = true;
						maj_bool(donnees);
							
						donnees->latence = 200;
						printf("okfin\n");
						return;

					}
				}
		
			if(donnees->latence == 0 && abscisseSouris()<300+LARGEUR_BOUTON && abscisseSouris()>300 && ordonneeSouris()> 300 && ordonneeSouris()<300+HAUTEUR_BOUTON && etatBoutonSouris() == GaucheAppuye){
				donnees->lancer = true;
				donnees->latence = 200;
				
			}
		}
		
		if(donnees->lancer == true){
			effacer_sauvegarde();
			couleurCourante(255, 255, 255);
		
			ecrisImage(0, 0, donnees->fond_vide->largeurImage, donnees->fond_vide->hauteurImage, donnees->fond_vide->donneesRGB);
			epaisseurDeTrait(4);
			couleurCourante(255, 255, 255);
			ligne(360,280,750,280);
			afficheChaine("PSEUDO J1:",50,35,300);
			creer_bouton(donnees, "OK", 315, 75,TAILLE_TEXT);
			donnees->jouer = creer_bouton_retour(donnees);
			if (donnees->lettreCourante!=13 || donnees->lettreCouranteJ2!=13)
				saisie_pseudo(donnees);
			if (donnees->latence == 0 && (donnees->lettreCourante==13 || donnees->lettreCouranteJ2==13)){
				donnees->lettreCourante='a';
				donnees->lancer = false;
				donnees->choix_pseudoJ2 = true;
				donnees->latence = 400;
			}

			if(donnees->latence == 0 && abscisseSouris()<315+LARGEUR_BOUTON && abscisseSouris()>315 && ordonneeSouris()> 75 && ordonneeSouris()<75+HAUTEUR_BOUTON && etatBoutonSouris() == GaucheAppuye){
				
				donnees->lancer = false;
				donnees->choix_pseudoJ2 = true;
				donnees->latence = 200;
			}

		}

		if(donnees->choix_pseudoJ2 == true){

				ecrisImage(0, 0, donnees->fond_vide->largeurImage, donnees->fond_vide->hauteurImage, donnees->fond_vide->donneesRGB);
				epaisseurDeTrait(4);
				couleurCourante(255, 255, 255);
				ligne(360,280,750,280);
				afficheChaine("PSEUDO J2:",50,35,300);
				creer_bouton(donnees, "OK", 315, 75,TAILLE_TEXT);
				donnees->jouer = creer_bouton_retour(donnees);
				if (donnees->lettreCourante!=13 || donnees->lettreCouranteJ2!=13)
					saisie_pseudo(donnees);

				if (donnees->latence == 0 && (donnees->lettreCourante==13 || donnees->lettreCouranteJ2==13)){
					donnees->lettreCourante='a';
						donnees->lancer = false;
			donnees->choix = true;

					donnees->latence = 200;
				}

				if(donnees->latence == 0 &&abscisseSouris()<315+LARGEUR_BOUTON && abscisseSouris()>315 && ordonneeSouris()> 75 && ordonneeSouris()<75+HAUTEUR_BOUTON && etatBoutonSouris() == GaucheAppuye){
						donnees->lancer = false;
					donnees->choix = true;

					donnees->latence = 200;
				}
			}

	

	
		if(donnees->choix == true){
			assign_pion(donnees);
		}
	}
}

void gestion_fin_partie(Data * donnees) {
	ecrisImage(0, 0, donnees->fond_vide->largeurImage, donnees->fond_vide->hauteurImage, donnees->fond_vide->donneesRGB);
	

	if (donnees->fin_partie_win==true && donnees->fin_partie_loose==false){
		afficheChaine("Vous avez gagne !", 30, 300, 300); 
		//fin_partie_win=false;
	}
	if (donnees->fin_partie_loose==true && donnees->fin_partie_win==false){
		afficheChaine("Vous avez perdu...", 30, 300, 300);
		//donnees->fin_partie_loose=false;
	}

	if (donnees->fin_partie_multi2){
		afficheChaine("Victoire de", 50, 200, 300);
		afficheChaine(donnees->nomCompletJ2, 50, 500, 300);
		//donnees->fin_partie_multi2=false;
	}
	if (donnees->fin_partie_multi1){
		afficheChaine("Victoire de", 50, 200, 300);
		afficheChaine(donnees->nomComplet, 50, 500, 300);
		//donnees->fin_partie_multi1=false;
	}

	creer_bouton(donnees, "MENU",310, 100,TAILLE_TEXT);

	if(donnees->latence == 0 && abscisseSouris()<310+LARGEUR_BOUTON && abscisseSouris()>310 && ordonneeSouris()> 100 
		&& ordonneeSouris()<100+HAUTEUR_BOUTON && etatBoutonSouris() == GaucheAppuye){
		donnees->menu = true;
		donnees->menu_principal = true;
		reinitialise_plateau(donnees);
		donnees->latence = 200;
	}
}
