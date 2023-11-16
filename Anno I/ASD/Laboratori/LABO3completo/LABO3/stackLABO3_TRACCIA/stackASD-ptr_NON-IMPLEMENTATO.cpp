#include "stackASD-ptr.h"

using namespace stack;


struct stack::cell {
    Elem	elem;
    cell	*next;
};


/****************************************************************/
bool stack::isEmpty(const Stack& s)
{
return (s==EMPTYSTACK);
}


/****************************************************************/
void stack::push(const Elem x, Stack& s) 
{
	cell*aux = new cell;
	aux->elem = x;
	aux->next = s;
	s = aux;
	return;
}

/****************************************************************/
Elem stack::pop(Stack& s)
{
	if(isEmpty(s)) return EMPTYELEM;
	Elem res = s->elem;
	cell*aux = s;
	s = s->next;
	delete aux;
	return res;
}


/****************************************************************/
Elem stack::top(Stack& s)
{
	if(isEmpty(s)) return EMPTYELEM;
	return s->elem;
}



Stack readFromFile(string nome_file)
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    return readFromStream(ifs);
}



Stack readFromStdin()
{
    cout << "\nInserire una sequenza di numeri separati da spazi seguiti da " <<  FINEINPUT << " per terminare\n";
    return readFromStream((std::cin));
}



Stack readFromStream(istream& str)
{
    Stack s = EMPTYSTACK;
    Elem e;
    str>>e;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    while (e!= FINEINPUT)  // assumiamo che il segnale di fine input nel file sia il numero  FINEINPUT
    {
    push(e, s);
    str>>e;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    }
return s;
}



void print(const Stack& s)
{
cell* aux = s;
cout << endl;
while (aux != EMPTYSTACK)
   {
   cout << aux->elem << "; "; 
   aux = aux->next;
   }
std::cout << endl;
}
