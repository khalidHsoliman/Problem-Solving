#include <iostream>
using namespace std;

// Number of elements to be sorted
#define N 1000000

// Number of sorting runs
#define NUM 10

// perform insertion sort on arr[]
void insertionSort(int arr[], int low, int n)
{
	// Start from second element (element at index 0 
	// is already sorted)
	for (int i = low + 1; i <= n; i++) 
	{
		int value = arr[i];
		int j = i;
		
		// Find the index j within the sorted subset arr[0..i-1]
		// where element arr[i] belongs
		while (j > low && arr[j - 1] > value) 
		{
			arr[j] = arr[j - 1];
			j--;
		}
		// Note that subarray arr[j..i-1] is shifted to
		// the right by one position i.e. arr[j+1..i]
		
		arr[j] = value;
	}
}
 
int Partition (int a[], int low, int high)
{
	// Pick rightmost element as pivot from the array
	int pivot = a[high];

	// elements less than pivot will be pushed to the left of pIndex
	// elements more than pivot will be pushed to the right of pIndex
	// equal elements can go either way
	int pIndex = low;	
	
	// each time we finds an element less than or equal to pivot, pIndex
	// is incremented and that element would be placed before the pivot. 
	for (int i = low; i < high; i++)
	{
		if (a[i] <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}
	// swap pIndex with Pivot
	swap (a[pIndex], a[high]);
	
	// return pIndex (index of pivot element)
	return pIndex;
}

void QuickSort(int a[], int low, int high)
{
	// base condition
	if(low >= high)
		return;

	// rearrange the elements across pivot
	int pivot = Partition(a, low, high);

	// recur on sub-array containing elements that are less than pivot
	QuickSort(a, low, pivot - 1);

	// recur on sub-array containing elements that are more than pivot
	QuickSort(a, pivot + 1, high);
}

void optimizedQuickSort(int A[], int low, int high)
{
	while (low < high) 
	{
		// do insertion sort if 10 or smaller
		if(high - low < 10)
		{
			insertionSort(A, low, high);
			break;
		}
		else 
		{
			int pivot = Partition(A, low, high);
			
			// tail call optimizations - recur on smaller sub-array
			if (pivot - low < high - pivot) {
				optimizedQuickSort(A, low, pivot - 1);
				low = pivot + 1;
			} else {
				optimizedQuickSort(A, pivot + 1, high);
				high = pivot - 1;
			}
		}
	}	
}

int main()
{
	int arr[N], dup[N];
	
	// seed for random input
	srand(time(NULL));
 
	// to measure time taken by optimized and non-optimized Quicksort 
	clock_t begin, end;
	double t1 = 0.0, t2 = 0.0;
	
	// perform Quicksort NUM times and take average
	for(int i = 0; i < NUM; i++)
	{
		// generate random input
		for (int i = 0; i < N; i++)
			dup[i] = arr[i] = rand() % 100000;

		// Perform non-optimized Quicksort on arr
		begin = clock();
		QuickSort(arr, 0, N-1);
		end = clock();

		// calculate time taken by Non-Optimized QuickSort
		t1 += (double)(end - begin) / CLOCKS_PER_SEC;
		
		// Perform Optimized Quicksort on dup[]
		begin = clock();
		optimizedQuickSort(dup, 0, N-1);
		end = clock();

		// calculate time taken by optimized QuickSort
		t2 += (double)(end - begin) / CLOCKS_PER_SEC;
	}

	cout << "Average time taken by Non-Optimized Quicksort: " << t1/NUM;
	cout << "\nAverage time taken by Optimized Quicksort: " << t2/NUM;

	return 0;
}