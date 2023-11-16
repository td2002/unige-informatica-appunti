//implementazioni funzioni
//include .h
//is_contained restituisce true se stringa s è contenuta nella lista di parole wl, se no false
//add aggiunge stringa s alla WordList wl. restituisce false se s è già presente, true se non c'era e l'ha aggiunta.


#include <string>
#include <vector>
#include <iostream>
#include "wordlist.h"

bool is_contained(const WordList &wl, const std::string s){
	int i=0;
	for (i=0; i< wl.size(); ++i){
		if (wl[i] == s) return true;
	}
	return false;
}

bool add(WordList &wl, std::string s){
	if(!is_contained(wl, s)){
		wl.push_back(s);
		return true;
	}
	return false;
}

//funzione aggiuntiva
std::string list_all(const WordList &wl){
	std::string tot="- - ELENCO PAROLE - -\n";
	int i;
	for (i=0; i< wl.size(); ++i){
		tot+= wl[i];
		tot+= "\n";
	}
	tot += "- - - - - - - - - - -\n";
	return tot;
}

