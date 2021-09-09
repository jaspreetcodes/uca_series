#include <stdio.h>
#include<stdlib.h>
void disp(int *a, int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
//using property of selection sort that k passes are useful
void sel(int *a, int m,int n)
{
    int i,temp,min_ind,j;
    for(i=0;i<n;i++)
    {
        min_ind=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min_ind])
            min_ind=j;
        }
        temp=a[min_ind];
        a[min_ind]=a[i];
        a[i]=temp;
    }
}

int main()
{
    int m,n;
    printf("Enter size : \n");
    scanf("%d",&n);
    int i,k,a[n];
    for(i=0;i<n;i++)
    {
     k=rand();
     a[i]=k%20000 + 1;
    }
    disp(a,n);
    scanf("%d",&m);
    sel(a,m,n);
    disp(a,n);
    printf("%d",a[m-1]);

    return 0;
}
