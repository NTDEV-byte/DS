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
			printf("Warning Loop Detected at %d !!! \n",indexLoop(temp));
			loop++;
			if(loop == 10) return;
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

Liste createLoopAt(int pos,Liste l){ 
	Liste temp = l;
	Liste head = l;

	while(pos > 0){
		   temp = tail(temp);
		   pos--;
	}

	temp->suivant = head;

	return l;
}

int indexLoop(Liste l){
	Liste temp = l;
	Liste fast = tail(tail(temp));
	Liste slow = tail(temp);
	int index = 0;

	while(isEmpty(fast) != 1 && (!(slow == fast))){ 
			fast =  tail(tail(fast));
			slow = tail(slow);
			index++;
	}
	 return index;
}

void removeLoop(Liste *l){
	Liste temp = *l;
	int loopAt = indexLoop(temp);
	int index = loopAt;
	while(loopAt > 1){
		temp = tail(temp);
		loopAt--;
	}
	printf("Loop removed at position %d\n",index);
	temp->suivant = NULL;
}

int findLengthOfLoop(Liste l){
	Liste temp  = l;

	if(isThereALoop(temp)){
		return indexLoop(temp);
	}
		// there is no loop
	return 0;
}
/*
*computers are getting powerful these days
*/
int isPalindrome(Liste l){ 
	Liste headL = l;
	Liste temp = l;
	Liste beforeMid = NULL;
	Liste afterMid = NULL;
	int size = lengthList(temp);
	int index = 0;

	if(size % 2 == 0){
		return 0;
	}
	else{
		while(isEmpty(temp) != 1){ 
			if(index < (size / 2)){
				beforeMid = createNode(head(temp),beforeMid);
			}
			else{
				if(index != (size / 2))
				afterMid = createNode(head(temp),afterMid);
			}
			temp = tail(temp);
			index++;
		}
		int bf = lengthList(beforeMid);
		int af = lengthList(afterMid);

		if(bf != af) return 0;
		else{
			while(isEmpty(afterMid) != 1){
				 if(head(beforeMid) != head(afterMid)){
					 return 0;
				 }
				 afterMid = tail(afterMid);
				 beforeMid = tail(beforeMid);
			}
		return 1;
		}
}
}

// PIIII

void moveLastNodeToFront(Liste *l){
	Liste temp = *l;
	Liste lastNode = NULL;

	while(isEmpty(tail(tail(temp))) != 1){
			temp = tail(temp);
	}
	//we save the adress of the last node 
	lastNode = tail(temp);
	// we make point the before last node to null otherwise it wont stop when we browse the list
	temp->suivant = NULL;

	//rewind 
	temp = *l;
	//point the next of the lastNode to the beginning of our list 
	lastNode->suivant = temp;
	// we move the lastNode  pointer to the start of our list
	*l = lastNode;
}

Liste intersectionSortedList(Liste l1,Liste l2){
Liste temp1 = l1;
Liste temp2 = l2;
Liste result = NULL;
while(isEmpty(temp1) != 1){
  	 while(isEmpty(temp2) != 1){ 
			  if(head(temp1) == head(temp2)){ 
					 result = createNode(head(temp1) , result);
			   }
				temp2 = tail(temp2);
		  	}
		   temp1 = tail(temp1);
		   temp2 = l2;
		}
	return result;
}

/**
 * 
 * Liste swapNodesWithoutSwapData(Liste l,int x,int y){ 
	Liste temp = l;
	Liste n1,n2;

	if(isPresent(x,temp) && isPresent(y,temp)){
		 	while(isEmpty(temp) != 1){ 
				  if(head(temp) == x){ 
					  n1 = temp;
				  }
				  	if(head(temp) == y){ 
						  n2  = temp;
					  }
			 }
			
			
	 n1->suivant = NULL;
	 n2->suivant = NULL;
	 temp = l;

	 
		while(isEmpty(temp) != 1){ 
			if(head(tail(temp)) == x){
				 temp->suivant = n2;
				 n2->suivant = temp->suivant->suivant;
			}
			if(head(tail(temp)) == y){
				 temp->suivant = n1;
				 n1->suivant = temp->suivant->suivant;
			}
		}

		return l;
	}
	else{
		printf("Cannot swipe x or y is missing \n");
	}

	return l;
}
 */ 





