#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
			//Swap Function
void swap(int* a, int* b)
{
int t = *a;
*a = *b;
*b = t;
}


			// Quick SOrt Function 
//initialization
int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high- 1; j++) 
	{
	if (arr[j] <= pivot) 
	{
	i++;
	swap(&arr[i], &arr[j]);
	}
}
swap(&arr[i + 1], &arr[high]);
return (i + 1);
}
//Quick sort Function
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
	int pi = partition(arr, low, high);
	quickSort(arr, low, pi - 1);
	quickSort(arr, pi + 1, high);
	}
}




			// Insertion Sort Function
//Insertion Sort Function
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		
	}

}
int main()
{
int num_Of_array = 100000;
int n_Of_array = 100000;
int i;
int arr[num_Of_array];
int m[n_Of_array];
for (i=0;i< num_Of_array ;i++) {
		 arr[i] = rand() % 100000;
}
   	printf("Array of 100000 random numbers is nitialized \n");
   	printf("\n\n");

int n = sizeof(arr)/sizeof(arr[0]);
clock_t start, end;
 start=clock();
quickSort(arr, 0, n-1);
 end=clock() - start;
double time_used = ((double)end)/CLOCKS_PER_SEC;
printf("The array is sorted using quick sort in  %f second",((double)end)/CLOCKS_PER_SEC); 
printf("\n");
for (i=0;i< n_Of_array ;i++) {
		 m[i] = rand() % 100000;
}
 start=clock();
insertionSort(m, n);
 end=clock() - start;
printf("The array is sorted using insertion sort in %f second",((double)end)/CLOCKS_PER_SEC); 

return 0;
}