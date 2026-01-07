#include <stdio.h>

void cube(int *p, int size)
{
    int i, j;

    printf("\nCubes of all elements:\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            int value = *(p + i * size + j);
            printf("%d ", value * value * value);
        }
        printf("\n");
    }
}

int main()
{
    int size;
    printf("Enter array's size: ");
    scanf("%d", &size);

    int a[size][size];   

    printf("\nEnter array elements:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    cube(&a[0][0], size);   

    
}
