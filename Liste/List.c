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
	 while(estVide(temp)!=1){
		  if(tete(temp) == x){ 
			  return 1;
		  }
		  temp = queue(temp);
	 }
	 return 0;
}

Liste insertYAfterX(int x,int y,Liste l){ 
	Liste temp = l;
	int tours = 0;
	while(estVide(temp)!= 1){ 
		if(tete(temp)!=x){
			temp = queue(temp);
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

	if(estVide(temp)){ 
		temp = result;
		return temp;
	}

	while((estVide(queue(temp)))!= 1){
		temp = queue(temp);
	}

	temp->suivant = result;

	return l;
}

Liste deleteX(int x,Liste l){
	Liste temp = l;
	Liste prec = NULL;

	if(estVide(temp)){ 
		return l;
	}else{

		while(estVide(temp)!= 1){
			 if(tete(temp) != x){
 			 prec = temp;
			 temp = queue(temp);
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


void afficheListe(Liste l){ 
	Liste temp = l;
	while(temp!=NULL){ 

		printf("[%d]->",temp->valeur);
		temp = temp->suivant;
	}
	printf("\n");
	printf("parcours terminer !\n");
}