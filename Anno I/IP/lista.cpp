#include <iostream>

struct cell {
	int info; //T tipo noto a priori
	cell *tail;
	};
typedef cell*Seq;

bool isEmpty(Seq &l){
	return (l==0);
}

void insertInOrder(Seq &l, int a){
	if(l==0 || a<=l->info){
		cell *aux = new cell;
		aux->info=a;
		aux->tail=l;
		l=aux;
		return;
	} else {
		if(a > l->info){
			insertInOrder(l->tail, a);
		}
	}
}

bool insertLast(Seq &l, int val){
	if(l!=0){
		if(l->tail == 0){
			cell* aux = new cell;
			aux->info = val;
			aux->tail = 0;
			l->tail = aux;
			return true;
		}
		return insertLast(l->tail, val);
	}
	return false;
}

void deleteSeq(Seq &l){
	if (l!=0){
		deleteSeq(l->tail);
		delete l;
		l=0;
	}
}

bool remove(Seq &s, int val){
	if(s!=0){
		if(s->info == val){
			cell* aux = s->tail;
			delete s;
			s = aux;
			return true;
		}
		remove(s->tail, val);
	}
	return false;
}


int deleteAllElemAux(Seq &s, int val, int c){
	int q=c;
	if(s!=0){
		if(s->info == val){
			cell* aux = s->tail;
			delete s;
			s = aux;
			q++;
			deleteAllElemAux(s->tail, val,q);
		}
		deleteAllElemAux(s->tail, val,q);
	}
	return q;
}
int deleteAllElem(Seq &s, int val){
	int q=0;
	if(s!=0){
		deleteAllElemAux(s, val, q);
	}
	return q;
}

void print(Seq&l){
	
	if(l==0){
		return;
	} 
	std::cout << l->info << " | ";
	print(l->tail);
}

bool deletePos_aux(Seq &l, int c, int i){
	if(i<0 || c>i) return false;
	if(c<i && l!=0) return deletePos_aux(l->tail, c+1, i);
	if(c==i){
		cell*aux = l->tail;
		delete l;
		l=aux;
		return true;
	}
	return false;
}
bool deletePos(Seq &l, int index){
	if(index<0){
		return false;
	}
	int cont=0;
	return deletePos_aux(l, cont, index);
}


int main(){
	Seq s = 0;
	std::cout << isEmpty(s);
	insertInOrder(s, 3);
	insertInOrder(s, 5);
	insertInOrder(s, 2);
	insertInOrder(s, 1);
	insertInOrder(s, 80);
	insertInOrder(s, 11);
	std::cout << "\n\nlista: ";
	print(s);
	remove(s, 2);
	std::cout << "\n\nlista: ";
	print(s);
	remove(s, 80);
	std::cout << "\n\nlista: ";
	print(s);
	remove(s, 1);
	std::cout << "\n\nlista: ";
	print(s);
	remove(s, 9999);
	std::cout << "\n\nlista: ";
	print(s);
	insertInOrder(s, 18);
	insertInOrder(s, 110);
	insertInOrder(s, 6);
	insertInOrder(s, 0);
	std::cout << "\n\nlista: ";
	print(s);
	
	deletePos(s, 3);
	std::cout << "\n\n(delete pos 3) lista:\n";
	print(s);
	deletePos(s, 30);
	std::cout << "\n\n(delete pos 30 che non esiste) lista:\n";
	print(s);
	insertInOrder(s, 5);
	/*insertInOrder(s, 5);
	insertInOrder(s, 5);
	insertInOrder(s, 5);
	insertInOrder(s, 5);
	insertInOrder(s, 5);
	insertInOrder(s, 5);*/
	std::cout << "\n\nlista: ";
	print(s);
	/*
	std::cout << "eliminati " << deleteAllElem(s,5) << " elementi";
	std::cout << "\n\nlista: ";
	print(s);
	*/
	
	insertLast(s, 7);
	std::cout << "\n\nlista: ";
	print(s);
	remove(s, 7);
	std::cout << "\n\nlista: ";
	print(s);
	remove(s, 5);
	std::cout << "\n\nlista: ";
	print(s);
}
