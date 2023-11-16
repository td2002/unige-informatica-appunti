#include <string>
#include <vector>

struct Contact_Str {
  std::string Name;
  std::string Surname;
  int PhoneNumber;
};

typedef std::vector<Contact_Str> PhoneBook;

void add(PhoneBook& B, std::string surname, std::string name, int phoneNumber);
void print(const PhoneBook& B);
void sortSurnames(PhoneBook& B);
int FindPos(const PhoneBook& r, std::string S);
void Shift_PhoneBook(PhoneBook& B, int pos);
bool add_ord(PhoneBook& B, std::string surname, std::string name, int phoneNumber);
