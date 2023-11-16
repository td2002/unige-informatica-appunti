#include <iostream>

struct cell{
	int info;
	cell* next;
	cell* prev;
};
typedef cell* list;

void addFirst(list &l, int x){

	
		cell* aux = new cell;
		aux->info=x;
		
		aux->prev=0;
			if(l!=0){
				aux->next = l;
		l->prev=aux;
	}
}

int main(){
	list lista;
	addFirst(lista, 3);
}
