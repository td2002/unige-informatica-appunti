#include <iostream>

void ordinaFloat (float*, float*, float*, bool);

int main(){
	
	float x, y, z;
	bool flag;
	
	x=.1; y=.5; z=1; flag=false;
	std::cout << "1. Numeri non ordinati: " << x << " - " << y << " - " << z << "\n";
	ordinaFloat(&x,&y,&z,flag);
	std::cout << "1. Numeri ordinati: " << x << " - " << y << " - " << z << "\n\n";
	
	x=.1; y=.5; z=1; flag=true;
	std::cout << "2. Numeri non ordinati: " << x << " - " << y << " - " << z << "\n";
	ordinaFloat(&x,&y,&z,flag);
	std::cout << "2. Numeri ordinati: " << x << " - " << y << " - " << z << "\n\n";
	
	x=1; y=.5; z=.1; flag=false;
	std::cout << "3. Numeri non ordinati: " << x << " - " << y << " - " << z << "\n";
	ordinaFloat(&x,&y,&z,flag);
	std::cout << "3. Numeri ordinati: " << x << " - " << y << " - " << z << "\n\n";
	
	x=1; y=.5; z=.1; flag=true;
	std::cout << "4. Numeri non ordinati: " << x << " - " << y << " - " << z << "\n";
	ordinaFloat(&x,&y,&z,flag);
	std::cout << "4. Numeri ordinati: " << x << " - " << y << " - " << z << "\n\n";
	
	x=.5; y=.1; z=1; flag=false;
	std::cout << "5. Numeri non ordinati: " << x << " - " << y << " - " << z << "\n";
	ordinaFloat(&x,&y,&z,flag);
	std::cout << "5. Numeri ordinati: " << x << " - " << y << " - " << z << "\n\n";
	
	x=.5; y=.1; z=1; flag=true;
	std::cout << "6. Numeri non ordinati: " << x << " - " << y << " - " << z << "\n";
	ordinaFloat(&x,&y,&z,flag);
	std::cout << "6. Numeri ordinati: " << x << " - " << y << " - " << z << "\n\n";
	
	x=.5; y=1; z=.1; flag=false;
	std::cout << "7. Numeri non ordinati: " << x << " - " << y << " - " << z << "\n";
	ordinaFloat(&x,&y,&z,flag);
	std::cout << "7. Numeri ordinati: " << x << " - " << y << " - " << z << "\n\n";
	
	x=.5; y=1; z=.1; flag=true;
	std::cout << "8. Numeri non ordinati: " << x << " - " << y << " - " << z << "\n";
	ordinaFloat(&x,&y,&z,flag);
	std::cout << "8. Numeri ordinati: " << x << " - " << y << " - " << z << "\n\n";
	
	return 0;
}

void ordinaFloat (float* a, float* b, float* c, bool f){
	float temp=0;
	if(*a<*b){
		if(*c<*a){
			//c a b
			temp=*a;
			*a=*c;
			*c=*b;
			*b=temp;
		} else {
			if(*c<*b){
				//a c b
				temp=*b;
				*b=*c;
				*c=temp;
			} else {
				// a b c
			}
		}
	} else {
		if(*c<*b){
			//c b a
			temp=*a;
			*a=*c;
			*c=temp;
		} else {
			if(*c<*a){
				//b c a
				temp=*a;
				*a=*b;
				*b=*c;
				*c=temp;
			} else {
				//b a c
				temp=*a;
				*a=*b;
				*b=temp;
			}
		}
	}
	
	if(!f){
		temp=*a;
		*a=*c;
		*c=temp;
	}	
}
