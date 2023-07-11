#include<iostream>
using namespace std;

#include "sorting_functions.h"

void get();
void show(int arr[], int n);
int n;
int array[1];

//---------------------------------------------------------------------------------------------------------

void sorting_main()
{
	sorting_functions();	//in sorting_functions.h header file where the definitinons of the sorting algorithms are present
	
	int answer;	
	cout<<"\nEnter your choice: ";cin>>answer;
	switch(answer)
	{
		case 1:
			get();
			mergeSort(array, 0, n-1);
			show(array, n);
			break;
		
		case 2:
			get();
			quickSort(array, 0, n-1);
			show(array, n);
			break;
		
		case 3:
			get();
			insertionSort(array, n);
			show(array, n);
			break;
				
		case 4:
			get();
			selectionSort(array,n);
			show(array, n);
			break;
		
		case 5:
			get();
			countingSort(array ,n);
			show(array, n);
			break;
		
		case 6:
			get();
			radixSort(array, n);
			show(array, n);
			break;
		
		case 7:
			get();
			bubbleSort(array, n);
			show(array, n);
			break;
		
		default:
			cout<<"\n\nInvalid input\nPlease enter an input from 1-7";	
	}
}

//---------------------------------------------------------------------------------------------------------

void get()
{
	cout<<"Enter the number of elements: ";cin>>n;
	array[n];
	
	for(int i=0;i<n;i++)
		cin>>array[i];
}

void show(int arr[], int n)
{
	cout<<"\nThe Sorted array is : ";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}



