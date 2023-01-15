#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
typedef struct livre
{
    int code;
    int numexp;
} livre;
typedef struct emprunt
{
    int num;
    int code_livre;
    int etat;
    char id_abonne[20];
} emprunt;
int menu();
void saisir_livre(livre * p_livre);
void chercher_livre(livre t_livres[],int nl,int code_l,int* pos);
void ajouter_livre(livre t_livres[], int* nl);
void afficher_livres(livre t_livres[], int nl);
void saisir_emprunt(emprunt* p_emprunt);
void ajouter_emprunt(emprunt t_emprunts[],int* ne,livre t_livres[],int nl);
void chercher_emprunt(int num,emprunt t_emprunts[],int ne,int* pos);
void retourner_emprunt(int num,emprunt t_emprunts[],int ne,livre t_livres[],int nl);
void afficher_emprunts_retournes(emprunt t_emprunts[],int ne);
#endif // FUNCTION_H_INCLUDED
