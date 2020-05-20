#include <stdio.h>
#include <stdlib.h>


struct piece_s
{
    int joueur;
    char statut;
};
typedef struct piece_s piece_t;

piece_t piece_creer(int player,char s);
void piece_afficher(piece_t p);
int piece_joueur(piece_t piece1);
piece_t piece_identifier(char c);
char piece_caractere(piece_t piece);
