#include "piece.h"
#include <string.h>


piece_t piece_creer(int player, char stat)
{
    piece_t resultat;
    resultat.joueur = player;
    resultat.statut=stat;
    return resultat;
}

int piece_joueur(piece_t piece1)
{
    return piece1.joueur;
}

piece_t piece_identifier(char c)
{
    if ((c=='p')|| (c=='d'))
        return piece_creer(0, c);
    else 
        return piece_creer(1, c);
}

char piece_caractere(piece_t piece)
{
    return piece.statut;
}

void piece_afficher(piece_t p)
{
    printf("statut = %c\n",p.statut);
}

