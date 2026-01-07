#include <stdio.h>

int main() {
    char str[100];
    int i = 0, j = 0;

    printf("Enter a string: ");
    scanf("%s", str);


    while (str[j] != '\0') {
        j++;
    }
    j = j - 1;   

    while (i < j) {
        if (str[i] != str[j]) {
            printf("The string is NOT a Palindrome");
            return 0;
        }
        i++;
        j--;
    }

    printf("The string is a Palindrome");

   printf("\n");
   printf("\n");
   printf("\n");

   char stri[100];
    int freq[256] = {0};   
    int p = 0;

    printf("Enter a string: ");
    scanf("%s", stri);

    
    while (stri[p] != '\0') {
        freq[stri[p]]++;
        p++;
    }


    printf("Character frequencies:\n");
    for (p = 0; p < 256; p++) {
        if (freq[p] != 0) {
            printf("%c = %d\n", p, freq[p]);
        }
    }

    return 0;
}
