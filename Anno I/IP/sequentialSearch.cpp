// dichiarare una variabile const int N inizializzata a 15
// dichiarare una variabile int item
// leggere item da input
// dichiarare un array v di N interi
// leggere v da input (vedi esercizi parte precedente)
// dichiarare una variabile int loc e inizializzarla a -1
// dichiarare una variabile bool found e inizializzarla a false
/* iterare sugli elementi di v fino a che found diventa true o ...
... si è iterato su tutto l'array
- se il valore alla pos corrente (i) e' uguale a item
-- assegnare true a found e il valore di i a loc
*/
// se trovato, scrivere su output: ``Trovato in posizione ...''
// altrimenti scrivere ``Non trovato''

const int N = 16;

#include <fstream>
#include <iostream>

bool arrayReader(int arr[], int n, char*filename);
bool arrayPrinter(int arr[], int n);

int main(){
	
	int item;
	int v[N];
	int loc = -1;
	bool found = false;
	
	std::ifstream inputfile;
	inputfile.open("dati.txt");
	inputfile >> item;
	
	std::cout << item << "\n\n";
	
	
	arrayReader(v, N, "datiV.txt");
	arrayPrinter(v, N);
	
	for(int i=0;i<N && !found;++i){
		if (v[i]==item){
			found=true;
			loc = i;
		}
	}
	if (found){
		std::cout << "Valore " << item << " trovato in posizione " << loc+1;
	} else {
		std::cout << "Valore " << item << "Non trovato";
	}
	
	return 0;
	
}

bool arrayReader(int arr[], int n, char*filename){
	std::ifstream input;
	input.open(filename);
	int i=0;
	for (;i<n;++i){
		input >> arr[i];
	}
	
	return true;
}

bool arrayPrinter(int arr[], int n){
	for(int i=0; i<n-1; ++i)
		std::cout << arr[i] << " - ";
	std::cout << arr[n-1] << "\n\n";
	return true;
}
