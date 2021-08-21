/* C program for mth smallest */
#include <stdio.h>
#include <stdlib.h>

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int selectionSort{
}

/* Driver code */
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	int m;
	printf("Given array is \n");
	printArray(arr, arr_size);

	scanf(" %d",&m);
	selectionSort(arr, 0, m, arr_size - 1);

	printf("\n mth smallest number is %d \n",selectionSort(arr);
	return 0;
}

