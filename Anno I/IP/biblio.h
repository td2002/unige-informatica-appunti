#include <string>


struct DatiBiblio{
    std::string autore;
    std::string titolo;
    int anno;
};

struct Scheda {
    DatiBiblio libro;
    Scheda * next;
};

typedef Scheda * Schedario;

bool remove (Schedario& lista, DatiBiblio x);
void clear  (Schedario& lista);
void print  (Schedario& lista);
bool add    (Schedario& lista, DatiBiblio x);
bool is_in  (Schedario& lista, DatiBiblio x);
