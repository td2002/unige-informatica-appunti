#include "queue.h"

using namespace queue;


/****************************************************************/
/* 			FUNZIONI SULLE CODE 			*/
/****************************************************************/

/****************************************************************/

Queue queue::createEmpty()
{
   Queue q;
   q.size = 0;
   q.maxsize = BLOCKDIM;
   q.info = new Elem[BLOCKDIM];
   return q;
}
void queue::enqueue(Elem e, Queue& l) // aggiunge e in coda
{
	
	for (int i=l.size; i>0; --i){
		l.info[i] = l.info[i-1];
	}
	l.info[0] = e;
	l.size++;
	cout << "token: " << e.val << " k " << e.k << "\n";
	return;
}


/****************************************************************/
Elem queue::dequeue(Queue& l) // rimuove il primo elemento e lo restituisce
{
	Elem empty = {"fine", SCONOSCIUTO};
  if (isEmpty(l)) return empty;
	
	l.size--;
	return l.info[l.size];
}

/****************************************************************/
bool queue::isEmpty(const Queue& l)
{
  // DA IMPLEMENTARE 
   return (!l.size);
}

/****************************************************************/
