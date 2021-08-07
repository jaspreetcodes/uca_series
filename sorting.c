/**
 * Program to implement sorting algos on array of integers and analyze their runtime complexities.
 * 
 * Compilation: gcc sorting.c
 * Execution:   ./a.out
 *
 * @Jaspreet_Singh (1910991347), 28th july 2021
 * Day2_Coding_Assignment/ Analyzing runtime complexities of sorts problem ...
 *
 * (resources:
 *	https://linuxhint.com/gettimeofday_c_language/
 *	https://linuxize.com/post/vim-find-replace/
 *	https://www.geeksforgeeks.org/bool-in-c/
 * )
 */

// Program to implement sorting algos on array of integers and analyze their runtime complexities.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>

// returns epoch (Since 1970)time elapsed 
long int timeElapsed()
{
    struct timeval time;
    gettimeofday(&time,NULL);
    long int te = time.tv_sec*1000 + time.tv_usec/1000;
    return te;
}

// filles up array with random values
void setArray(int a[],int n)
{
        for(int i = 0; i < n; i++)
        {
                a[i]=rand();
        }
}

//swaps 2 no.s
void swap(int *x, int *y)
{
        int c = *x;
        *x = *y;
        *y = c;
}

// A function to implement bubble sort
//returns time taken by algo (in ms)
long int bubbleSort(int a[], int n)
{
        int i, j;
        long int past, present;
        past = timeElapsed();
        for (i = 0; i < n-1; i++)
            {
                    // Last i elements are already in place
                    for (j = 0; j < n-i-1; j++)
                            if (a[j] > a[j+1])
                                    swap(&a[j], &a[j+1]);
            }
        present = timeElapsed();        
        return present - past;
}

//A function to implement optimized bubble sort
//returns time taken by algo (in ms)
long int bubbleSortOp(int a[], int n)
{
    int i, j;
    bool noSwaps = true;
    long int past, present;
    past = timeElapsed();
    for (i = 0; i < n-1; i++)
        {
            noSwaps = true;
            // Last i elements are already in place
            for (j = 0; j < n-i-1; j++)
                if (a[j] > a[j+1])
                   {
                       swap(&a[j], &a[j+1]);
                       noSwaps = false;
                   }
        
            if(noSwaps)
            break;
        }
    present = timeElapsed();        
    return present - past;
}

// A function to implement Insertion sort
//returns time taken by algo (in ms)

long int insertionSort(int a[],int n)
{
    int i,j,key;
    long int past,present;
    past = timeElapsed();
    for(i = 1; i < n; i++)
    {
        key = a[i];
        for(j = i-1; (j>=0)&&(a[j] > key); j--)
        {
            a[j+1]=a[j];
        }
        a[j+1] = key;
    }
    present = timeElapsed();        
    return present - past;
}

// A function to implement selection sort
//returns time taken by algo (in ms)
long int selectionSort(int a[],int n)
{
    int i, j ,minI=0;
    long int past, present;
    past = timeElapsed();
    for (i = 0; i < n-1; i++)
        {
            minI = i;
            // Last i elements are already in place
            for (j = i+1; j < n; j++)
                    if (a[minI] > a[j])
                            minI = j;
            swap(&a[minI], &a[i]);
        }
    present = timeElapsed();        
    return present - past;
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



// Driver program to test above functions
int main()
{
    //variable delarations
    int n=36000;
    int a[n];
    long int avgtbs, avgtbsop, avgtis, avgtss;
    long int worsttbs, worsttbsop,worsttis, worsttss;
    long int besttbs, besttbsop, besttis, besttss;
    
    //main code
        //insertionSort callings
        setArray(a, n);
        avgtis= insertionSort(a, n);
        besttis= insertionSort(a, n);
        reverseArray(a,n);
        worsttis= insertionSort(a, n);
        
        //selectionSort callings
        setArray(a, n);
        avgtss= selectionSort(a, n);
        besttss= selectionSort(a, n);
        reverseArray(a,n);
        worsttss= selectionSort(a, n);
        
        //bubbleSort optimized
        // setArray(a, n);
        // avgtbsop= bubbleSortOp(a, n);
        // besttbsop= bubbleSortOp(a, n);
        // reverseArray(a,n);
        // worsttbsop= bubbleSortOp(a, n);
        
        //bubbleSort callings
        setArray(a, n);
        avgtbs= bubbleSort(a, n);
        besttbs= bubbleSort(a, n);
        reverseArray(a,n);
        worsttbs= bubbleSort(a, n);
        
    printf("n = %d \nTime taken \n",n);
    printf("InsertionSort\n\tRANDOM (avg case): %ld\n\tASC (best case): %ld\n\tDESC (worst case): %ld\n",avgtis,besttis,worsttis);
    printf("SelectionSort\n\tRANDOM (avg case): %ld\n\tASC (best case): %ld\n\tDESC (worst case): %ld\n",avgtss,besttss,worsttss);
    // printf("BubbleSortOp\n\tRANDOM (avg case): %ld\n\tASC (best case): %ld\n\tDESC (worst case): %ld\n",avgtbsop,besttbsop,worsttbsop);
    printf("BubbleSort\n\tRANDOM (avg case): %ld\n\tASC (best case): %ld\n\tDESC (worst case): %ld\n",avgtbs,besttbs,worsttbs);
    return 0;
}

/* Performs sorting
 *
 * Parameters
 * //In main:
 * 	avg - average
 *	t - time
 *	bs - bubble sort
 *	is - insertion sort
 *	ss - selection sort
 *	bsop - bubble sort optimized
 * avgtbs: average case time elapsed in bubble sort( random )
 * besttis: best case time elapsed in bubble sort( sorted )
 * worsttis: worst case time elapsed in selection sort( reverse sorted )
 *
 * //everywhere:
 * past: time before algo started
 * present: time after algo ended
 * a: Pointer to an array of integers
 * n: length of the array
 * minI: minimum index (index of (supposed)minimum element) 
 * Prints best, worst, avg case times of all 4 algos
 */
