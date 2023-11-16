#include <iostream>

#include "contactl.cpp"

PhoneBook mybook;

int main()
{
  std::cout << std::boolalpha;
  while (!std::cin.eof()) {
    std::string surname, name; int phonenumber;
    std::cin >> surname;
    std::cout << surname;
    if (surname == ".") break;
    std::cin >> name;
    std::cin >> phonenumber;
    add_ord(mybook, surname, name, phonenumber);
  }
  std::cout << "Input letto:\n";
  print(mybook);
  std::cout << "FindPos d (elemento presente):\n";
  std::cout << FindPos(mybook, "d")->Surname << "\n";
  std::cout << "FindPos ff (elemento non presente):\n";
  std::cout << FindPos(mybook, "ff")->Surname << "\n";
  std::cout << "FindPos 0 (testa, stampo puntatore che deve essere 0):\n";
  std::cout << FindPos(mybook, "0") << "\n";
  std::cout << "FindPos zz (coda):\n";
  std::cout << FindPos(mybook, "zz")->Surname << "\n";
  bool risultato = add_ord(mybook, "ff", "ff", 65);
  std::cout << "Dopo add ff ff 65:\n";
  std::cout << "Risultato: "<<risultato<<"\n";
  print(mybook);
  risultato = add_ord(mybook, "d", "d", 4);
  std::cout << "Dopo add d d 4:\n";
  std::cout << "Risultato: "<<risultato<<"\n";
  print(mybook);
  risultato = add_ord(mybook, "0", "0", 0);
  std::cout << "Dopo add 0 0 0:\n";
  std::cout << "Risultato: "<<risultato<<"\n";
  print(mybook);
  risultato = add_ord(mybook, "zz", "zz", 100);
  std::cout << "Dopo add zz zz 100:\n";
  std::cout << "Risultato: "<<risultato<<"\n";
  print(mybook);
  clear(mybook);
}
