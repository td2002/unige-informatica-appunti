const int N = 10;

#include <fstream>
#include <iostream>

bool arrayReader(int arr[], int n, char*filename);
bool arrayPrinter(int arr[], int n);
bool selectionSortArray(int arr[], int n);

int main(){
	
	int array[N];
	
	arrayReader(array, N, "datiV.txt");
	arrayPrinter(array, N);
	
	std::cout << "Stato ordinamento: " << selectionSortArray(array, N) << "\n\n";
	
	arrayPrinter(array, N);
	
	return 0;
}

bool arrayReader(int arr[], int n, char*filename){
	std::ifstream input;
	input.open(filename);
	int i=0;
	for (;i<n;++i){
		input >> arr[i];
	}
	
	return true;
}

bool arrayPrinter(int arr[], int n){
	for(int i=0; i<n-1; ++i)
		std::cout << arr[i] << " - ";
	std::cout << arr[n-1] << "\n\n";
	return true;
}

bool selectionSortArray(int arr[], int n){
	int temp=-1;
	int min=arr[0];
	int locMin=0;
	int j=-1;
	for(int i=0;i<n;++i){
		for(j=i;j<n;++j){
			if(arr[j]<min){
				min=arr[j];
				locMin=j;
			}
		}
		temp=arr[i];
		arr[i]=min;
		arr[locMin]=temp;
		min=arr[i+1];
		locMin=i+1;
	}
	
	for(int i=0;i<n-1;++i){
		if(arr[i]>arr[i+1]){
			return false;
		}
	}
	return true;
}
