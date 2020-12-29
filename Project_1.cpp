/*
 * Project_1.cpp
 *
 *  Created on: Oct 21, 2020
 *      Author: MunerKhan
 */


#include <iostream>
#include <array>
#include <limits.h>
#include <stdio.h>
#include <chrono> 
using namespace std::chrono; 



using namespace std;
void insertionSort(int arr[], int n);
void printArray(int array[], int n);


void mergeSort(int arr[], int left, int right);
void merge(int arr[], int l, int m, int r);

void buildHeap(int arr[], int len); 
void heapify(int arr[], int n, int i);
void heapSort(int arr[],int len) ;

//quick sort
int partition(int arr[], int p, int r);
void quicksort(int arr[], int p, int r);
void swap(int* a, int* b);

int partition_r(int arr[], int p, int q); 
void quicksort_r(int arr[], int p, int r);


//void countSort(int arr[], int n); 
void radixsort(int arr[], int n);
int getMax(int array[], int n);

void countSort(int arr[], int size, int place);

int main ()

{
	
	int size;
	cout<<"Enter the size of the array ";
	cin>>size;
	
	int arr[size];
	
	for (int i=0; i<size;i++)
	{
		arr[i]=(rand()%size);
	}
	
	
	auto begin = std::chrono::high_resolution_clock::now();

	
	//insertionSort(arr,size);
	/*printArray(arr,size);
	cout<<"\n ";
	
	mergeSort(arr,0,size-1);
	printArray(arr,size);
	cout<<"\n ";
	
	heapSort(arr,size);
	printArray(arr,size);
	cout<<"\n ";
	
	quicksort(arr,0,size-1);
	printArray(arr,size);
	cout<<"\n ";
	
	quicksort_r(arr,0,size-1);
	printArray(arr,size);
	cout<<"\n ";
	
	radixsort(arr,size);
	printArray(arr,size);
	cout<<"\n ";
	*/
	quicksort(arr,0,size-1);

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - begin); 
	cout << "Time taken by function: "<< duration.count() << " microseconds" << endl; 
	
	
	
	//cout<<"Sorted ";
	//printArray(arr,size);
	
	return 0;
}


void printArray(int array[], int n)
{
	
	for (int i=0; i<n;i++)
	{
		printf("%d ",array[i]);
		
	}
	printf("\n");
}



//Insertion Sort

void insertionSort(int arr[], int n)
{
	int val, j;
	for (int i=1; i<n;i++)
	{
		val = arr[i];
		j = i-1;
		
		while (j>=0 && arr[j]>val)
		{
			arr[j+1]= arr[j];
			j=j-1;
		}
		arr[j+1] = val;
	}
}


//Merge sort 

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left+right) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
 		merge(arr, left, mid, right);
    }
}


void merge(int arr[],int l, int m, int r)
{
	int n1, n2;
	n1 = m-l+1;
	n2 = r-m;
	int L[n1], R[n2];
	
	//filling up left and right array from A (original array
	for (int i=0; i<n1;i++)
	{
		L[i]= arr[i+l];
	}
	for (int i=0; i<n2;i++)
	{
		R[i]=arr[i+m+1];
	}
	
	
	int i=0;
	int j=0;
	int k=l;
	
	while(i<n1 && j<n2)
	{
		if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
	}
	
	//copy remaing elements if there are any left 
	while(i<n1)
	{
		arr[k] = L[i];
        i++;
        k++;
	}
    while (j<n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
		
}



//Heap Sort 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; 
    int l = 2*i+1;  
    int r = 2*i+2; 
  
     
    if (l<n && arr[l]>arr[largest]) 
    {
        largest = l; 
    }
 
    if (r<n && arr[r]>arr[largest]) 
    {
        largest = r; 
    }
    
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 
  

void buildHeap(int arr[], int len) 
{  
    int start = (len/2)-1; 
  
    for (int i =start; i >=0; i--) 
    { 
        heapify(arr, len, i); 
    } 
}


void heapSort(int arr[], int len) 
{ 
	buildHeap(arr,len); 
  
    for (int i=len-1; i>=0; i--) 
    { 
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
}


void quicksort(int arr[], int p, int r) 
{ 
    if (p<r) 
    { 
      
        int q = partition(arr, p, r); 
        quicksort(arr, p, q-1); 
        quicksort(arr, q+1, r); 
    } 
}
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}

int partition(int arr[], int p, int r) 
{ 
    int pivot = arr[r];  
    int i = (p-1); // index of smaller element 
    for (int j=p; j<=(r-1); j++) 
    { 
         
        if (arr[j] <= pivot) 
        { 
            i++; 
            int temp = arr[i];
            arr[i]= arr[j];
            arr[j]= temp;
    
        } 
    } 

   
    int temp = arr[i+1];
    arr[i+1]= arr[r];
    arr[r]= temp;

    return i+1; 
} 



void quicksort_r(int arr[], int p, int r) 
{ 
    if (p<r) 
    { 
      
        int q = partition_r(arr, p, r); 
        quicksort(arr, p, q-1); 
        quicksort(arr, q+1, r); 
    } 
}



int partition_r(int arr[], int p, int q) 
{
	
	int ran = (rand()%q-p);
	swap(&arr[ran],&arr[q]);
	return partition(arr,p,q);
}




//Using counting sort to sort the elements in the basis of significant places
void countSort(int arr[], int size, int place) 
{
  int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
  {
    count[i] = 0;
  }
  //Calculate count of elements
  for (int i = 0; i < size; i++)
  {
    count[(arr[i] / place) % 10]++;
  }
  //Calculating cumulative count
  for (int i = 1; i < max; i++)
  {
    count[i] += count[i - 1];
  }
  //Placing the elements in sorted order
  for (int i = size - 1; i >= 0; i--) 
  {
    output[count[(arr[i] / place) % 10] - 1] = arr[i];
    count[(arr[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
  {
    arr[i] = output[i];
  }
}


void radixsort(int arr[], int size) 
{
	
	int max = arr[0];
	for (int i = 1; i < size; i++)
	{
	    if (arr[i] > max)
	      max = arr[i];
	}
  

  for (int place =1;max/place>0; place *= 10)
  {
    countSort(arr, size, place);
  }
}









