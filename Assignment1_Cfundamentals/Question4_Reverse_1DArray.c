//Q4
//Write a C Program to reverse the given 1 D array. 
//Create a function for the reversal process.
#include <stdio.h>
#include <stdlib.h>

//swaps 2 no.s
void swap(int *x, int *y)
{
        int c = *x;
        *x = *y;
        *y = c;
}

/* filles up array with random values*/
void setArray(int a[],int n)
{
        for(int i = 0; i < n; i++)
        {
                a[i]=rand();
        }
}

/* Function to reverse an array */
void reverseArray(int a[], int n)
{
    int i,j;
    for(i=0,j=n-1;i<j;i++,j--)
    {
        swap(&a[i], &a[j]);
    }
}

/* Function to print an array */
void printArray(int a[], int n)
{
        int i;
        for (i=0; i < n; i++)
        printf("%d ", a[i]);
        printf("\n");
}

int main()
{
	int n=10;
	int a[n];
	setArray(a, n);
	printArray(a, n);
	reverseArray(a, n);
	printArray(a, n);
	return 0;
}

