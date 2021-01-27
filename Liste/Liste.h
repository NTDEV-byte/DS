#include<stdio.h>
#include<stdlib.h>
#ifndef ___LIST___
#define ___LIST___

/*
 */

typedef struct cellule
{
	int valeur;
	struct cellule *suivant;
}*Liste;

Liste createNode(int x,Liste l);
int tete(Liste l);
Liste queue(Liste l);
int estVide(Liste l);
Liste insertTete(int x,Liste l);
int appartient(int x,Liste l);
Liste insertXY(int x,int y,Liste l);
Liste insertQueue(int x,Liste l);
Liste supprimer(int x,Liste l);

Liste creationIT(int nombre);
Liste createRecT(int x,Liste l);
Liste createRecNT(int x,Liste l);
void afficheListe(Liste l);
Liste insertKPos(int x,Liste l);
int dernier(Liste l);
Liste doubleListe(Liste l);
int occurence(int x,Liste l);
int recherche(int x,Liste l);
Liste remdup(Liste l);




#endif