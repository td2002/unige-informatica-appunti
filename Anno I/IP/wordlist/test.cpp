//contiene cpp e testa

#include <iostream>
#include <fstream>
#include "wordlist.cpp"

int main(){
	
	WordList parole;
	std::string str="vuoto";
	std::ifstream file;
	bool flag=true;//per vedere se il file è finito
	file.open ("words.txt");
	
	do{
	
	std::cout << "Leggo una parola dal file\n";
	flag=file >> str;
	if (!flag) break;
	std::cout << "Letta parola " << str << "\n";
	
	std::cout << "Aggiungo parola alla lista\n";
	add(parole, str) ? std::cout << "Aggiunta effettuata\n\n" : std::cout << "Aggiunta non effettuata\n\n";
	
	} while (flag);
	std::cout << "Non posso, il file finisce qui.\n";

	
	file.close();
	
	std::cout << "\nInizio inserimento utente: per terminare inserire stringa \"" << END_STRING << "\" senza virgolette\n";
	
	while(str != END_STRING){
	
	std::cout << "Scrivi una parola da aggiungere: ";
	std::cin >> str;
	
	if (str == END_STRING){
		break;
	}
	
	std::cout << "Aggiungo parola alla lista\n";
	
	add(parole, str) ? std::cout << "Aggiunta effettuata\n" : std::cout << "Aggiunta non effettuata\n";
	
	}
	std::cout << "\n" << list_all(parole);
	
	return 0;
}

