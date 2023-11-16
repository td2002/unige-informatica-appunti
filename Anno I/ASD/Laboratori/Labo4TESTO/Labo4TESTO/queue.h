#include <iostream>
#include <stdexcept>

#include "token.h"
	
using namespace std;

// Implementa QUEUE 
namespace queue{


// Gli elementi della QUEUE sono token
typedef token Elem;       

const int BLOCKDIM = 1000;
const int FINEINPUT = -1000000;
//const Elem EMPTYELEM = {-100000, 6};
typedef struct{
	Elem* info;
    int size;
    int maxsize;
} Queue; // Definizione di Queue fasulla. MODIFICARE!

Queue createEmpty();
bool isEmpty(const Queue&);
void enqueue(Elem, Queue&);  /* inserisce l'elemento alla fine della lista */
Elem dequeue(Queue&);        /* cancella l'elemento in prima posizione (se esiste) e lo restituisce */
}
