#include<iostream>
using namespace std;

void sorting_functions()
{
	cout<<"\n1)Merge Sort."
		  "\n2)Quick Sort."
		  "\n3)Insertion Sort."
	      "\n4)Selection Sort."
	      "\n5)Counting Sort."
	      "\n6)Radix Sort."
	      "\n7)Bubble Sort.\n\n";
}

//---------------------------------------------------------------------------------------------------------
//		FOR SWAPPING TWO ELEMENTS
void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

//---------------------------------------------------------------------------------------------------------
//		MERGE FUNCTION OF MERGE SORT
void merge(int arr[], int lb, int mid, int ub)
{
	//we initially create an auxiliary array to store the elements of the two arrays
	int b[ub];
	
	//there are two arrays that are sorted, 1st array and 2nd array
	
	//we take three variables 1 for the lower bound i.e the start of the 1st array;
	//another if for the second lower bound of the other array i.e the right array that is sorted
	//and then k is the lower bound, which we use for the newly formed auxiliary array that we get_array after merging both the arrays
	int i=lb;
	int j=mid+1;
	int k=lb;
	
	while( i<=mid && j<=ub )	//perform the operation while there are elements in both the arrays 
	{
		if(arr[i] < arr[j])
			b[k++] = arr[i++];
			
		else //(arr[i] > = arr[j]
			b[k++] = arr[j++];
	
	}
	
	if(i>mid)					// if we have completed running the while loop and there are still elements that are left in the 2nd array
		while(j<=ub)			// then we copy all these element to the auxiliary array
			b[k++] = arr[j++];
	
	
	else if(j>ub)				// if we have completed running the while loop and there are still elements that are left in the 1st array
		while(i<=mid)			// then we copy all these element to the auxiliary array
			b[k++] = arr[i++];
	
	for(int p=lb; p<=ub; p++)	//copy the elements of the auxiliary array to the original array
		arr[p] = b[p];

}

//MERGE SORT ALGORITHM
void mergeSort(int arr[], int lb, int ub)
{
	if(lb<ub)	//we call merge sort only when there are atleast 2 elements in the array, we stop when we have a single element
	{
		int mid = (lb + ub)/ 2;			//divide the array into two halves and
		mergeSort(arr, lb, mid);		//recursively call mergesort on both the halves of the original array
		mergeSort(arr, mid+1, ub);
		merge(arr, lb, mid, ub);		//and the merge the halves of the array
	}
}

//---------------------------------------------------------------------------------------------------------
//SELECTION SORT
void selectionSort(int arr[],  int n)	//Selection sort considers
{
	int min;
	for(int i=0; i<n-1; i++)
	{
		min = i;						//the current element as the minimum in the  array
		for(int j=i+1; j<n; j++)		//and it start the comparision from the next index 
			if(arr[j] < arr[min])		//if there is an element which is smaller than the current element
				min = j;				//then we change the minimum to that index
		
		if(min != i)					//so, if the index is not same as the initial one
			swap(arr[i], arr[min]);		//we swap the curr min element with the newly found minimum 
	}
}
//---------------------------------------------------------------------------------------------------------
//INSERTION SORT
void insertionSort(int arr[], int n)	//insertion sort imagines two array, the left side as the sorted one and the right side as unsorted
{
	for(int i=1; i<n; i++)				//initially, we consider the first element to be sorted i.e the 0th index is sorted
	{									//then we consider the elements from the 1st index as unsorted and begin a loop till last element
	
		int temp = arr[i];				//we store the current element in temp
		int j=i-1;						//then we go to the previous index;
		
		while(j>=0 && arr[j]>temp)		//we go back from current element till 0, and swap the current element (j+1) index as we are at (j-1)th index
		{								//with the jth index and move back again 
			swap(arr[j], arr[j+1]);
			j--;
		}
		arr[j+1] = temp;				//and at the end if we reach say -1 th index suppose
										//we move to the 0th index by saying [j+1] and we store the temp variable
	}
}
//---------------------------------------------------------------------------------------------------------
//BUBBLESORT
void bubbleSort(int arr[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
				swap(arr[j], arr[j+1]);
		}
	}
}
//---------------------------------------------------------------------------------------------------------
//		PARTITION FUNCTION IN QUICKSORT
int partition(int arr[], int lb, int ub)
{
	int pivot = arr[lb];
	int start = lb;
	int end = ub;
	while(start < end)
	{
		while(arr[start] <= pivot)			//we increment start until we find an element greater than pivot
			start++;						//i.e if the element at the start is less than the pivot element, we increment start
		
		while(arr[end] > pivot)				//we decrement end until we find an ememnt that is greater than the pivot
			end--;							//i.e if the element at the end is greater than the pivot element, we decrement end
			
		if(start < end)						//we swap only when the start is less than end
			swap(arr[start], arr[end]);
	}
	swap(arr[lb], arr[end]);				//when the loop completes end crosses start,
											//so we swap the lower bound element which is the pivot, with the end element
	return end;						//and return this index, so that we can call quick sort or elements that are on either sides of the pivot element
}

void quickSort(int arr[], int lb, int ub)
{
	if(lb<ub)	
	{
		int loc = partition(arr, lb, ub);	//we get_array the location of the partitioned element after the quick sort is performed
		quickSort(arr, lb, loc-1);			//then we call quicksort on the left side of the partition element
		quickSort(arr, loc+1, ub);			// and then on the right side of the partition element
	}
}

//---------------------------------------------------------------------------------------------------------
//COUNTING SORT ALGORITHM
void countingSort(int arr[], int n)
{	
	int max = arr[0];
	for(int i=1; i<n; i++ )
		if(arr[i] > max)
			max = arr[i];
	
	int k = max + 1;
	
	int count[k];
	for(int i=0; i<k; i++)
		count[i] = 0;
	for(int i=0; i<n; i++)
		count[arr[i]]++;
		
	for(int i=1; i<k; i++)
		count[i] = count[i] + count[i-1];
		
	int output[n];
	for(int i=n-1; i>=0; i--)
	{
		output[ count[arr[i]] - 1 ] = arr[i];
		count[arr[i]]--;
	}
	
	for(int i=0; i<n; i++)
		arr[i] = output[i];
}

//---------------------------------------------------------------------------------------------------------
//		RADIX SORT
//		COUNTING SORT FOR RADIX SORTING ALGORITHM
countingSort_radix(int arr[], int n, int exp)
{
	int count[10], output[n];
	for(int i=0;i<10;i++)
		count[i] = 0;
	for(int i=0;i<n;i++)
		count[ (arr[i]/exp) % 10 ]++;
	
	for(int i=1; i<10; i++)
		count[i] = count[i] + count[i-1];
		
	for(int i=n-1; i>=0; i--)
	{
		output[ count[ (arr[i]/exp) % 10 ] - 1 ] = arr[i];
		count[ (arr[i]/exp) % 10 ]--;
	}	
	
	for(int i=0; i<n; i++)
		arr[i] = output[i];
}

// Radix Sort Algorithm
void radixSort(int arr[], int n)
{
	int max = arr[0];
	for(int i=1; i<n; i++ )
		if(arr[i] > max)
			max = arr[i];
			
	for(int exp=1; max/exp > 0; exp=exp*10)		
		countingSort_radix(arr, n, exp);
}

