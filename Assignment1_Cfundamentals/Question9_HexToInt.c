/* Q9
Write the function htoi(char* s), 
which converts a string of hexadecimal digits 
(including an optional 0x or 0X) into its equivalent integer value. 
The allowable digits are 0 through 9, 11 through f, and A through F
*/
#include <stdio.h>
#include <math.h>
int slength(char str[])
{
    int i;
	for( i = 0; str[i] != '\0'; i++);
	return i;
}
		
int htoi(char str[])
{
	int i, j = 0, n, hi = 0;
	n = slength(str);
	for(i = n - 1; i > 1; i--)
	{
		if( str[i] >= 'a')
			hi += pow(16,j) * (str[i] - '7' - 32);
		
		else if( str[i] >= 'A')
		    hi += pow(16,j) * (str[i] - '7');
		    
		else if( str[i] >= '0')
		    hi += pow(16,j) * (str[i] - '0');
		    
		    j++;
	}
	
	return hi;
}
int main()
{
	char s[10] ;
	scanf("%s", s);
	printf("%d",htoi(s));	
	return 0;
}
