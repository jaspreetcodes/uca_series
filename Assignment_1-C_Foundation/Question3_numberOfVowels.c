//q3
// Write a C program to find the count of the number of 
// vowels and consonants in the given string. 
// (Update - Consider spaces and special characters as consonants)

#include <stdio.h>
int main()
{
    int i, j, cntnotc = 0, cntv =0;
    char a[] = { "AEIOUaeiou0123456789" };
    char str[500];
    scanf("%[^\n]",str);
    for(i = 0; str[i] != '\0'; i++)
    {
        for( j = 0; a[j] != '\0'; j++)
        {
            if((str[i] == a[j]) && (j < 10))
            {
                cntv++;
                cntnotc++;
                break;
            }
            else if(str[i] == a[j])
            {
                cntnotc++;
                break;
            }
        }
    }
    
    printf("no. of vowels :%d\nno. of consonants :%d",cntv,i - cntnotc);
    return 0;
}
