#include<stdio.h>
#include<stdlib.h>
#ifndef ___LIST___
#define ___LIST___

/*
 */
//PI
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
void showList(Liste l);

//PII

Liste createITMode(int size);
Liste createRecTMode(Liste l);
Liste createRecNTMode(Liste l);
int lastElement(Liste l);
Liste insertKPos(int x,int position,Liste l);
Liste doubleListe(Liste l);
int maxList(Liste l);
int occurence(int x,Liste l);
int search(int x,Liste l);
Liste remdup(Liste l);




void freeMemory(Liste l);
#endif