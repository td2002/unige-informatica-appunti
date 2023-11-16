#include "labo2_sort.h"


void scambia(vector<int>& v, int i, int j)
{ 
  int tmp = v[j];
  v[j] = v[i];
  v[i] = tmp;
}


/**************************************************************************************
				SELECTION SORT
***************************************************************************************/
void selectionSort(vector<int>& v)
{
   int current_min_index;
   unsigned int size = v.size();
   for (unsigned int i=0; i<size; ++i)
   { 
     current_min_index = i;
     for (unsigned int j=i+1;j<size; ++j)
        if (v[current_min_index] > v[j])
            current_min_index = j;
     scambia(v, i, current_min_index);
   }
}



/**************************************************************************************
				INSERTION SORT
***************************************************************************************/
void insertionSort(vector<int>& v)
{
   int current, prev;
   unsigned int size = v.size();
   for (unsigned int i=1; i<size; ++i)
   { current=i; 
     prev=i-1;
     while(prev>=0 && v[current]<v[prev])
        {
         scambia(v, current, prev);
         --current;
         --prev;
        }
   }
}


/**************************************************************************************
				BUBBLESORT
***************************************************************************************/
void bubbleSort(vector<int>& v)
{
   unsigned int size = v.size();
   bool scambiati;
   for (unsigned int i=1; i<size; ++i)
      {
      scambiati = false;
      for (unsigned int j=0; j<size-i; ++j)
          if(v[j]>v[j+1])
            { 
              scambia(v, j, j+1);
              scambiati = true;
            }
      if (!scambiati) return;
      }
}



/**************************************************************************************
				   MERGESORT
***************************************************************************************/
void fondi(vector<int>& v, unsigned int inizio, unsigned int centro, unsigned int fine)
{
   vector<int> vsinistra, vdestra;

   for (unsigned int i=inizio; i<=centro; ++i)
      vsinistra.push_back(v[i]);

   for (unsigned int i=centro+1; i<=fine; ++i)
      vdestra.push_back(v[i]);

   unsigned int indicesinistra = 0;
   unsigned int maxsin = vsinistra.size();
   unsigned int indicedestra = 0;
   unsigned int maxdes = vdestra.size();
   
   for (unsigned int i=inizio; i<=fine; ++i)
   {
      if (indicesinistra < maxsin && indicedestra < maxdes)
         {
         if (vsinistra[indicesinistra]<vdestra[indicedestra])
            {
             v[i] = vsinistra[indicesinistra];
             indicesinistra++; continue;
             }
         else
            { 
            v[i] = vdestra[indicedestra];
            indicedestra++; continue;
            }
         } 
      
      if (indicesinistra == maxsin && indicedestra < maxdes)
         { 
            v[i] = vdestra[indicedestra];
            indicedestra++; continue;
         }

       if (indicedestra == maxdes && indicesinistra < maxsin)
         { 
            v[i] = vsinistra[indicesinistra];
            indicesinistra++; continue;
         }         
   } 
}

void ms(vector<int>& v, unsigned int inizio, unsigned int fine)
{
    if (inizio < fine)
      {
          unsigned int centro = (inizio+fine)/2;
          ms(v, inizio, centro);
          ms(v, centro+1, fine);
          fondi(v, inizio, centro, fine);
      }
}


void mergeSort(vector<int>& v)
{
   if (v.size() != 0)
      ms(v, 0, v.size()-1);
}


/**************************************************************************************
				QUICKSORT CON SCELTA "BANALE" DEL PIVOT
***************************************************************************************/

void swap(vector<int>&v, int pos1, int pos2){
	//if (pos1==pos2) return;
	int aux=v[pos1];
	v[pos1]=v[pos2];
	v[pos2]=aux;
	return;
}

int partition(vector<int>&a, int l, int r){
	int pivot = a[l];
	int i=l+1;
	for(int j=l+1; j<=r; ++j){
		if(a[j] < pivot){
			swap(a,j,i);
			++i;
		}
		
	}
	swap(a,l,i-1);
	//ritorna dove sta il pivot
	return i-1;
}

void quickSortTrivialAux(vector<int>& v, int first, int last)
{
   /* Implementare quickSort banale con partizione in place */
   
   	if(first>=last) return;
   	
	int pos_pivot = partition(v,first,last);
	
	quickSortTrivialAux(v,first,pos_pivot-1);
	quickSortTrivialAux(v,pos_pivot+1,last);
	
}


void quickSortTrivial(vector<int>& v)
{
   /* Implementare quickSort banale con partizione in place */
	quickSortTrivialAux(v,0,v.size()-1);
	
}








/**************************************************************************************
				QUICKSORT RANDOMIZZATO
***************************************************************************************/

int partitionR(vector<int>&a, int l, int r){
	int pivot_ind = ((rand())%(r-l+1))+l;
	int pivot = a[pivot_ind];
	swap(a,l,pivot_ind);
	int i=l+1;
	for(int j=l+1; j<=r; ++j){
		if(a[j] < pivot){
			swap(a,j,i);
			++i;
		}
		
	}
	swap(a,l,i-1);
	//ritorna dove sta il pivot
	return i-1;
}

void quickSortRandomAux(vector<int>& v, int first, int last)
{
   /* Implementare quickSort banale con partizione in place */
   
   	if(first>=last) return;
   	
	int pos_pivot = partitionR(v,first,last);
	
	quickSortRandomAux(v,first,pos_pivot-1);
	quickSortRandomAux(v,pos_pivot+1,last);
	
}

void quickSortRandom(vector<int>& v)
{
   /* Implementare quickSort randomizzato con partizione in place */
	srand(time_t(NULL));
	quickSortRandomAux(v,0,v.size()-1);
}
