#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

int main()
{
    int i,nl=0,choix,ne=0,num;
    livre t_livres[100];
    emprunt t_emprunts[100];

    do
    {
        choix = menu();
        switch(choix)
        {
        case 0:
            printf("au revoir");
            break;
        case 1:
            ajouter_livre(t_livres, &nl);
            break;
        case 2:
            afficher_livres(t_livres, nl);
            break;
        case 3:
            ajouter_emprunt(t_emprunts, &ne, t_livres, nl);
            break;
        case 4:
            printf("\nEntrer le numero de l emprunt: ");
            scanf("%d", &num);
            retourner_emprunt(num, t_emprunts, ne, t_livres, nl);
            break;
        case 5:
            afficher_emprunts_retournes(t_emprunts, ne);
            break;
        }
    } while (choix != 0);

    return 0;
}
