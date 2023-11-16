#include <iostream>
#include <cmath>

struct Cerchio{
	float cx, cy;
	float r;
};

bool cerchioIncluso(Cerchio, Cerchio);

int main(){

	struct Cerchio cerchio1, cerchio2;
	
	cerchio1={0,0,1};
	cerchio2={10,10,2};
	if(cerchioIncluso(cerchio1, cerchio2))
		std::cout << "Uno dei due cerchi è incluso nell'altro\n";
	else
		std::cout << "I due cerchi non si sovrappongono\n";
	
	cerchio1={0,0,1};
	cerchio2={1,1,1};
	if(cerchioIncluso(cerchio1, cerchio2))
		std::cout << "Uno dei due cerchi è incluso nell'altro\n";
	else
		std::cout << "I due cerchi non si sovrappongono\n";
		
	cerchio1={0,0,1};
	cerchio2={0,0,1};
	if(cerchioIncluso(cerchio1, cerchio2))
		std::cout << "Uno dei due cerchi è incluso nell'altro\n";
	else
		std::cout << "I due cerchi non si sovrappongono\n";
	
	return 0;
}

bool cerchioIncluso(Cerchio c1, Cerchio c2){
	float dist=sqrt((pow((c1.cx-c2.cx),2)+pow((c1.cy-c2.cy),2)));
	if(dist<=(2*c1.r) || dist<=(2*c2.r))
		return true;
	return false;
}
