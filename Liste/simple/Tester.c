#include<stdio.h>
#include<stdlib.h>
#include "List.h"


/**
 * Fichier où qui pour tester les fonctions implémentés.
 * 
 */ 



void testInstersectionPointTest(){
    Liste l1 = NULL,l2 = NULL;
    l1 = createNode(30,l1);
    l1 = createNode(15,l1);
    l1 = createNode(9,l1);
    l1 = createNode(6,l1);
    l1 = createNode(3,l1);

      l2 = createNode(10,l2);
      l2->suivant = l1->suivant->suivant->suivant;


     intersectionPoint(l1,l2);

}

void reverseCollectionTest(){
      Liste collection = NULL;

      collection = createNode(5,collection);
            collection = createNode(4,collection);
                  collection = createNode(3,collection);
                        collection = createNode(2,collection);
      collection = createNode(1,collection);


showList(collection);

reverse(collection);

showList(collection);

freeMemory(&collection);
}


