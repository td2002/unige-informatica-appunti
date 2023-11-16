//typedef di WordList come vector di string
//contiene prototipi funzioni

#include <iostream>
#include <string>
#include <vector>

//definizione della stringa di terminazione inserimento utente
#define END_STRING "*FINE"

typedef std::vector<std::string> WordList;

bool is_contained(const WordList &wl, const std::string s);
bool add(WordList &wl, std::string s);
//funzione aggiuntiva
std::string list_all(const WordList &wl);
