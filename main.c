#include <stdio.h>
#include <stdlib.h>
#include "partie.h"
#define couleur(param) printf("\033[%sm",param)

// projet exo 1.1


int main () 
{
	FILE* fichier =NULL;
	int i,j;
	printf("\033[H\033[J");
	couleur("1;36");
	printf("********************************************************************\n");
	couleur("1;33");
	printf("****                  JEU DE DAMES V3.0                         ****\n");
	printf("****                                                            ****\n");
	printf("****                   ENJOY !!                                 ****\n");
	printf("****                                                            ****\n");
	printf("****                                              :)            ****\n");
	couleur("1;36");
	printf("********************************************************************\n");
	couleur("0");
	sleep(3);
	partie_t partie=partie_jouer ();
	printf("\033[H\033[J");
	affiche_plateau(partie);
	partie.tour=0;
	while(partie_fin (partie)==3)
	{
		if(partie.tour == 0 )
		{
			int nbr,i,r;
			couleur("1;36");
			printf("*******************************\n** c'est le tour de joueur 0 **\n*******************************\n");
			deplacement_t dep;
			printf ("*** pour jouer un coup tapez 0\n*** pour sauvegrader la partie tapez 1\n*** pour charger une partie tapez 2\n*** pour quitter tapez 3 \n*** pour annuler le coup tapez 4\n votre choix: ");
			scanf ("%d",&r);
			if (r==4)
			{
				annuler_mouvement(&partie);
				printf("\033[H\033[J");
				affiche_plateau(partie);
			}
			if (r==1)
			{
				partie_sauvegarder (&partie);
			}
			if (r==3)
			{
				printf("A bientot! \n");
        remove("sauvegarde.txt");	
				return EXIT_SUCCESS;
			}
			if (r==2)
			{
				partie_charger (&partie);	
     	
				printf("\033[H\033[J");
				affiche_plateau(partie);
			}		
			
			if (r==0)
			{
				mouvement_sauvegarder (&partie);
				printf ("est-ce que votre deplacement est une prise multiple? si oui tapez le nombre de deplacement, sinon tapez 1: \n ");
				scanf ("%d",&nbr);
				couleur ("0");
				for (i=0;i<nbr;i++)
				{
					do
					{  
						couleur("1;36");
						printf("donnez x de la case init: ");
						scanf("%d",&dep.initiale.x);
						printf("donnez y de la case init: ");
						scanf("%d",&dep.initiale.y);
						printf("donnez x de la case final: ");
						scanf("%d",&dep.finale.x);
						printf("donnez y de la case final: ");
						scanf("%d",&dep.finale.y);
						couleur("0");
						if ((deplacement_valide(partie,dep))==3)
						{
							couleur("1;35");
							printf("ce n'est pas votre tour !\n");
							couleur("0");
						}
						if ((deplacement_valide(partie,dep))==2)
						{
							couleur("1;35");
							printf("la case est occupee!\n");
							couleur("0");
						}
						if ((deplacement_valide(partie,dep))==4)
						{
							couleur("1;35");
							printf("vous pouvez pas manger vos propre pion!\n");
							couleur("0");
						}
						if ((deplacement_valide(partie,dep))==5)
						{
							couleur("1;35");
							printf("vous pouvez pas vous deplacer plus d'une case sans manger !\n");
							couleur("0");
						}
						if ((deplacement_valide(partie,dep))==6)
						{
							couleur("1;35");
							printf("vous pouvez pas revenr en arriere !\n");
							couleur("0");
						}
						if ((deplacement_valide(partie,dep))==7)
						{
							couleur("1;35");
							printf("la dame ne peut pas faire ce deplacement!\n");
							couleur("0");
						}
						
						
						
					} while((deplacement_valide(partie,dep))==3 ||(deplacement_valide(partie,dep))==2 ||(deplacement_valide(partie,dep))==4 ||(deplacement_valide(partie,dep))==5 ||(deplacement_valide(partie,dep))==6 ||(deplacement_valide(partie,dep))==7) ;	
					
					modif_damier(&partie, dep);			
					printf("\033[H\033[J");
					affiche_plateau(partie);	
				}
				partie.tour =1;
			}
		}
		if(partie.tour == 1 )
		{	
			int nbr,i,j,r;
			couleur("1;33");				  
			printf("*******************************\n** c'est le tour de joueur 1 **\n*******************************\n");
			deplacement_t dep;
			printf ("*** pour jouer un coup tapez 0\n*** pour sauvegrader la partie tapez 1\n*** pour charger une partie tapez 2\n*** pour quitter tapez 3 \n*** pour annuler le coup tapez 4\n votre choix: ");
			scanf ("%d",&r);
			if (r==4)
			{
				annuler_mouvement(&partie);
				printf("\033[H\033[J");
				affiche_plateau(partie);
			}
			if (r==1)
			{
				partie_sauvegarder (&partie);
			}
			if (r==3)
			{
				printf("A bientot! \n");
        remove("sauvegarde.txt");	
				return EXIT_SUCCESS;
			}
			if (r==2)
			{
				partie_charger (&partie);		
				printf("\033[H\033[J");
				affiche_plateau(partie);
			}	
			if (r==0)
			{
				mouvement_sauvegarder (&partie);
				printf ("est-ce que votre deplacement est une prise multiple? si oui tapez le nombre de deplacement, sinon tapez 1: \n");
				scanf ("%d",&nbr);
				couleur("0");
				for (i=0;i<nbr;i++)
				{
					do
					{  
						couleur("1;33");
						printf("donnez x de la case init: ");
						scanf("%d",&dep.initiale.x);
						printf("donnez y de la case init: ");
						scanf("%d",&dep.initiale.y);
						printf("donnez x de la case final: ");
						scanf("%d",&dep.finale.x);
						printf("donnez y de la case final: ");
						scanf("%d",&dep.finale.y);
						couleur("0");
						if ((deplacement_valide(partie,dep))==3)
						{
							couleur("1;35");
							printf("ce n'est pas votre tour !\n");
							couleur("0");
						}
						if ((deplacement_valide(partie,dep))==2)
						{
							couleur("1;35");
							printf("la case est occupee!\n");
							couleur("0");
						}
						if ((deplacement_valide(partie,dep))==4)
						{
							couleur("1;35");
							printf("vous pouvez pas manger vos propre pion!\n");
							couleur("0");
						}
						if ((deplacement_valide(partie,dep))==5)
						{
							couleur("1;35");
							printf("vous pouvez pas vous deplacer plus d'une case sans manger !\n");
							couleur("0");
						}
						if ((deplacement_valide(partie,dep))==6)
						{
							couleur("1;35");
							printf("vous pouvez pas revenr en arriere !\n");
							couleur("0");
						}
						if ((deplacement_valide(partie,dep))==7)
						{
							couleur("1;35");
							printf("la dame ne peut pas faire ce deplacement!\n");
							couleur("0");
						}
						
					}while((deplacement_valide(partie,dep))==3 || (deplacement_valide(partie,dep))==2 ||(deplacement_valide(partie,dep))==4 ||(deplacement_valide(partie,dep))==5 ||(deplacement_valide(partie,dep))==6 ||(deplacement_valide(partie,dep))==7);
										
					modif_damier(&partie, dep);
					
					printf("\033[H\033[J");
					affiche_plateau(partie);
				}
				partie.tour =0;
			}
		}
	}
	if (partie_fin (partie)==0)
	{
		couleur("1;35");
		printf("la partie est finie, le joueur BLEU a gagné !!!\n");
		couleur("0");
    remove("sauvegarde.txt");
		return EXIT_SUCCESS;
	}
	if (partie_fin (partie)==1)
	{
		couleur("1;35");
		printf("la partie est finie, le joueur JAUNE a gagné !!!\n");
		couleur("0");
    remove("sauvegarde.txt");
		return EXIT_SUCCESS;
	}

		
	
}


