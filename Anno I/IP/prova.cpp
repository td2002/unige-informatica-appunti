#include <iostream>

struct Stanza{

    std::string nome;
    float dimensione;
    double temperatura;
};
int main(){
	Stanza p;
	
	UpdateRoom(&p,"a",3,2);

	
	
	return 0;
}

void UpdateRoom(Stanza &S, std::string s, float dim, float t)
{
     S.nome=s;
     S.dimensione=dim;
     S.t=temperatura;
}
