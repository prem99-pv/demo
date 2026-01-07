#include <stdio.h>

int main()
{

    int b;
    printf("Enter the array size: ");
    scanf("%d", &b);

    int arr[b];
    printf("Enter the array elements:\n");
    for(int n = 0; n < b; n++){
        scanf("%d", &arr[n]);
    }

    printf("Negative elements from array: ");
    for(int g = 0; g < b; g++){
        if(arr[g] < 0){
            printf("%d ", arr[g]);
        }
    }

    printf("\n\n");

    

    int row1, col1;
    printf("Enter rows: ");
    scanf("%d", &row1);

    printf("Enter columns: ");
    scanf("%d", &col1);

    int l[row1][col1];
    printf("Enter array elements:\n");
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < col1; j++){
            scanf("%d", &l[i][j]);
        }
    }

    int max = l[0][0];
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < col1; j++){
            if(l[i][j] > max){
                max = l[i][j];
            }
        }
    }
    printf("Largest element = %d\n\n", max);

    
    int n;
    int d[10][10], t[10][10];

    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &d[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            t[j][i] = d[i][j];
        }
    }

    printf("Transpose matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }

    printf("\n");


    int a[10][10];
    int r, c, row, col;
    int rowSum = 0, colSum = 0;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter row number: ");
    scanf("%d", &row);

    for(int j = 0; j < c; j++){
        rowSum += a[row][j];
    }
    printf("Sum of row %d = %d\n", row, rowSum);

    printf("Enter column number: ");
    scanf("%d", &col);

    for(int i = 0; i < r; i++){
        colSum += a[i][col];
    }
    printf("Sum of column %d = %d\n", col, colSum);

    return 0;
}
