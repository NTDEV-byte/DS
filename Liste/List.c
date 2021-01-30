#include "List.h"


//PI
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
	Liste head = l;
	int loop = 0;
	while(temp!=NULL){ 
		printf("[%d]->",temp->valeur);
		temp = temp->suivant;
		if(temp == head){ 
			printf("Warning Loop Detected !!! \n");
			loop++;
			printf("loop: %d\n",loop);
		}
	}
	printf("\n");
	printf("parcours terminer !\n");
}

void freeMemory(Liste *l){
	Liste current = *l;
	Liste next = NULL;

	while(isEmpty(current) != 1){ 
		next = current->suivant;
		free(current);
		current = NULL;
		current = next;
	}

	printf("Memory Free !\n");
}

Liste createLoop(Liste l){ 
	Liste temp = l;
	Liste head = l;

	while(isEmpty(tail(temp)) != 1){
		   temp = tail(temp);
	}

	temp->suivant = head;

	return l;
}



//PII

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

int max(int a,int b){
	return (a > b) ? a : b;
}

int maxList(Liste l){ 
	Liste temp = l;
	int maxV = head(temp);
	temp = tail(temp);
	while(isEmpty(temp) != 1){
		  maxV = max(maxV,head(temp));
		  temp = tail(temp);
	}
	return maxV;
}

int occurence(int x,Liste l){
	 Liste temp = l;
	 int occ = 0;

	 while(isEmpty(temp) != 1){
		if(head(temp) == x){ 
			occ++;
		}
		temp = tail(temp);
	 }
	 return occ;
}

int search(int x,Liste l){
	Liste temp = l;
	while(isEmpty(temp) != 1){ 
		if(head(temp) == x){ 
			return 1;
		}
		temp = tail(temp);
	}
	return 0;
}

Liste remdup(Liste l){ 
	Liste temp = l;
	while(isEmpty((temp)) != 1){ 
		   if(search(head(temp),tail(temp))){
			   l = deleteX(head(temp) , l);
		   }
		temp = tail(temp);
	}
return l;
}

Liste remdupRec(Liste l){
	if(l == NULL){ 
		return l;
	}	
	else 
		if(search(head(l) , tail(l))){
			return remdup(tail(l));
		}
		else{
			return  createNode(head(l),remdup(tail(l)));
		}
}




//PIII

int lengthList(Liste l){ 
	Liste temp = l;
	int size = 0;
	while(isEmpty(temp) != 1){
		 size++;
		 temp = tail(temp);
	}
	return size;
}

int searchRec(int x,Liste l){ 
	if(isEmpty(l)){
		return 0;
	}
	else
		if(head(l) == x){
			 return 1;
		}
		else{
			return searchRec(x,tail(l));
		}
}

int getElementAt(int pos,Liste l){
	Liste temp = l;
	while(pos > 0){ 
		temp = tail(temp);
		pos--;
	}
	return head(temp);
}

int getElementSFE(int pos,Liste l){ 
	Liste temp = l;
	int size = lengthList(temp);
	printf("size: %d\n",size);
	int index = size - pos;
	if(index >= 0){ 
		while(index >= 1){ 
			index--;
			temp = tail(temp);
		}
	return head(temp);
	}
	else{
		printf("Invalid location !\n");
	}
	return -1;
}
int getMiddleElement(Liste l){ 
	Liste temp = l;
	int size = lengthList(temp);
	int mid = size / 2;

	while(mid > 0){ 
		temp = tail(temp);
		mid--;
	}
	return head(temp);
}

int isThereALoop(Liste l){
	Liste temp = l;
	Liste fast = tail(tail(temp));
	Liste slow = tail(temp);

	while(isEmpty(fast) != 1 && (!(slow == fast))){ 
			fast =  tail(tail(fast));
			slow = tail(slow);
	}

	 return (isEmpty(fast)) ? 0 : 1;
}



int findLengthOfLoop(Liste l);
int isPalindrome(Liste l);
void swapNodes(Liste l);
void moveLastNodeToFront(Liste l);









