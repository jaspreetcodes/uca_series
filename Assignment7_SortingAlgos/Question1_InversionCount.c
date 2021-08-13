/**
 * Program to implement sorting algos on array of integers and count no of inversions possible.
 * 
 * Compilation: gcc Question1_InversionCount.c -o Question1_InversionCount
 * Execution:   ./Question1_InversionCount
 *
 * @Jaspreet_Singh (1910991347), 11th august 2021
 * Assignment_7-SortingAlgos Count of Inversions/ 
 *
 * (resources)
 */

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
 * n : Array length
 * a[n] : Array
 * i ,j : variables for iterative progression
 *
 *
 * Prints inversion count. 
 *
*/
