#include <vector>
#include <string>
#include <iostream>

int main(){
	
	std::vector<int> a;
	a.push_back(2);
	a.push_back(5);
	a.push_back(6);
	a.push_back(8);
	a.push_back(10);
	a.push_back(14);
	a.push_back(15);
	a.push_back(55);
	a.push_back(59);
	a.push_back(591);
	a.push_back(592);
	
	for(int i=0; i<a.size(); ++i)
	std::cout << a[i]<< "|";
	
	std::cout <<  "\n\n\n";
	int ins = 18;
	for(int i=0; i<a.size(); ++i){
		if (ins < a[i]){
			std::vector<int> aux;
			for(int j=i; j<a.size(); j++){
				aux.push_back(a[j]);
			}
			int s = a.size();
			for(int k=i; k<s;++k){
				a.pop_back();
			}
			a.push_back(ins);
			for(int x=0; x<aux.size(); ++x){
				a.push_back(aux[x]);
			}
			break;
		}
	}
	for(int i=0; i<a.size(); ++i)
	std::cout << a[i]<< "|";

	std::cout <<  "\n\n\n";	
	ins = 180;
	for(int i=0; i<a.size(); ++i){
		if (ins < a[i]){
			std::vector<int> aux;
			for(int j=i; j<a.size(); j++){
				aux.push_back(a[j]);
			}
			int s = a.size();
			for(int k=i; k<s;++k){
				a.pop_back();
			}
			a.push_back(ins);
			for(int x=0; x<aux.size(); ++x){
				a.push_back(aux[x]);
			}
			break;
		}
	}
	for(int i=0; i<a.size(); ++i)
	std::cout << a[i]<< "|";
	
	std::cout <<  "\n\n\n";	
	ins = -5;
	for(int i=0; i<a.size(); ++i){
		if (ins < a[i]){
			std::vector<int> aux;
			for(int j=i; j<a.size(); j++){
				aux.push_back(a[j]);
			}
			int s = a.size();
			for(int k=i; k<s;++k){
				a.pop_back();
			}
			a.push_back(ins);
			for(int x=0; x<aux.size(); ++x){
				a.push_back(aux[x]);
			}
			break;
		}
	}
	for(int i=0; i<a.size(); ++i)
	std::cout << a[i]<< "|";
	
	
}
