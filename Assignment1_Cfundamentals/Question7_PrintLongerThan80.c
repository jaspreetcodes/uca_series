#include <stdio.h>
#include <stdbool.h>

int main()
{
    char fileName[1000];

    printf("Enter the file name:\n");
    //scans a string until newline encountered
    scanf("%s", fileName);

    FILE *ptr = fopen(fileName, "r");

    //If file could not be opened
    if (!fileName)
    {
        printf("File could not be opened\n");
        return 0; //exiting the program
    }

    char input[1000]; //to read the input from file

    //scanning the strings
    while (fscanf(ptr, "%[^\n]%*c", input) != EOF)
    {
        //finding the length of the string
        int len = 0;
        while (input[len] != '\0')
        {
            len++;
        }

        //if length of string is greater than 80, then printing it
        if (len > 80)
        {
            printf("%s\n", input);
        }
    }
    
}
