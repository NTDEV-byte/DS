#include "List.h"

Liste createNode(int x,Liste l){
	Liste L = malloc(sizeof(Liste));
	L->valeur = x;
	L->suivant = l;
	return L;
}

int head(Liste l){
	return l->valeur;
}
Liste tail(Liste l) {
	return l->suivant;
}

int isEmpty(Liste l){ 
	if(l == NULL){ 
		return 1;
	}
	return 0;
}

Liste insertHead(int x,Liste l){
	return createNode(x,l);
}

int isPresent(int x,Liste l){
	 Liste temp = l;
	 while(isEmpty(temp)!=1){
		  if(head(temp) == x){ 
			  return 1;
		  }
		  temp = tail(temp);
	 }
	 return 0;
}

Liste insertYAfterX(int x,int y,Liste l){ 
	Liste temp = l;
	int tours = 0;
	while(isEmpty(temp)!= 1){ 
		if(head(temp)!=x){
			temp = tail(temp);
		}
		else{
				temp->suivant = createNode(y,temp->suivant);
				return l;
		}
	}
	return l;
}

Liste insertTail(int x,Liste l){
	Liste temp = l;
	Liste result = createNode(x,NULL);

	if(isEmpty(temp)){ 
		temp = result;
		return temp;
	}

	while((isEmpty(tail(temp)))!= 1){
		temp = tail(temp);
	}

	temp->suivant = result;

	return l;
}

Liste deleteX(int x,Liste l){
	Liste temp = l;
	Liste prec = NULL;

	if(isEmpty(temp)){ 
		return l;
	}else{

		while(isEmpty(temp)!= 1){
			 if(head(temp) != x){
 			 prec = temp;
			 temp = tail(temp);
			 }
			
			else if(prec == NULL){
				 return temp->suivant;
			}
			 else
			 	{
					 prec->suivant = temp->suivant;
					 return l;
				 }
		}
	} 
	return l;
}

void showList(Liste l){ 
	Liste temp = l;
	while(temp!=NULL){ 

		printf("[%d]->",temp->valeur);
		temp = temp->suivant;
	}
	printf("\n");
	printf("parcours terminer !\n");
}


Liste createITMode(int size){

	Liste collection = NULL;	
	int input;

	for(int i=0;i<size;i++){
		printf("Plz enter a value to push to the list: '-1' -> Exit \n");
		scanf("%d",&input);
		if(input == -1){ 
			printf("++++++++++++++++++ \n");
			printf("Abort All ... \n");
			printf("++++++++++++++++++\n");
			return collection;
		}
			collection = createNode(input,collection);
	}

	printf("++++++++++++++++++++++++\n");
	printf("Collection created !\n");
	printf("++++++++++++++++++++++++\n");

return collection;
}

Liste createRecTMode(Liste l){
	int x;
	printf("Enter a value to push [-1] -> Exit \n");
	scanf("%d",&x);
	if(x == -1){
		 return l;
	}
	else{
		return createRecTMode(createNode(x,l));
	}
}

Liste createRecNTMode(Liste l){ 
	int x;
	printf("Enter a value to push [-1] -> Exit \n");
	scanf("%d",&x);
	if(x == -1){ 
		return l;
	}
	else{
		return createNode(x,createRecNTMode(l));
	}
}

int lastElement(Liste l){
	Liste temp = l;
	
	while(isEmpty(tail(temp)) != 1){
		  temp = tail(temp);
	}

	return head(temp);
}

Liste insertKPos(int x,int position,Liste l){ 
	Liste temp = l;
	while(position > 1){ 
		temp = tail(temp);
		position--;
	}
	temp->suivant = createNode(x,temp->suivant);
	return l;
}

Liste doubleListe(Liste l){
	Liste temp = l;
	while(isEmpty(tail(temp)) != 1){
		 temp->suivant = createNode(head(temp),temp->suivant);
		 temp = tail(tail(temp));
	}
	return l;
}


int maxList(Liste l);
int occurence(int x,Liste l);
int search(int x,Liste l);
Liste remdup(Liste l);


void freeMemory(Liste l){
	Liste temp = l;
	Liste cell = NULL;
	
	while(isEmpty(temp) != 1){ 
		cell = temp;
		temp = tail(temp);
		free(cell);
	}

	printf("Memory cleaned ! \n");
}