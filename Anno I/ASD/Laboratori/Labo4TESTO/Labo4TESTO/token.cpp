/////////////////////////////////////////////////////////////////////
//
// Laboratorio 3: calcolo di semplici espressioni numeriche 
//                mediante pile e code
//
// vengono accettati dall'esterno solo numeri positivi.
// Per trattare anche numeri negativi occorre modificare
// l'analizzatore lessicale.
//
///////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#include "token.h"

using std::cout;
using std::cin;
using std::string;
using std::istringstream;
using std::ostringstream;

/////////////////////////////////////////////////////////////////////
// Funzioni ausiliarie su tipi di dato semplici
/////////////////////////////////////////////////////////////////////

// da stringa a numero
int str2int(const string &s) {
  // DA IMPLEMENTARE
  int n;
  istringstream itmp(s);
	itmp >> n;
	return n;
}

// da numero a stringa
string int2str(int n) {
  // DA IMPLEMENTARE
  string s;
  ostringstream otmp;
otmp << n;
s = otmp.str();
return s;
}

// ritorna false se e solo se token di tipo sconosciuto o se stringa vuota.
// se stringa non vuota, la stringa perde il pezzo iniziale,
// che diventa token.

bool prossimoToken(string &s, token &t) {
  // DA IMPLEMENTARE
  /*
  string aux="";
  for(int i=0; i<s.size() && s[i]!=' '; ++i){
  	aux+=s[i];
  }
  if (aux==")") t.k = PARENTESI_CHIUSA;
  if (aux=="(") t.k = PARENTESI_APERTA;
  if (aux=="+") t.k = OP_SOMMA;
  if (aux=="-") t.k = OP_SOTTRAZIONE;
  if (aux=="*") t.k = OP_MOLTIPLICAZIONE;
  cout << aux;
  //t.val=()*/
	
	if(!s.size()) return false;
		
	string sub="";
	int spazio = s.find(" ",0);
	if(spazio==string::npos) sub = s.substr(0, s.size());
	else sub = s.substr(0, spazio);
//	cout << "sub:"<<sub<<"\n";
	if(spazio==string::npos) s.erase(0, s.size());
	else s.erase(0, spazio+1);
//	cout << "str:"<< s<<"\n";
	
	/*
	switch(sub){
		case"(":{
			t.k = PARENTESI_APERTA;
			break;
		}
		case")":{
			t.k = PARENTESI_CHIUSA;
			break;
		}
		case"+":{
			t.k = OP_SOMMA;
			break;
		}
		case"-":{
			t.k = OP_SOTTRAZIONE;
			break;
		}
		case"*":{
			t.k = OP_MOLTIPLICAZIONE;
			break;
		}
		default: t.k = SCONOSCIUTO; break;
	}*/
	t.k = SCONOSCIUTO;
	if (sub==")") t.k = PARENTESI_CHIUSA;
	if (sub=="(") t.k = PARENTESI_APERTA;
	if (sub=="+") t.k = OP_SOMMA;
	if (sub=="-") t.k = OP_SOTTRAZIONE;
	if (sub=="*") t.k = OP_MOLTIPLICAZIONE;
//	cout << str2int(sub);
	
	if(int2str(str2int(sub))==sub){
		t.k = NUMERO;
	}
/*	if(t.k == SCONOSCIUTO){
		//se è un num
		t.val = (sub);
		t.k = NUMERO;
	}
	else*/
	t.val = sub;
	
	return true;
	

}

