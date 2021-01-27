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
int head(Liste l);
Liste tail(Liste l);
int isEmpty(Liste l);
Liste insertHead(int x,Liste l);
int isPresent(int x,Liste l);
Liste insertYAfterX(int x,int y,Liste l);
Liste insertTail(int x,Liste l);
Liste deleteX(int x,Liste l);

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