#include <iostream>
#include <sstream>

struct typeDate{
	int year;
	short unsigned int month;
	short unsigned int day;
};

typedef struct typeDate date;

bool datePrinter(date d);
bool dateChecker(date d);

int main(){
	
	date myDate;
	
	std::cout << "Year: ";
	std::cin >> myDate.year;
	std::cout << "Month: ";
	std::cin >> myDate.month;
	std::cout << "Day: ";
	std::cin >> myDate.day;
	
	datePrinter(myDate);
	
	return 0;
}

bool dateChecker(date d){
	if(d.month<1 || d.month>12)
		return false;
	if(d.day<1 || d.day>31)
		return false;
	if((d.month==4 || d.month==6 || d.month ==9 || d.month == 11) && d.day>30)
		return false;
	if(!((d.year%4==0 && d.year%100!=0)||d.year%400==0) && d.month==2 && d.day>28)
		return false;
	if(d.year<0 || d.year>9999)
		return false;
	return true;
}

bool datePrinter(date d){
	
	if(dateChecker(d)){
	
		std::stringstream ssd;
		std::string ds;
		if(d.year<1000)
			ssd << "0";
		if(d.year<100)
			ssd << "0";
		if(d.year<10)
			ssd << "0";
		ssd << d.year << "-";
		if(d.month<10)
			ssd << "0";
		ssd << d.month << "-";
		if(d.day<10)
			ssd << "0";
		ssd << d.day;
		
		ssd >> ds;
	
		std::cout << ds;
		return true;
	}
	std::cout << "Invalid date";
	return false;
}
