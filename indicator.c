#include <stdio.h>

int main()
{
    char str[100];
    char *ptr;
    int length = 0;

    printf("Enter any string: ");
    scanf("%[^\n]", str);   

    ptr = str;             

    while (*ptr != '\0')
    {
        length++;
        ptr++;
    }

    printf("The length of a string is: %d", length);

    
}
