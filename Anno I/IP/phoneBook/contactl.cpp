#include <iostream>
#include "contactl.h"


// ausiliaria
Contact_Str *newContact(std::string surname, std::string name, int phoneNumber)
{
  Contact_Str *nc = new Contact_Str;
  nc->Name = name;
  nc->Surname = surname;
  nc->PhoneNumber = phoneNumber;
  nc->next = 0;//nullptr;
  return nc;
}

void print(PhoneBook B)
{
  int i=1;
  while (B) {
    std::cout << i++ << "\t";
    std::cout << B->Surname << ", ";
    std::cout << B->Name << " ... ";
    std::cout << B->PhoneNumber << "\n";
    B = B->next;
  }
}

Contact_Str * FindPos(PhoneBook B, std::string S)
{
  if (B==0/*nullptr*/ || B->Surname > S) return 0;//nullptr;
  while (B->next && B->next->Surname<=S) B = B->next;
  return B;
}

bool add_ord(PhoneBook& B, std::string surname, std::string name, int phoneNumber)
{
  Contact_Str * insertAfter = FindPos(B, surname);

  if (insertAfter == 0/*nullptr*/) {
    Contact_Str * nc = newContact(surname, name, phoneNumber);
    nc->next = B;
    B = nc;
    return true;
  }
  else if (insertAfter->Surname != surname) {
    Contact_Str * nc = newContact(surname, name, phoneNumber);
    if (insertAfter->next) nc->next = insertAfter->next;
    insertAfter->next = nc;
    return true;
  }
  else return false;
}

void clear(PhoneBook &B)
{
  if (B) {
    clear(B->next);
    delete B;
    B = 0;//nullptr; // utile solo per la testa
  }
}
