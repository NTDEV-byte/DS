#include<stdio.h>
#include<stdlib.h>
#include "List.h"

Liste getDefaultList(){
    Liste collection = NULL;
    collection = createNode(9,collection);
       collection = createNode(8,collection);
                  collection = createNode(7,collection);
                        collection = createNode(6,collection);
                 collection = createNode(5,collection);
          collection = createNode(4,collection);
     collection = createNode(3,collection);
         collection = createNode(2,collection);
             collection = createNode(1,collection);
}

Liste customize(){
    Liste collection = NULL;
    collection = createNode(1,collection);
    collection = createNode(1,collection);
       collection = createNode(2,collection);
    collection = createNode(1,collection);
      collection = createNode(1,collection);
   return collection;
}


int main(int argc,char **argv){

    Liste c1 = NULL,c2 = NULL,res = NULL;
       c1 = createRecTMode(c1);
       c2 = createRecTMode(c2);
       res = intersectionSortedList(c1,c2);
          showList(c1);
          showList(c2);
          showList(res);

  /**
  * to avoid memory leaks 
  */
   freeMemory(&c1);freeMemory(&c2);freeMemory(&res);
    return EXIT_SUCCESS;

}