#include "queueASD-array.h"

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
   q.queue = new Elem[BLOCKDIM];
   return q;
}

/****************************************************************/

Queue checksize(Queue& q){
	if(q.size >= q.maxsize){
		q.maxsize = q.maxsize + BLOCKDIM;
		Elem*aux = new Elem[q.maxsize+BLOCKDIM];
		
		for (int i=0; i<q.size; ++i){
			aux[i] = q.queue[i];
		}
		
		Elem*del = q.queue;
		q.queue = aux;
		delete del;
		
		printf("\n\nsize %d, max %d\n\n",q.size,q.maxsize);
		
		return q;
	}
	
	if(q.size < (q.maxsize-BLOCKDIM)){
		q.maxsize = q.maxsize - BLOCKDIM;
		Elem*aux = new Elem[q.maxsize-BLOCKDIM+1];
		
		for (int i=0; i<q.size; ++i){
			aux[i] = q.queue[i];
		}
		
		Elem*del = q.queue;
		q.queue = aux;
		delete del;
		
		printf("\n\nsize %d, max %d\n\n",q.size,q.maxsize);
		
		return q;
	}
	
	printf("\n\nsize %d, max %d\n\n",q.size,q.maxsize);
	return q;
}

void queue::enqueue(Elem e, Queue& l) // aggiunge e in coda
{

	l = checksize(l);
	
	for (int i=l.size; i>0; --i){
		l.queue[i] = l.queue[i-1];
	}
	l.queue[0] = e;
	l.size++;
	return;
}


/****************************************************************/
Elem queue::dequeue(Queue& l) // rimuove il primo elemento e lo restituisce
{
	if (isEmpty(l)) return EMPTYELEM;
	checksize(l);
	
	l.size--;
	return l.queue[l.size];
}


/****************************************************************/
Elem queue::first(Queue& l) // restituisce il primo elemento
{
	if (isEmpty(l)) return EMPTYELEM;
	return l.queue[l.size-1];
}


/****************************************************************/
bool queue::isEmpty(const Queue& l)
{
   return (!l.size);
}



/****************************************************************/
Queue readFromFile(string nome_file)
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    return readFromStream(ifs);
}


/****************************************************************/
Queue readFromStdin()
{
    cout << "\nInserire una sequenza di numeri separati da spazi seguiti da " << FINEINPUT << " per terminare\n";
    return readFromStream((std::cin));
}


/****************************************************************/
Queue readFromStream(istream& str)
{
    Queue l = createEmpty();        
    int dato;
    str>>dato;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    while (dato!= FINEINPUT)  // assumiamo che il segnale di fine input nel file sia  FINEINPUT
        {     
        enqueue(dato, l);   // aggiunge l'elemento alla fine della coda
        str>>dato;
        if (!str) throw runtime_error("Errore inserimento dati\n");
        }
return l;
}

/****************************************************************/
void print(const Queue& l)
{
cout << endl;
for (int i=0; i<l.size; ++i)
   cout << l.queue[i] << "; "; 
cout << endl;
}
