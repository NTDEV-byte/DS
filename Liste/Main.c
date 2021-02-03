#include<stdio.h>
#include<stdlib.h>
#include "List.h"
#include "Tester.h"

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

void intersectionPoint();
int main(int argc,char **argv){

testInstersectionPointTest();


  //  freeMemory(&c1);
    return EXIT_SUCCESS;

}