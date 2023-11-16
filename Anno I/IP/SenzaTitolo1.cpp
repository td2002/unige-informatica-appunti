#include <iostream>

int main(){
	
	int v[5]={3,6,9,12,15};

int *p=v;

p=p+1;

*p=4;
	std::cout << *(p+3);
}
