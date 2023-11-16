#include "dictionary.h"

#include <math.h> // sqrt()

using namespace dict;

struct dict::cell {
        Elem	elem;
 	    cell	*next;
};


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
int h1(Key s) // funzione di hash che considera unicamente il valore ascii del primo carattere della chiave (se esiste) e restituisce il resto della divisione di tale valore per tableDim 
{
 // implementare la funzione richiesta e modificare il return 
int c = (int)s[0];
 return (c%tableDim);
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
int h2(Key s) // funzione di hash che somma il codice ascii di ogni carattere nella chiave e restituisce il resto della divisione di tale somma per tableDim 
{
 // implementare la funzione richiesta e modificare il return 
int i=0;
int somma=0;
while(s[i] != '\0'){
	somma += (int)s[i];
	++i;
}
 return (somma%tableDim);
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
int h3(Key s) // funzione di hash diversa da h1 ed h2, che progettate e implementate voi seguendo qualche criterio che vi sembra ragionevole
{
 // implementare la funzione richiesta e modificare il return 
int i=1;
int somma=0;
while(s[i] != '\0'){
	somma += (int)s[i];
	++i;
}
 return (somma%tableDim);
}

/****************************************************************/
/*    FUNZIONE DA MODIFICARE PER FARE ESPERIMENTI DIVERSI       */
/****************************************************************/
int h(Key s)
{
   return h1(s); // modificare questa chiamata per sperimentare l'utilizzo delle funzioni di hash h1, h2, h3, definite prima
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
Error dict::deleteElem(const Key k, Dictionary& s)
{	
int bucket = h(k);
if(s[bucket] == emptyBucket){
	return FAIL;  
} else {
	cell* aux = s[bucket];
	if(aux->elem.key == k){
		if(aux->next == emptyBucket){
			delete aux;
			s[bucket] = emptyBucket;
			return OK;
		}
		cell*loc = aux;
		aux = aux->next;
		delete loc;
		return OK;
	} else {
		while(aux->next != emptyBucket){
			if(aux->next->elem.key == k){
				//allora cancello
				cell* loc = aux->next;
				aux->next = aux->next->next;
				delete loc;
				return OK;
			}
			aux = aux->next;
		}
	}
}
return FAIL;
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
Value dict::search(const Key k, const Dictionary& s)
{	
int bucket = h(k);
if(s[bucket] == emptyBucket){
	return emptyValue;  
} else {
	cell* aux = s[bucket];
	if(aux->elem.key == k){
		return aux->elem.value;
	}
	while(aux->next != emptyBucket){
		if(aux->elem.key == k){
			return aux->elem.value;
		}
		aux = aux->next;
	}
}
return emptyValue;
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
Error dict::insertElem(const Key k, const Value v,  Dictionary& s)
{
int bucket = h(k);
//Elem *ins = new Elem;
//ins->key = k;
//ins->value = v;
//cell *c = new cell;
//c->elem = ins;

if(s[bucket] == emptyBucket){
	s[bucket] = new cell;
	s[bucket]->elem.key = k;
	s[bucket]->elem.value = v;
	s[bucket]->next = emptyBucket;
} else {
	//cell* prev = s[bucket];
	cell* aux = s[bucket];
	if(aux->elem.key == k) return FAIL;
	while(aux->next != emptyBucket){
		//prev = aux;
		aux = aux->next;
		if(aux->elem.key == k) return FAIL;
	}
	cell* cur = new cell;
	//s[bucket] = new cell;
	cur->elem.key = k;
	cur->elem.value = v;
	cur->next = emptyBucket;
	aux->next = cur;
	//prev->next = s[bucket];
}
   return OK;
}


/****************************************************************/
Dictionary dict::createEmptyDict()
{
   Bucket* d = new Bucket[tableDim];
   for (int i=0; i < tableDim; ++i)
      d[i]=emptyBucket;
   return d;
}


/****************************************************************/
Dictionary readFromFile(string nome_file)
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    if (!ifs) {cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; return createEmptyDict();}  
    return readFromStream(ifs);
}


/****************************************************************/
Dictionary readFromStdin()
{
    cout << "\nInserire una sequenza di linee che rispettano la sintassi key: value.<enter>\nDigitare CTRL^ D per terminare l'inserimento\n";
    Dictionary d = readFromStream((std::cin));
// Questa serve per aggirare un bug di alcune versioni attuali di glibc.
    clearerr(stdin);
    return d;
}


/****************************************************************/
Dictionary readFromStream(istream& str)
{
    Dictionary d = createEmptyDict();     
    string key, kcopy;
    string value;
    getline (str, key, ':'); 
    getline (str, value); 
    while (!str.eof())  
        {     
        kcopy = key;
        removeBlanksAndLower(kcopy);   
        insertElem(kcopy, value, d); // FINCHE' NON IMPLEMENTATE LA INSERTELEM, NON PUO' FUNZIONARE CORRETTAMENTE: la insertElem e' la prima funzione che dovete implementare
        getline (str, key, ':'); 
        getline (str, value); 
        }
    str.clear();
    return d;
}


/****************************************************************/
int printBucket(Bucket b) // stampa il contenuto di un bucket e restituisce il numero di elementi contenuti nel bucket stesso
{  
   int counter = 0;
   while(b!=emptyBucket) {
        counter++;
        cout << (b->elem).key << ": " << (b->elem).value << "\n"; 
	b=b->next;
	}
   return counter;	
}


/****************************************************************/
void print(const Dictionary& s)
// stampa il contenuto del dizionario ed anche informazioni su come sono stati organizzati gli elementi
{
int bucketDim[tableDim];
int totalElem = 0;
for (unsigned int i=0; i<tableDim; ++i)
   {
    cout << "\nBucket " << i << "\n\n";
    bucketDim[i] = printBucket(s[i]);
    totalElem += bucketDim[i]; 
   }
float means = totalElem/(float)tableDim;
float standardDevSum = 0;
for (unsigned int i=0; i<tableDim; ++i)
     standardDevSum += (bucketDim[i]-means)*(bucketDim[i]-means);
   
/* Lo scarto tipo, deviazione standard, o scarto quadratico medio e' un indice di dispersione statistico, vale a dire una stima della variabilita' di una popolazione di dati o di una variabile casuale.
Lo scarto tipo e' uno dei modi per esprimere la dispersione dei dati intorno ad un indice di posizione, quale puo' essere, ad esempio, la media aritmetica. */

cout << "\n===STATISTICHE SULL'ORGANIZZAZIONE DEL DIZIONARIO===\n";

for (unsigned int i=0; i<tableDim; ++i)
   cout << "\nBucket " << i << ": " << bucketDim[i] << " elementi";

cout << "\nIl numero totale di elementi memorizzati e' " << totalElem;
cout << "\nIl numero di bucket nel dizionario e' " << tableDim;
if (tableDim != 0) cout << "\nIl numero atteso di elementi per bucket e' " << means << "\nLa deviazione standard e' " << sqrt(standardDevSum/tableDim);
}



