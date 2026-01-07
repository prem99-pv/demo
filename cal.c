#include <stdio.h>

// User Defined Functions
int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

float divi(int a, int b) {
    return (float)a / b;
}

int mod(int a, int b) {
    return a % b;
}

int main() {
    int a, b, choice;
    char ch;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Modulus (%%)\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("Enter first number: ");
        scanf("%d", &a);

        printf("Enter second number: ");
        scanf("%d", &b);

        switch (choice) {
            case 1:
                printf("Result = %d", add(a, b));
                break;

            case 2:
                printf("Result = %d", sub(a, b));
                break;

            case 3:
                printf("Result = %d", mul(a, b));
                break;

            case 4:
                if (b != 0)
                    printf("Result = %.2f", divi(a, b));
                else
                    printf("Division by zero not allowed");
                break;

            case 5:
                if (b != 0)
                    printf("Result = %d", mod(a, b));
                else
                    printf("Modulus by zero not allowed");
                break;
            default:
                printf("Invalid choice");
        }
    } while (ch != 'X' && ch != 'x');

    
}
