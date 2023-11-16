// Implementa le funzioni sulle liste realizzate con strutture doppiamente collegate, circolari, con sentinella, senza ordinamento

// FILE DA MODIFICARE

#include "ASD-doubly-linked-list.h"


using namespace list;

struct list::node {  // descrivo qui, fuori dal namespace, come e' fatta la struttura node: i dettagli interni non saranno visibili dal main
    Elem info;
    node *prev;
    node *next;
};

/*************************************************/
/* Implementazione delle operazioni di utilita'  */
/*************************************************/

void readFromStream(istream& str, List& l) {
    createEmpty(l);
    Elem e;
    str>>e;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    // assumiamo che il segnale di fine input nel file sia  FINEINPUT
    while (e != FINEINPUT)  {     
        addRear(e, l);   // aggiunge l'elemento alla fine della lista
        str>>e;
        if (!str) throw runtime_error("Errore inserimento dati\n");
    }
}

/* legge il contenuto di una lista da file */
void readFromFile(string nome_file, List& l) {
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    readFromStream(ifs, l);
}


/* legge il contenuto di una lista da standard input */
void readFromStdin(List& l) {
   cout << "\nInserire una sequenza di numeri separati da spazi seguiti da " << FINEINPUT << " per terminare\n";
   readFromStream((std::cin), l);
}

/* stampa la lista */
void print(const List& l) {
   List q = l->next;  // q "salta la sentinella" e va alla testa della lista
   while (q != l) {   // avanza finche' non finisce la lista
      cout << q->info << "; ";
      q = q->next; 
    }
}

/**************************************************/
/* Implementazione delle operazioni nel namespace */
/**************************************************/

/* crea la lista vuota */
void list::createEmpty(List& l) {
	node* aux = new node;
	aux->info = EMPTYELEM;
	aux->prev = aux;
	aux->next = aux;
	l = aux;
}

/* "smantella" la lista svuotandola */
void list::clear(const List& l) {
	List aux = l->next;
	node* loc;
	while(aux->info!=EMPTYELEM){
		loc = aux->next;
		aux->next->prev=aux->prev;
		aux->prev->next=aux->next;
		delete aux;
		aux=loc;
		
	}
}

/* restituisce l'elemento in posizione pos se presente; restituisce un elemento 
che per convenzione si decide che rappresenta l'elemento vuoto altrimenti*/
Elem list::get(int pos, const List& l) {
	node* aux = l->next;
	for(int i=0; aux->info!=EMPTYELEM; ++i){
		if(i==pos){
			return aux->info;
		}
		aux = aux->next;
	}
	return EMPTYELEM;
}

/* modifica l'elemento in posizione pos, se la posizione e' ammissibile */
void list::set(int pos, Elem e, const List& l) {
	if (pos >= size(l)) return;
	
	node* loc = l->next;
	for(int i=0; i<pos; ++i) loc=loc->next;
	
	loc->info = e;
   
}

/* inserisce l'elemento in posizione pos, shiftando a destra gli altri elementi */
void list::add(int pos, Elem e, const List& l) {   
	if(pos>size(l)) return;
	                                            
	node* aux = new node;
	aux->info = e;
	
	node* loc = l->next;
	for(int i=0; i<pos; ++i) loc=loc->next;
	
	aux->prev = loc->prev;
	aux->next = loc;
	loc->prev->next = aux;
	loc->prev = aux;
}

/* inserisce l'elemento alla fine della lista */
void list::addRear(Elem e,  const List& l) {
	node* aux = new node;
	aux->info = e;
	aux->prev = l->prev;
	aux->next = l;
	l->prev->next = aux;
	l->prev = aux;
}

/* inserisce l'elemento all'inizio della lista */
void list::addFront(Elem e, const List& l) {
	node* aux = new node;
	aux->info = e;
	aux->prev = l;
	aux->next = l->next;
	l->next->prev = aux;
	l->next = aux;
}

/* cancella l'elemento in posizione pos dalla lista */
void list::removePos(int pos, const List& l) {
	if (pos>size(l)) return;
	
	node* loc = l->next;
	for(int i=0; i<pos; ++i) loc=loc->next;
	
	loc->prev->next = loc->next;
	loc->next->prev = loc->prev;
	delete loc;
}

 /* cancella tutte le occorrenze dell'elemento elem, se presenti, dalla lista */
void list::removeEl(Elem e, const List& l) {
	node* aux = l->next;
	while(aux!=l){
		
		//controllo ed eventuale elimina
		if(aux->info==e){
			//elimina
			node*loc=aux;
			loc->prev->next = loc->next;
			loc->next->prev = loc->prev;
			delete loc;
		}
		aux=aux->next;
	}
}

/* restituisce true se la lista e' vuota (ed e' vuota se il next di l, e' l stessa */
bool list::isEmpty(const List& l) {
	return (l->next == l);
}

 /* restituisce la dimensione della lista */
int list::size(const List& l) {
	int i=0;
	List q = l->next;  // q "salta la sentinella" e va alla testa della lista
	while (q != l) {   // avanza finche' non finisce la lista
		++i;
		q = q->next; 
    }
    return i;
}


