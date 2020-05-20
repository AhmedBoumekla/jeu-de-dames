#include "partie.h"
#define couleur(param) printf("\033[%sm",param)


int case_vide(partie_t *jeu ,case_t c)
{

	if (jeu->damier[c.coord.x][9-(c.coord.y)].contenu.statut == '.')
		return 1;
	else 
		return 0;
}

void modifier_case(partie_t *jeu, piece_t p, case_t c)
{
	if (case_vide(jeu,c)==0) 	
		printf("le déplacement est impossible !\n");
	else 
	{
		jeu->damier[c.coord.x][9-(c.coord.y)].contenu.statut = p.statut;
	}
}


void changer_joueur(partie_t *jeu)
{
    if (jeu->tour == 0) // si c'est le joueur 0 qui a le trait
        jeu->tour = 1;  // c'est au tour du joueur 1 de l'avoir
    else
        jeu->tour = 0; // et inversement
}

void affiche_plateau(partie_t jeu)
{
	printf("\n");
	int i,j,k;
	printf("\t");
	for (k=0;k<10;k++)
	{
		printf("%d\t",k);
	}
	printf("\n");
	for (i=0;i<10;i++)
	{
		printf("%d\t",9-i);
		for(j=0;j<10;j++)
		{
			if (jeu.damier[j][i].contenu.statut == 'X')
			{
				couleur("1;33");
				printf ("⛀\t");  
				couleur("0");
			}
			else if (jeu.damier[j][i].contenu.statut == 'd')
			{
				couleur("1;33");
				printf ("⛁\t");  
				couleur("0");
			}
			else if (jeu.damier[j][i].contenu.statut == 'O')
			{
				couleur("1;36");
				printf ("⛀\t");
				couleur("0");
			}
			else if (jeu.damier[j][i].contenu.statut == 'D')
			{
				couleur("1;36");
				printf ("⛁\t");
				couleur("0");
			}
			else
				printf ("%c\t",jeu.damier[j][i].contenu.statut);
		}
	
		printf("\n\n");
	}
}
coup_t *creer_coup (capture_t cap,int b,deplacement_t dep)
{
	coup_t *res =malloc(sizeof(coup_t));
	res->piece_capture=cap;
	res->promo=b;
	res->dep=dep;
	res->suivant=NULL;
	res->precedent=NULL;
	return res;
}
void liste_coup_ajout(liste_coup_t *l,coup_t*coup)
{
	coup->suivant=l->debut;
	l->debut=coup;
	l->taille++;
}


void modif_damier(partie_t *jeu, deplacement_t deplacement)
{
		
	capture_t cap;
	if ((deplacement.finale.x - deplacement.initiale.x > 2 ) || (deplacement.finale.x - deplacement.initiale.x < -2))
	{
		
		
		if (((jeu->damier[deplacement.initiale.x][9-(deplacement.initiale.y)].contenu.statut) == 'D') || ((jeu->damier[deplacement.initiale.x][9-(deplacement.initiale.y)].contenu.statut) == 'd'))
		{
			
			jeu->damier[deplacement.finale.x][9-(deplacement.finale.y)].contenu.statut = jeu->damier[deplacement.initiale.x][9-(deplacement.initiale.y)].contenu.statut ;
			jeu->damier[deplacement.finale.x][9-(deplacement.finale.y)].contenu.joueur = jeu->damier[deplacement.initiale.x][9-(deplacement.initiale.y)].contenu.joueur ;
			
			jeu->damier[deplacement.initiale.x][9-(deplacement.initiale.y)].contenu.statut = '.';
			jeu->damier[deplacement.initiale.x][9-(deplacement.initiale.y)].contenu.joueur = 3;
			
			
			if(((deplacement.finale.x) > (deplacement.initiale.x) ) && ((deplacement.finale.y) > (deplacement.initiale.y)))
			{
				
				int i,j,r,l,c;
				r=(deplacement.finale.x)-(deplacement.initiale.x);
				
				for (i=1;i<r;i++)
				{	
					l=(deplacement.initiale.x)+i;
					c=9-((deplacement.initiale.y)+i);
					
					jeu->damier[l][c].contenu.statut = '.';
					jeu->damier[l][c].contenu.joueur = 3;
				}
			}
			if(((deplacement.finale.x) > (deplacement.initiale.x) ) && ((deplacement.finale.y) < (deplacement.initiale.y)))
			{
				
				int i,j,r,l,c;
				r=(deplacement.finale.x)-(deplacement.initiale.x);
				
				for (i=1;i<r;i++)
				{	
					l=(deplacement.initiale.x)+i;
					c=9-((deplacement.initiale.y)-i);
					
					jeu->damier[l][c].contenu.statut = '.';
					jeu->damier[l][c].contenu.joueur = 3;
				}
			}
			if(((deplacement.finale.x) < (deplacement.initiale.x) ) && ((deplacement.finale.y) > (deplacement.initiale.y)))
			{
				
				int i,j,r,l,c;
				r=(deplacement.finale.y)-(deplacement.initiale.y);
				
				for (i=1;i<r;i++)
				{	
					l=(deplacement.initiale.x)-i;
					c=9-((deplacement.initiale.y)+i);
					
					jeu->damier[l][c].contenu.statut = '.';
					jeu->damier[l][c].contenu.joueur = 3;
				}
			}
			if(((deplacement.finale.x) < (deplacement.initiale.x) ) && ((deplacement.finale.y) < (deplacement.initiale.y)))
			{
				
				int i,j,r,l,c;
				r=(deplacement.initiale.x)-(deplacement.finale.x);
				
				for (i=1;i<r;i++)
				{	
					l=(deplacement.initiale.x)-i;
					c=9-((deplacement.initiale.y)-i);
					
					jeu->damier[l][c].contenu.statut = '.';
					jeu->damier[l][c].contenu.joueur = 3;
				}
			}
						
		}
			
		
	}




	else if ((deplacement.finale.x - deplacement.initiale.x == 1 ) || (deplacement.finale.x - deplacement.initiale.x == -1))
	{
		jeu->damier[deplacement.finale.x][9-(deplacement.finale.y)].contenu.statut = jeu->damier[deplacement.initiale.x][9-deplacement.initiale.y].contenu.statut ;
		jeu->damier[deplacement.finale.x][9-(deplacement.finale.y)].contenu.joueur = jeu->damier[deplacement.initiale.x][9-(deplacement.initiale.y)].contenu.joueur ;
		jeu->damier[deplacement.initiale.x][9-(deplacement.initiale.y)].contenu.statut = '.';
		jeu->damier[deplacement.initiale.x][9-(deplacement.initiale.y)].contenu.joueur = 3;
		
	}
	else if ((deplacement.finale.x - deplacement.initiale.x == 2 ) || (deplacement.finale.x - deplacement.initiale.x == -2))  
	{

		jeu->damier[deplacement.finale.x][9-(deplacement.finale.y)].contenu.statut = jeu->damier[deplacement.initiale.x][9-(deplacement.initiale.y)].contenu.statut ;
		jeu->damier[deplacement.finale.x][9-(deplacement.finale.y)].contenu.joueur = jeu->damier[deplacement.initiale.x][9-(deplacement.initiale.y)].contenu.joueur ;
		jeu->damier[deplacement.initiale.x][9-(deplacement.initiale.y)].contenu.statut = '.';
		jeu->damier[deplacement.initiale.x][9-(deplacement.initiale.y)].contenu.joueur = 3;
		
		jeu->damier[((deplacement.initiale.x)+(deplacement.finale.x))/2][9-(((deplacement.initiale.y)+(deplacement.finale.y))/2)].contenu.statut='.';
		jeu->damier[((deplacement.initiale.x)+(deplacement.finale.x))/2][9-(((deplacement.initiale.y)+(deplacement.finale.y))/2)].contenu.joueur=3;
		

	}
	if (jeu->tour==0) 
	{
		if ((deplacement.finale.x - deplacement.initiale.x == 2 ) || (deplacement.finale.x - deplacement.initiale.x == -2) || (deplacement.finale.x - deplacement.initiale.x == 1 ) || (deplacement.finale.x - deplacement.initiale.x == -1))
		{
			
			if((deplacement.finale.y) == 9)
				jeu->damier[deplacement.finale.x][9-(deplacement.finale.y)].contenu.statut ='D';
				jeu->damier[deplacement.finale.x][9-(deplacement.finale.y)].contenu.joueur =0;
		}
	}
	if (jeu->tour==1) 
	{
		if ((deplacement.finale.x - deplacement.initiale.x == 2 ) || (deplacement.finale.x - deplacement.initiale.x == -2) || (deplacement.finale.x - deplacement.initiale.x == 1 ) || (deplacement.finale.x - deplacement.initiale.x == -1))
		{
			if((deplacement.finale.y) == 0)
				jeu->damier[deplacement.finale.x][9-(deplacement.finale.y)].contenu.statut ='d';
				jeu->damier[deplacement.finale.x][9-(deplacement.finale.y)].contenu.joueur =1;
		}
			
	}
	
}



/*void annuler_mouvement(partie_t *jeu)
{
	if (jeu->liste_coup.taille == 0 )
		printf("il n'y a pas encore de mouvement joué");
	else 
	{
		deplacement_t dep_precedent ;
		dep_precedent.initiale = jeu->liste_coup.debut->dep.finale;
		dep_precedent.finale = jeu->liste_coup.debut->dep.initiale;
		if ((dep_precedent.finale.x - dep_precedent.initiale.x == 1 ) || (dep_precedent.finale.x - dep_precedent.initiale.x == -1))
		{
			jeu->damier[dep_precedent.finale.x][dep_precedent.finale.y].contenu.statut = jeu->damier[dep_precedent.initiale.x][dep_precedent.initiale.y].contenu.statut ;
			jeu->damier[dep_precedent.initiale.x][dep_precedent.initiale.y].contenu.statut = '.';
			if(jeu->tour == 0)
			{
				if (jeu->liste_coup.debut->promo == 1)
					jeu->damier[dep_precedent.finale.x][dep_precedent.finale.y].contenu.statut='p';
			}
			else
			{
				if (jeu->liste_coup.debut->promo == 1)
					jeu->damier[dep_precedent.finale.x][dep_precedent.finale.y].contenu.statut='P';
			}
		}
		else
		{
			jeu->damier[dep_precedent.finale.x][dep_precedent.finale.y].contenu.statut = jeu->damier[dep_precedent.initiale.x][dep_precedent.initiale.y].contenu.statut ;
			jeu->damier[dep_precedent.initiale.x][dep_precedent.initiale.y].contenu.statut = '.';
			jeu->damier[((dep_precedent.finale.x)+(dep_precedent.initiale.x))/2][((dep_precedent.finale.y)+(dep_precedent.initiale.y))/2].contenu = jeu->liste_coup.debut->piece_capture.piece;
			if(jeu->tour == 0)
			{
				if (jeu->liste_coup.debut->promo == 1)
					jeu->damier[dep_precedent.finale.x][dep_precedent.finale.y].contenu.statut='p';
			}
			else
			{
				if (jeu->liste_coup.debut->promo == 1)
					jeu->damier[dep_precedent.finale.x][dep_precedent.finale.y].contenu.statut='P';
			}

		}
	}
}

*/
			

partie_t* partie_creer()
{
	partie_t* res = malloc(sizeof(partie_t));	
	liste_coup_t *l = malloc(sizeof(liste_coup_t));
	l->debut == NULL;
	l->taille=0;
	return res;
}

void partie_detruire(partie_t *partie)
{
	free(partie);
}

partie_t partie_jouer ()
{
	partie_t partie;
	int i,j;
	for (i=0;i<4;i=i+2)
	{
		for (j=0;j<10;j=j+2)
		{
			partie.damier[j][i].contenu.statut=' ';
			partie.damier[j][i].contenu.joueur=3;
		}	
		for (j=1;j<10;j=j+2)
		{
			partie.damier[j][i].contenu.statut='X';
			partie.damier[j][i].contenu.joueur = 1;
		}
	}
	for (i=1;i<5;i=i+2)
	{
		for (j=1;j<10;j=j+2)
		{
			partie.damier[j][i].contenu.statut=' ';
			partie.damier[j][i].contenu.joueur=3;
		}
		for (j=0;j<10;j=j+2)
		{
			partie.damier[j][i].contenu.statut='X';
			partie.damier[j][i].contenu.joueur = 1;
		}
			
	}	
	for (j=0;j<10;j=j+2)
	{
		partie.damier[j][4].contenu.statut=' ';
		partie.damier[j][i].contenu.joueur=3;
	}
	for (j=1;j<10;j=j+2)
	{
		partie.damier[j][4].contenu.statut='.';	
		partie.damier[j][i].contenu.joueur=3;
	}

	for (j=0;j<10;j=j+2)
	{
		partie.damier[j][5].contenu.statut='.';
		partie.damier[j][i].contenu.joueur=3;
	}
	for (j=1;j<10;j=j+2)
	{
		partie.damier[j][5].contenu.statut=' ';	
		partie.damier[j][i].contenu.joueur=3;
	}

	for (i=6;i<10;i=i+2)
	{
		for (j=0;j<10;j=j+2)
		{
			partie.damier[j][i].contenu.statut=' ';
			partie.damier[j][i].contenu.joueur=3;
		}
		for (j=1;j<10;j=j+2)
		{
			partie.damier[j][i].contenu.statut='O';
			partie.damier[j][i].contenu.joueur = 0;
		}
			
	}
	for (i=7;i<10;i=i+2)
	{
		for (j=1;j<10;j=j+2)
		{
			partie.damier[j][i].contenu.statut=' ';
			partie.damier[j][i].contenu.joueur=3;
		}
		for (j=0;j<10;j=j+2)
		{
			partie.damier[j][i].contenu.statut='O';
			partie.damier[j][i].contenu.joueur = 0;
		}
			
	
	}
	return partie;
}
int deplacement_valide(partie_t partie,deplacement_t dep)
{
	if ( partie.tour == partie.damier[dep.initiale.x][9-(dep.initiale.y)].contenu.joueur)
	{
		if (piece_valide(partie,dep))
		{
			if ((dep.finale.x - dep.initiale.x == 1 ) || (dep.finale.x - dep.initiale.x == -1))
			{
				if((partie.tour == 0) && (dep.finale.y < dep.initiale.y)&&(partie.damier[dep.initiale.x][9-(dep.initiale.y)].contenu.statut !='D'))
					return 6;
				if((partie.tour == 1) && (dep.finale.y > dep.initiale.y)&&(partie.damier[dep.initiale.x][9-(dep.initiale.y)].contenu.statut !='d'))
					return 6;
			}
			if (((dep.finale.x - dep.initiale.x > 2 ) || (dep.finale.x - dep.initiale.x < -2)))
			{
					if ((partie.damier[dep.initiale.x][9-(dep.initiale.y)].contenu.statut =='D') || (partie.damier[dep.initiale.x][9-(dep.initiale.y)].contenu.statut =='d'))
						{
							
							if (deplacement_valide_dame2(partie,dep)==0)
							{
								
								return 7;
							}
							else
							{
								
								return 1;
							}
						}
					else
						return 5;
							
			}
				
			if (((dep.finale.x - dep.initiale.x == 2 ) || (dep.finale.x - dep.initiale.x == -2)) && (partie.damier[dep.initiale.x][9-(dep.initiale.y)].contenu.statut !='D') && (partie.damier[dep.initiale.x][9-(dep.initiale.y)].contenu.statut !='d')) 
			{
				if ((partie.damier[((dep.initiale.x)+(dep.finale.x))/2][9-(((dep.initiale.y)+(dep.finale.y))/2)].contenu.statut == '.')) 
					return 5;
				else if (partie.tour != (partie.damier[((dep.initiale.x)+(dep.finale.x))/2][9-(((dep.initiale.y)+(dep.finale.y))/2)].contenu.joueur))			
					return 1;
				else
					return 4;
			}
			else
				return 1;
		}
		else
			return 2;
	}
	else
		return 3;
}

int piece_valide(partie_t partie, deplacement_t dep)
{	
	case_t c;
	c.coord.x=dep.finale.x;
	c.coord.y=dep.finale.y;
	
	if (case_vide(&partie ,c))
		return 1;
	else
		return 0;
}

int deplacement_valide_dame(partie_t partie,deplacement_t dep)
{

		
		if(((dep.finale.x) > (dep.initiale.x) ) && ((dep.finale.y) > (dep.initiale.y)))
		{
				
				int i,j,r,l,c,g,joueur;
				r=(dep.finale.x)-(dep.initiale.x);
				joueur=partie.damier[dep.initiale.x][9-(dep.initiale.y)].contenu.joueur;

				for (i=1;i<r;i++)
				{	
					
					l=(dep.initiale.x)+i;
					c=9-((dep.initiale.y)+i);
					g=9-((dep.initiale.y)+i+1);
					if (i==1)
					{	
						if ((partie.damier[l][c].contenu.joueur == 0 )|| (partie.damier[l][c].contenu.joueur == 1))
						{
							printf ("LLLLL\n");
							if ((partie.damier[l+1][g].contenu.joueur == 0) || (partie.damier[l+1][g].contenu.joueur == 1))
							{
								return 0;
								printf ("ZZZZ\n");
							}
						}
					}
					else
					{	
						if (partie.damier[l][c].contenu.joueur == joueur)
							return 0; //il y a un pion du meme joueur dans la diagonal
						if ((partie.damier[l][c].contenu.joueur == 0 )|| (partie.damier[l][c].contenu.joueur == 1))
						{
							if ((partie.damier[l+1][c+1].contenu.joueur == 0) || (partie.damier[l+1][c+1].contenu.joueur == 1))
					  			return 0;
						}

					}

				}
				return 1;
		}
		if(((dep.finale.x) > (dep.initiale.x) ) && ((dep.finale.y) < (dep.initiale.y)))
		{
				
				int i,j,r,l,c,joueur;
				r=(dep.finale.x)-(dep.initiale.x);
				joueur=partie.damier[dep.initiale.x][9-(dep.initiale.y)].contenu.joueur;

				for (i=1;i<r;i++)
				{	
					
					l=(dep.initiale.x)+i;
					c=9-((dep.initiale.y)-i);
					if (i==1)
					{	
						if ((partie.damier[l][c].contenu.joueur == 0 )|| (partie.damier[l][c].contenu.joueur == 1))
						{
							if ((partie.damier[l+1][c-1].contenu.joueur == 0) || (partie.damier[l-1][c+1].contenu.joueur == 1))
							{
								printf("XXXX\n");
								return 0;
							}
						}
					}
					else
					{	
						if (partie.damier[l][c].contenu.joueur == joueur)
						{
							printf("KKKK\n");
							return 0; //il y a un pion du meme joueur dans la diagonal
						}
						if ((partie.damier[l][c].contenu.joueur == 0 )|| (partie.damier[l][c].contenu.joueur == 1))
						{
							if ((partie.damier[l+1][c-1].contenu.joueur == 0) || (partie.damier[l+1][c-1].contenu.joueur == 1))
							{
					  			printf("MMMM\n");
								return 0;
							}
						}

					}

				}
				return 1;
		}
		if(((dep.finale.x) < (dep.initiale.x) ) && ((dep.finale.y) > (dep.initiale.y)))
		{
				
				int i,j,r,l,c,joueur;
				r=(dep.finale.y)-(dep.initiale.y);
				joueur=partie.damier[dep.initiale.x][9-(dep.initiale.y)].contenu.joueur;

				for (i=1;i<r;i++)
				{	
					
					l=(dep.initiale.x)-i;
					c=9-((dep.initiale.y)+i);
					if (i==1)
					{	
						if ((partie.damier[l][c].contenu.joueur == 0 )|| (partie.damier[l][c].contenu.joueur == 1))
						{
							if ((partie.damier[l-1][c+1].contenu.joueur == 0) || (partie.damier[l-1][c+1].contenu.joueur == 1))
							{
								printf("vvvv\n");
								return 0;
							}
						}
					}
					else
					{	
						if (partie.damier[l][c].contenu.joueur == joueur)
						{
							printf("FFF\n");
							return 0; //il y a un pion du meme joueur dans la diagonal
						}
						if ((partie.damier[l][c].contenu.joueur == 0 )|| (partie.damier[l][c].contenu.joueur == 1))
						{
							if ((partie.damier[l-1][c+1].contenu.joueur == 0) || (partie.damier[l-1][c+1].contenu.joueur == 1))
							{
								printf("BBB\n");
					  			return 0;
							}
						}

					}

				}
				return 1;
		}
		if(((dep.finale.x) < (dep.initiale.x) ) && ((dep.finale.y) < (dep.initiale.y)))
		{
				
				int i,j,r,l,c,joueur;
				r=(dep.initiale.x)-(dep.finale.x);
				joueur=partie.damier[dep.initiale.x][9-(dep.initiale.y)].contenu.joueur;

				for (i=1;i<r;i++)
				{	
					
					l=(dep.initiale.x)-i;
					c=9-((dep.initiale.y)-i);
					if (i==1)
					{	
						if ((partie.damier[l][c].contenu.joueur == 0 )|| (partie.damier[l][c].contenu.joueur == 1))
						{
							printf ("loolloo\n");
							if ((partie.damier[l-1][c-1].contenu.joueur == 0) || (partie.damier[l-1][c-1].contenu.joueur == 1))
								return 0;
						}
					}
					else
					{	
						printf("nnnnnn\n");
						if (partie.damier[l][c].contenu.joueur == joueur)
						{
							printf("bbbbb\n");
							return 0; //il y a un pion du meme joueur dans la diagonal
						}
						if ((partie.damier[l][c].contenu.joueur == 0 )|| (partie.damier[l][c].contenu.joueur == 1))
						{
							printf("hhhhh\n");
							if ((partie.damier[l-1][c-1].contenu.joueur == 0) || (partie.damier[l-1][c-1].contenu.joueur == 1))
							{
									printf("ggggg\n");
					  			return 0;
							}
						}

					}

				}
				return 1;
		}
	
}
void partie_sauvegarder (partie_t *partie)
{
	char nom[20];
	printf("donnez le nom de votre sauvgarde (max 20 caractere): ");
	scanf("%s",nom);
	strcat(nom,".pl");
	FILE* fichier =NULL;
	int i,j;
	fichier = fopen(nom,"a");
	if (fichier !=NULL)
	{
		for (i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				fprintf(fichier,"%c",partie->damier[j][i].contenu.statut);
				fprintf(fichier,"%d",partie->damier[j][i].contenu.joueur);
			}
						
		}
		fprintf(fichier,"%d",partie->tour);
	}
	fclose(fichier);
	couleur("1;35");
	printf("******** partie sauvegardée avec succés ********\n");
	couleur("0");
}

void partie_charger (partie_t *partie)
{
				char nom[20];
				printf("donnez le nom de la partie que vous voulez charger : ");
				scanf("%s",nom);
				strcat(nom,".pl");
				FILE* fichier =NULL;
				int i,j;
				fichier = fopen(nom,"r+");
				if (fichier !=NULL)
				{
					for (i=0;i<10;i++)
					{
						
						for(j=0;j<10;j++)
						{
							fscanf(fichier,"%c",&partie->damier[j][i].contenu.statut);
							fscanf(fichier,"%d",&partie->damier[j][i].contenu.joueur);
						}
						 
					}
				}
				fscanf(fichier,"%d",partie->tour);
				fclose(fichier);
				printf("\033[H\033[J");
				couleur("1;35");
				printf("******** partie chargée avec succés ********\n");
				couleur("0");

}		
void annuler_mouvement(partie_t *partie)
{
				FILE* fichier =NULL;
				int i,j;
				fichier = fopen("sauvegarde.txt","r+");
				if (fichier !=NULL)
				{
					for (i=0;i<10;i++)
					{
						
						for(j=0;j<10;j++)
						{
							fscanf(fichier,"%c",&partie->damier[j][i].contenu.statut);
							fscanf(fichier,"%d",&partie->damier[j][i].contenu.joueur);
						} 
					}

				}
				changer_joueur(partie);
				fclose(fichier);
				
}

void mouvement_sauvegarder (partie_t *partie)
{
	FILE* fichier =NULL;
	int i,j;
	remove("sauvegarde.txt");
	fichier = fopen("sauvegarde.txt","a");
	if (fichier !=NULL)
	{
		for (i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				fprintf(fichier,"%c",partie->damier[j][i].contenu.statut);
				fprintf(fichier,"%d",partie->damier[j][i].contenu.joueur);
			}
						
		}
		
	}
	
	fclose(fichier);
}
int partie_fin (partie_t partie)
{
	int i,j,joueur0,joueur1;
	joueur0=0;
	joueur1=0;
	for (i=0;i<10;i++)
	{
		for (j=0;j<10;j++)
		{
			if ((partie.damier[j][i].contenu.statut == 'X'	) || (partie.damier[j][i].contenu.statut == 'd'	))
				joueur1 +=1;
			if ((partie.damier[j][i].contenu.statut == 'O'	) || (partie.damier[j][i].contenu.statut == 'D'	))
				joueur0 +=1;
		}
	}
	if (joueur1==0)
	{
		
		return 0 ;
	} //joueur 0 a gagné 
	if (joueur0 ==0)
	{
		
		return 1 ; //joueur 1 a gagné 
	}
	if ((joueur0 !=0) && (joueur1 !=0))
	{
		
		return 3 ; //la partie n'est pas encore fini 
	}
}
	
int deplacement_valide_dame2(partie_t jeu,deplacement_t dep)
{
	if (jeu.damier[dep.initiale.x][9-(dep.initiale.y)].contenu.statut == 'd')
	{
		if(((dep.finale.x) > (dep.initiale.x) ) && ((dep.finale.y) > (dep.initiale.y)))
		{
				int i,j,r,l,c;
				r=(dep.finale.x)-(dep.initiale.x);
				
				for (i=1;i<r;i++)
				{	
					l=(dep.initiale.x)+i;
					c=9-((dep.initiale.y)+i);
					if((jeu.damier[l][c].contenu.statut == 'X') || (jeu.damier[l][c].contenu.statut == 'd'))
					{
						return 0; //ya un pion du meme joueur
					}
					if ((jeu.damier[l][c].contenu.statut == 'O') || (jeu.damier[l][c].contenu.statut == 'D'))
					{
						l=(dep.initiale.x)+(i+1);
						c=9-((dep.initiale.y)+(i+1));
						if (jeu.damier[l][c].contenu.statut == 'O')
						{
							return 0;
						}
						
					}
				}
				return 1;
			
			
		}
		if(((dep.finale.x) > (dep.initiale.x) ) && ((dep.finale.y) < (dep.initiale.y)))
		{
				int i,j,r,l,c;
				r=(dep.finale.x)-(dep.initiale.x);
				
				for (i=1;i<r;i++)
				{	
					l=(dep.initiale.x)+i;
					c=9-((dep.initiale.y)-i);
					if((jeu.damier[l][c].contenu.statut == 'X') || (jeu.damier[l][c].contenu.statut == 'd'))
					{
						return 0; //ya un pion du meme joueur
					}
					if ((jeu.damier[l][c].contenu.statut == 'O') || (jeu.damier[l][c].contenu.statut == 'D'))
					{
						l=(dep.initiale.x)+(i+1);
						c=9-((dep.initiale.y)-(i+1));
						if (jeu.damier[l][c].contenu.statut == 'O')
						{
							return 0;
						}
						
					}
				}
				return 1;
			
		}
		if(((dep.finale.x) < (dep.initiale.x) ) && ((dep.finale.y) > (dep.initiale.y)))
		{
				int i,j,r,l,c;
				r=(dep.initiale.x)-(dep.finale.x);
				
				for (i=1;i<r;i++)
				{	
					l=(dep.initiale.x)-i;
					c=9-((dep.initiale.y)+i);
					if((jeu.damier[l][c].contenu.statut == 'X') || (jeu.damier[l][c].contenu.statut == 'd'))
					{
						return 0; //ya un pion du meme joueur
					}
					if ((jeu.damier[l][c].contenu.statut == 'O') || (jeu.damier[l][c].contenu.statut == 'D'))
					{
						l=(dep.initiale.x)-(i+1);
						c=9-((dep.initiale.y)+(i+1));
						if (jeu.damier[l][c].contenu.statut == 'O')
						{
							return 0;
						}
						
					}
				}
				return 1;
			
		}
		if(((dep.finale.x) < (dep.initiale.x) ) && ((dep.finale.y) < (dep.initiale.y)))
		{
				int i,j,r,l,c;
				r=(dep.initiale.x)-(dep.finale.x);
				
				for (i=1;i<r;i++)
				{	
					l=(dep.initiale.x)-i;
					c=9-((dep.initiale.y)-i);
					if((jeu.damier[l][c].contenu.statut == 'X') || (jeu.damier[l][c].contenu.statut == 'd'))
					{
						return 0; //ya un pion du meme joueur
					}
					if ((jeu.damier[l][c].contenu.statut == 'O') || (jeu.damier[l][c].contenu.statut == 'D'))
					{
						l=(dep.initiale.x)-(i+1);
						c=9-((dep.initiale.y)-(i+1));
						if (jeu.damier[l][c].contenu.statut == 'O')
						{
							return 0;
						}
						
					}
				}
				return 1;
			
		}
	}
	if (jeu.damier[dep.initiale.x][9-(dep.initiale.y)].contenu.statut == 'D')
	{
		if(((dep.finale.x) > (dep.initiale.x) ) && ((dep.finale.y) > (dep.initiale.y)))
		{
				
				int i,j,r,l,c;
				r=(dep.finale.x)-(dep.initiale.x);
				
				for (i=1;i<r;i++)
				{	
					l=(dep.initiale.x)+i;
					c=9-((dep.initiale.y)+i);
					if((jeu.damier[l][c].contenu.statut == 'O') || (jeu.damier[l][c].contenu.statut == 'D'))
					{
						return 0; //ya un pion du meme joueur
					}
					if ((jeu.damier[l][c].contenu.statut == 'X') || (jeu.damier[l][c].contenu.statut == 'd'))
					{
						l=(dep.initiale.x)+(i+1);
						c=9-((dep.initiale.y)+(i+1));
						if (jeu.damier[l][c].contenu.statut == 'X')
						{
							
							return 0;
						}
						
					}
				}
				return 1;
			
			
		}
		if(((dep.finale.x) > (dep.initiale.x) ) && ((dep.finale.y) < (dep.initiale.y)))
		{
				
				int i,j,r,l,c;
				r=(dep.finale.x)-(dep.initiale.x);
				
				for (i=1;i<r;i++)
				{	
					l=(dep.initiale.x)+i;
					c=9-((dep.initiale.y)-i);
					if((jeu.damier[l][c].contenu.statut == 'O') || (jeu.damier[l][c].contenu.statut == 'D'))
					{
						
						return 0; //ya un pion du meme joueur
					}
					if ((jeu.damier[l][c].contenu.statut == 'X') || (jeu.damier[l][c].contenu.statut == 'd'))
					{
						l=(dep.initiale.x)+(i+1);
						c=9-((dep.initiale.y)-(i+1));
						if (jeu.damier[l][c].contenu.statut == 'X')
						{
							return 0;
						}
						
					}
				}
				return 1;
			
		}
		if(((dep.finale.x) < (dep.initiale.x) ) && ((dep.finale.y) > (dep.initiale.y)))
		{
				
				int i,j,r,l,c;
				r=(dep.initiale.x)-(dep.finale.x);
				
				for (i=1;i<r;i++)
				{	
					l=(dep.initiale.x)-i;
					c=9-((dep.initiale.y)+i);
					if((jeu.damier[l][c].contenu.statut == 'O') || (jeu.damier[l][c].contenu.statut == 'D'))
					{
				
						return 0; //ya un pion du meme joueur
					}
					if ((jeu.damier[l][c].contenu.statut == 'X') || (jeu.damier[l][c].contenu.statut == 'd'))
					{
						l=(dep.initiale.x)-(i+1);
						c=9-((dep.initiale.y)+(i+1));
						if (jeu.damier[l][c].contenu.statut == 'X')
						{
				
							return 0;
						}
						
					}
				}
				return 1;
			
		}
		if(((dep.finale.x) < (dep.initiale.x) ) && ((dep.finale.y) < (dep.initiale.y)))
		{
				
				int i,j,r,l,c;
				r=(dep.initiale.x)-(dep.finale.x);
				
				for (i=1;i<r;i++)
				{	
					l=(dep.initiale.x)-i;
					c=9-((dep.initiale.y)-i);
					if((jeu.damier[l][c].contenu.statut == 'O') || (jeu.damier[l][c].contenu.statut == 'D'))
					{
						
						return 0; //ya un pion du meme joueur
					}
					if ((jeu.damier[l][c].contenu.statut == 'X') || (jeu.damier[l][c].contenu.statut == 'd'))
					{
						l=(dep.initiale.x)-(i+1);
						c=9-((dep.initiale.y)-(i+1));
						if (jeu.damier[l][c].contenu.statut == 'X')
						{
							
							return 0;
						}
						
					}
				}
				return 1;
			
		}
	}
	
}
/*
void prise_mutiple (partie_t *partie, deplacement_t dep)
{
	deplacement_t dep2,dep3;
	int choix;
	
	if ((partie->damier[dep.initiale.x][9-(dep.initiale.y)].contenu.statut !='D') && (partie->damier[dep.initiale.x][9-(dep.initiale.y)].contenu.statut !='d')) 
	{
		if (((dep.finale.x - dep.initiale.x == 2 ) || (dep.finale.x - dep.initiale.x == -2)))
		{
			if (partie->damier[dep.initiale.x][9-(dep.initiale.y)].contenu.statut =='X')
			{
				dep2.initiale.x= dep.finale.x;
				dep2.initiale.y= dep.finale.y;
				dep2.finale.x= dep.finale.x+2;
				dep2.finale.y= dep.finale.y-2;
				dep3.initiale.x= dep.finale.x;
				dep3.initiale.y= dep.finale.y;
				dep3.finale.x= dep.finale.x-2;
				dep3.finale.y= dep.finale.y-2;
				if (deplacement_valide(partie,dep2)==1)
				{
					if (deplacement_valide(partie,dep3)==1)
					{
						print("vous avez deux possibilité, pour aller a droite tapez 1 sinon tapez 2:");
						scanf ("%d",&choix);
						if (choix==1)
						{
							modif_damier(partie, dep);
							modif_damier(partie, dep2);
						}
						else
						{
							modif_damier(partie, dep);
							modif_damier(partie, dep3);
						}
					}
					else 
					{
						modif_damier(partie, dep);
						modif_damier(partie, dep2);
					}
				}
				else 
				{
					if (deplacement_valide(partie,dep3)==1)
					{
						modif_damier(partie, dep);
						modif_damier(partie, dep3);
					}
					else
						modif_damier(partie, dep);
						
				}		
			}
			if (partie->damier[dep.initiale.x][9-(dep.initiale.y)].contenu.statut =='O')
			{
				dep2.initiale.x= dep.finale.x;
				dep2.initiale.y= dep.finale.y;
				dep2.finale.x= dep.finale.x+2;
				dep2.finale.y= dep.finale.y+2;
				dep3.initiale.x= dep.finale.x;
				dep3.initiale.y= dep.finale.y;
				dep3.finale.x= dep.finale.x-2;
				dep3.finale.y= dep.finale.y+2;
				if (deplacement_valide(partie,dep2)==1)
				{
					if (deplacement_valide(partie,dep3)==1)
					{
						print("vous avez deux possibilité, pour aller a droite tapez 1 sinon tapez 2:");
						scanf ("%d",&choix);
						if (choix==1)
						{
							modif_damier(partie, dep);
							modif_damier(partie, dep2);
						}
						else
						{
							modif_damier(partie, dep);
							modif_damier(partie, dep3);
						}
					}
					else 
					{
						modif_damier(partie, dep);
						modif_damier(partie, dep2);
					}
				}
				else 
				{
					if (deplacement_valide(partie,dep3)==1)
					{
						modif_damier(partie, dep);
						modif_damier(partie, dep3);
					}
					else
						modif_damier(partie, dep);
						
				}	
			}
		}
		else
			modif_damier(partie,dep);
	}
	else
		modif_damier(partie,dep);
}
		
*/						
						



								
			
						
						
	
	
	
	



	






