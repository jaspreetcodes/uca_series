/**
 * Program to implement sorting algos on array of integers and analyze their run
 * time complexities.
 * 
 * Compilation: gcc sorting.c
 * Execution:   ./
 *
 * @Jaspreet_Singh (1910991347), 28th july 2021
 * Day2_Coding_Assignment/ Analyzing runtime complexities of sorts problem ...
 *
 * (resources)
 */
// Program to implement sorting algos on array of integers and analyze their runtime complexities.

#include <stdio.h>
#include <stdbool.h>

//swaps 2 no.s
void swap(int *x, int *y)
{
        int c = *x;
        *x = *y;
        *y = c;
}

//returns 
int bubbleSortOp(int a[], int n)
{
    int i, j, cnt = 0;
    bool noSwaps = true;
    for (i = 0; i < n-1; i++)
        {
            noSwaps = true;
            // Last i elements are already in place
            for (j = 0; j < n-i-1; j++)
                if (a[j] > a[j+1])
                   {
			swap(&a[j], &a[j+1]);
                        cnt++;
			noSwaps = false;
                   }
        
            if(noSwaps)
            break;
        }
    return cnt;
}

int main()
{
    //variable declaration
    int n, i;
    //scan
    printf("Please Enter array length");
    scanf("%d",&n);
    int a[n];
    for(i = 0; i < n; i++)
    {
	scanf("%d",&a[i]);
	
    }
    printf("%d",bubbleSortOp(a, n));

}
/* Performs sorting
 *
 * Parameters
 *
 * avgtbs: average case time elapsed in bubble sort( random )
 * besttis: best case time elapsed in bubble sort( sorted )
 * worsttis: worst case time elapsed in selection sort( reverse sorted )
 *
 * Prints best, worst, avg case times of all 4 algos
 *
*/


