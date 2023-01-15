#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
int menu()
{ int choix;
    do
    {
	printf("*************LE MENU*************\n");
        printf(" --------voici le menu merci de choisir-------- \n");
        printf("--------tapez 0 pour Quitter.--------\n");
        printf("--------tapez 1 pour Ajouter un livre --------\n");
        printf("--------tapez 2 pour Afficher tous les livres --------\n");
        printf("--------tapez 3 pour Ajouter un emprunt --------\n");
        printf("--------tapez 4 pour Retourner un emprunt--------\n");
        printf("--------tapez 5 pour Afficher tous les emprunts retournés --------\n");
        printf("donner votre choix \n");
        scanf("%d",&choix);
    }
    while((choix<0)||(choix>5));
    return choix;
}

void saisir_livre(livre *p_livre)
{
    printf("donner le code \n");
    scanf("%d",&(*p_livre).code);
    printf("donner le numero d'exemplaires disponibles \n");
    scanf("%d",&(*p_livre).numexp);
}

void chercher_livre(livre t_livres[],int nl,int code_l,int *pos){
    int i;
    *pos=-1;
    for(i=0;i<nl && code_l==t_livres[i].code;i++)
    {
         *pos=i;
    }
}

void ajouter_livre(livre t_livres[], int *nl)
{
    int pos;
    livre p_livre;
    saisir_livre(&p_livre);
    chercher_livre(t_livres, &nl, p_livre.code, &pos);
    if (pos != -1)
    {
        t_livres[pos].numexp += p_livre.numexp;
    }
    else
    {
        t_livres[(*nl)] = p_livre;
        (*nl)++;
    }
}
void afficher_livres(livre t_livres[], int nl)
{
    int i;
    for(i=0;i<nl;i++)
    {
        printf("le code : %d\n",t_livres[i].code);
        printf("le numero d'exemplaires disponibles : %d\n",t_livres[i].numexp);
    }
}
void saisir_emprunt(emprunt* p_emprunt)
{
    printf("donner le numero");
    scanf("%d",&(*p_emprunt).num);
    printf("donner le code livre ");
    scanf("%d",&(*p_emprunt).code_livre);
    (*p_emprunt).etat = 0;
    printf("donner le ID");
    fflush(stdin);
    gets((*p_emprunt).id_abonne);
}
void chercher_emprunt(int num,emprunt t_emprunts[],int ne,int* pos)
{
    int i;
    for(i=0;i<ne;i++)
    {
        if(t_emprunts[i].num==num)
            (*pos)=i;
         else
        {
            printf("le livre deja existe\n");
            (*pos)=-1;
        }
    }
}
void afficher_emprunts_retournes(emprunt t_emprunts[], int ne)
{
    int i;
    for(i=0;i<ne;i++)
    {
        if(t_emprunts[i].etat == 1)
            printf("le numero: %d, code: %d, id_abonne: %s\n", t_emprunts[i].num, t_emprunts[i].code_livre, t_emprunts[i].id_abonne);
        else
            printf("aucun emprunt retourne\n");
    }
}
void ajouter_emprunt(emprunt t_emprunts[],int* ne,livre t_livres[],int nl)
{
    int i,pos;
    emprunt e;
    saisir_emprunt (&e);
    chercher_emprunt(e.num,t_emprunts,&ne,&pos);
    if(pos!=-1)
    {
        printf("le livre est introuvable\n");
    }
    else
    {
        chercher_livre(t_livres,nl,e.code_livre,&pos);
        if (pos==-1)
        {
            printf("le livre est introuvable\n");
        }
        else if (t_livres[pos].numexp>=1)
        {
            t_livres[pos].numexp--;
            t_emprunts[(*ne)]=e;
            t_emprunts[(*ne)].etat=1;
            *ne++;
        }
        else{
            printf("livre non dispo\n");
        }
    }
}
void retourner_emprunt(int num,emprunt t_emprunts[],int ne,livre t_livres[],int nl)
{

    int pos_e;
    int pos_l;
    chercher_emprunt(num, t_emprunts, ne, &pos_e);
    if((pos_e != -1) && (t_emprunts[pos_e].etat == 0))
    {
        chercher_livre(t_livres, nl, t_emprunts[pos_e].code_livre, &pos_l);
        if(pos_l != -1){
            t_livres[pos_l].numexp++;
        }
        else{
            printf("\nErreur: Le livre n existe pas.");
        }
        t_emprunts[pos_e].etat = 1;
    }
    else
    {
        printf("\nErreur: L emprunt n existe pas.");
    }
}
