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
void freeMemory(Liste *l);

//PII

Liste createITMode(int size);
Liste createRecTMode(Liste l);
Liste createRecNTMode(Liste l);
int lastElement(Liste l);
Liste insertKPos(int x,int position,Liste l);
Liste doubleListe(Liste l);
int max(int a,int b);
int maxList(Liste l);
int occurence(int x,Liste l);
int search(int x,Liste l);
Liste remdup(Liste l);
Liste remdupRec(Liste l);

//PIII

int lengthList(Liste l);
int searchRec(int x,Liste l);
int getElementAt(int pos,Liste l);
int getElementSFE(int pos,Liste l);
int getMiddleElement(Liste l);
int isThereALoop(Liste l);
Liste createLoopAt(int pos,Liste l);
int indexLoop(Liste l);
void removeLoop(Liste *l);
int findLengthOfLoop(Liste l);
int isPalindrome(Liste l);


// PIIII
void moveLastNodeToFront(Liste *l);
Liste intersectionSortedList(Liste l1,Liste l2);
Liste getElement(int x,Liste l);
void intersectionPoint(Liste l1,Liste l2);
Liste reverse(Liste l);
//Liste QuickSortLKL(Liste l);
//Liste pairAvantImpair(Liste l);
//Liste swapNodesWithoutSwapData(Liste l,int x,int y);








#endif