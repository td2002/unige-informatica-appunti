#include <cstddef> // serve per il NULL
#include <iostream>
#include <stdexcept>

#include "token.h"

using namespace std;

// Implementa STACK

namespace stack{

// Gli elementi dello STACK sono token
typedef token Elem;

//typedef token* Stack; // Definizione di Stack fasulla. MODIFICARE!
struct cell;
typedef cell *Stack;
const Stack EMPTYSTACK = NULL;
const int FINEINPUT = -1000000;
const Elem EMPTYELEM = {"fine_stack", SCONOSCIUTO};

bool isEmpty(const Stack&);
void push(const Elem, Stack&);	/* aggiunge elem in cima (operazione safe, si può sempre fare) */
Elem pop(Stack&);	/* toglie dallo stack l'ultimo elemento e lo restituisce; se lo stack è vuoto 
                           viene sollevata un'eccezione) */
}
