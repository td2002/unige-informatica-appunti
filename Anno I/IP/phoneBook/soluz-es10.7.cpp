#include <iostream>
#include <vector>
//#include "contact.h"
#include "contact.cpp"

PhoneBook mybook;

int main()
{
  std::cout << std::boolalpha;
  while (!std::cin.eof()) {
    std::string surname, name; int phonenumber;
    std::cin >> surname;
    if (surname == ".") break;
    std::cin >> name;
    std::cin >> phonenumber;
    add(mybook, surname, name, phonenumber);
  }
  std::cout << "Input letto:\n";
  print(mybook);
  sortSurnames(mybook);
  std::cout << "Dopo sort:\n";
  print(mybook);

  int pos;
  std::cout << "FindPos d (elemento presente):\n";
  pos = FindPos(mybook, "d");
  if(pos>=0)
  std::cout << "pos = "<<pos<<" - " << mybook[pos].Surname << "\n";

  std::cout << "FindPos ff (elemento non presente):\n";
  pos = FindPos(mybook, "ff");
  if(pos>=0)
  std::cout << "pos = "<<pos<<" - " << mybook[pos].Surname << "\n";

  std::cout << "FindPos 0 (testa, stampo solo indice):\n";
  pos = FindPos(mybook, "0");
  std::cout << "pos = "<<pos<< "\n";

  std::cout << "FindPos zz (coda):\n";
  pos = FindPos(mybook, "zz");
  std::cout << "pos = "<<pos<<" - " << mybook[pos].Surname << "\n";
 
  pos = FindPos(mybook, "d");
  std::cout << "Dopo Shift "<<pos<<":\n";
  Shift_PhoneBook(mybook, pos);
  print(mybook);

  add_ord(mybook, "bb", "bb", 10);
  std::cout << "Dopo add bb bb 10:\n";
  print(mybook);
}
