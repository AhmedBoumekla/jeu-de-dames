#include<stdio.h>
#include<stdlib.h>
#include "piece.h"
struct coord_s 
{
	int x;
	int y;
};
typedef struct coord_s coord_t;

struct deplacement_s
{
	coord_t initiale;
	coord_t intermed;
	coord_t finale;
};	
typedef struct deplacement_s deplacement_t;

struct capture_s 
{
	piece_t piece;
	coord_t coord;
};
typedef struct capture_s capture_t ;

struct coup_s 
{
	capture_t piece_capture;	
	int promo;
	piece_t piece;
	deplacement_t dep;
	struct coup_s *suivant;
	struct coup_s *precedent;
};
typedef struct coup_s coup_t;


struct liste_coup_s
{
	coup_t *debut;
	int taille;
};
typedef struct liste_coup_s liste_coup_t;

struct config_s 
{
	piece_t piece;
	coord_t coord;
	struct config_s *suivant;
	struct config_s *precedent;
};
typedef struct config_s config_t;

struct liste_config_s
{
	config_t *debut;
	int taille;
};
typedef struct liste_config_s liste_config_t;


/////////////////////////////////////////////////////////


struct case_s
{
	coord_t coord;
	piece_t contenu;
};
typedef struct case_s case_t;

struct partie_s 
{
	case_t damier[10][10];
	liste_coup_t liste_coup;
	liste_config_t liste_config;
	int tour; 
};
typedef struct partie_s partie_t;



int case_vide(partie_t *jeu,case_t c);

void modifier_case(partie_t *jeu, piece_t p, case_t c);

void changer_joueur(partie_t *jeu);
void affiche_plateau(partie_t jeu);
void modif_damier(partie_t *jeu, deplacement_t deplacement);
coup_t* creer_coup (capture_t cap,int b,deplacement_t dep);
void liste_coup_ajout(liste_coup_t *l,coup_t*coup);
//void annuler_mouvement(partie_t *jeu);

partie_t partie_jouer ();
partie_t *partie_creer();
void partie_detruire(partie_t *partie);
int piece_valide(partie_t partie,deplacement_t dep);
int deplacement_valide(partie_t partie, deplacement_t dep);
int deplacement_valide_dame(partie_t partie,deplacement_t dep);
void partie_sauvegarder (partie_t *partie);
void partie_charger (partie_t *partie);
void annuler_mouvement(partie_t *partie);
void mouvement_sauvegarder (partie_t *partie);
int partie_fin (partie_t partie);
int deplacement_valide_dame2(partie_t jeu,deplacement_t dep);
void prise_mutiple (partie_t *partie, deplacement_t dep);

