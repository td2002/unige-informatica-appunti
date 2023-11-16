#include <iostream>
#include "contact.h"

// ausiliaria
Contact_Str newContact(std::string surname, std::string name, int phoneNumber)
{
  Contact_Str nc;
  nc.Name = name;
  nc.Surname = surname;
  nc.PhoneNumber = phoneNumber;
  return nc;
}

void add(PhoneBook& B, std::string surname, std::string name, int phoneNumber)
{
  B.push_back(newContact(surname, name, phoneNumber));
}

void print(const PhoneBook& B)
{
  for (int i=0; i<B.size(); i++) {
    std::cout << i << "\t";
    std::cout << B[i].Surname << ", ";
    std::cout << B[i].Name << " ... ";
    std::cout << B[i].PhoneNumber << "\n";
  }
}

void sortSurnames(PhoneBook& B)
{
  if (B.size()<=1) return;
  for (int i=0; i<B.size()-1; i++) {
    int imin = i;
    for (int j=i+1; j<B.size(); j++) if (B[imin].Surname>B[j].Surname) imin = j;
    Contact_Str temp = B[i];
    B[i]=B[imin];
    B[imin]=temp;
  }
}

int FindPos(const PhoneBook& B, std::string S)
{
  int l=0, h=B.size()-1;
  if (B[l].Surname > S) return l-1;
  if (B[h].Surname < S) return h;
  if (B[l].Surname == S) return l;
  if (B[h].Surname == S) return h;
  while (l<h) {
    int m = (h+l)/2;
    if (B[m].Surname == S) return m;
    if (B[m].Surname < S) l = m+1;
    else h = m-1;
  }
  return l;
}

void Shift_PhoneBook(PhoneBook& B, int pos)
{
  if (pos<-1 || pos>=B.size()) throw "out of range";
  B.resize(B.size()+1);
  for (int j=B.size()-1; j>pos; j--) B[j]=B[j-1];
}

bool add_ord(PhoneBook& B, std::string surname, std::string name, int phoneNumber)
{
  Contact_Str nc = newContact(surname, name, phoneNumber);
  int newPos = FindPos(B, surname);

  if (B[newPos].Surname!=surname) { // altrimenti c'è già
    Shift_PhoneBook(B, newPos);
    B[newPos]=nc;
    return true;
  }
  else return false;
}

