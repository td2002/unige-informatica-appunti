#include <string>

struct Contact_Str {
  std::string Name;
  std::string Surname;
  int PhoneNumber;
  Contact_Str * next;
};

typedef Contact_Str *  PhoneBook;

void print(PhoneBook B);
Contact_Str * FindPos(PhoneBook B, std::string S);
bool add_ord(PhoneBook& B, std::string surname, std::string name, int phoneNumber);
void clear(PhoneBook &B);
