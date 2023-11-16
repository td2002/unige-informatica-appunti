#include <iostream>

int const N=54;
int const NL=4;

int contaCarattere (char[], int, char);

int main(){
	
	char frase[N] = "prom'non nous dans le bois quand le loup il n'y a pas";
	char lettere[NL] = {'n', 'o', 'p', 'k'};
	
	std::cout << "All'interno della frase\n\t" << frase << "\n";
	for (int i=0; i<NL; ++i){
		std::cout << "la lettera " << lettere[i] << " appare " << contaCarattere(frase, N, lettere[i]) << " volte\n";
	}
	
	return 0;
}

int contaCarattere (char str[], int l, char c){
	int volte=0;
	for (int i=0; i<l; ++i){
		if(str[i]==c)
			volte++;
	}
	return volte;
}
