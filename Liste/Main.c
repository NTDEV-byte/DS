#include<stdio.h>
#include<stdlib.h>
#include "List.h"

Liste getDefaultList(){
    Liste collection = NULL;
    collection = createNode(8,collection);
       collection = createNode(15,collection);
                  collection = createNode(20,collection);
                        collection = createNode(30,collection);
                 collection = createNode(45,collection);
          collection = createNode(50,collection);
     collection = createNode(150,collection);
}

int main(int argc,char **argv){
    Liste collection = NULL;
    collection = getDefaultList();
    collection = doubleListe(collection);
    showList(collection);
 
 /**
  * to avoid memory leaks 
  */
    freeMemory(collection);


    
    return EXIT_SUCCESS;

}