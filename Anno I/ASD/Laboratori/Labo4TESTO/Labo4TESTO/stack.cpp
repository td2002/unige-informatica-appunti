#include "stack.h"

using namespace stack;

/****************************************************************/
struct stack::cell {
    Elem	elem;
    cell	*next;
};

bool stack::isEmpty(const Stack& s)
{
	return (s==EMPTYSTACK);
    // DA IMPLEMENTARE
}

/****************************************************************/
void stack::push(const Elem x, Stack& s) 
{
    // DA IMPLEMENTARE
    cell*aux = new cell;
	aux->elem = x;
	aux->next = s;
	s = aux;
	return;
}

/****************************************************************/
Elem stack::pop(Stack& s)
{
    // DA IMPLEMENTARE
	if(isEmpty(s)) return EMPTYELEM;
	Elem res = s->elem;
	cell*aux = s;
	s = s->next;
	delete aux;
	return res;
}

/****************************************************************/

