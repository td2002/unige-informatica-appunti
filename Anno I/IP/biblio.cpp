#include <iostream>
#include "biblio.h"

bool aux_order(DatiBiblio a, DatiBiblio b){
	return a.titolo < b.titolo;
}

bool add(Schedario &S, DatiBiblio d){
	Scheda *nspunt = nuovaScheda(d);
	if(S!=nullptr){
	
		if(aux_order(d, S->libro)){
			nspunt->next = S;
			S = nspunt;
			return true;
		}
		else return add(S->next, d);
	}
	S = nspunt;
	return true;
}

bool aux_compare(DatiBiblio a, BatiBiblio b){
	return (a.titolo == b.titolo && a.autore == b.autore && a.anno == b.anno);
}
bool is_in(Schedario S, DatiBiblio d){
	if (S!=nullptr){
		if (aux_compare())
	}
}

bool remove(Schedario &S, DatiBiblio d){
	if (S!=nullptr){
		if (aux_compare(S->libro, d)){
			Schedario resto = S->next;
			delete S;
			S = resto;
			return true;
		}
		else return remove(S->next, d);
	}
	else return false;
}

void clear(Schedario &S){
	if (S!=nullptr){
		clear(S->next);
		delete S;
		S = nullptr;
	}
}

void print(Schedario S){
	Schedario cur = S;
	while (cur!=nullptr){
		std::cout << "Autore :" << cur->libro.autore << "\n";
		//eccccc
	}
}
