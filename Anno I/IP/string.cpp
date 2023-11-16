#include <iostream>
#include <vector>

unsigned int ricerca_binaria(std::string*arr, int start, int end, std::string s){
	int m=(start+end)/2;
	if(start>=end){
		return -1;
	}
	if(s.compare(arr[m])==0){
		return m;
	}
	if(s.compare(arr[m])<0){
		return ricerca_binaria(arr, start, m, s);
	} else {
		return ricerca_binaria(arr, m+1, end, s);
	}
}


int main(){
	int n=5;
	std::string v[n] = {"abc", "de", "fg", "hi", "jkl"};
	std::string str = v[3];
	std::cout << "La stringa " << str << " è in pos. " << 1+ricerca_binaria(v, 0, n, str);
}
