#include<stdio.h>

int main()
{
    for(int i=41; i<=45; i++)
    {
       
      for(int j=41;j<=i;j++)
     {
         printf("%d", j);
           
    }
      printf("\n");
    }
    printf("\n");
    printf("\n");
   printf("\n");

   int b,c;
    int num=11;
 for(int b=1; b<=4; b++)
 {
       
    for(int c=1;c<=b;c++)
    {
           printf("%d", num);
           num++;
    }
       printf("\n");
}
    printf("\n");
    printf("\n");
    printf("\n");

    for(int i=5; i>=1; i--){
       for( int k=1; k<=i-1; k++)
          {
            printf(" ");
          }
        for( int j=5; j>=i; j--)
        {
            printf("%d",j);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
   printf("\n");
   for(int i=1; i>=0; i--){
       for( int j=i; j>=1; j--)
        {
            printf("%d",j);
        }
       printf("\n");
    }
    printf("\n");
    printf("\n");
   printf("\n");


    int i, j, k;

    for (i = 5; i >= 1; i--) {
        
for (k = 5; k > i; k--) {
           printf(" ");
      }
        for (j = 1; j <= i; j++) {
          if (j % 2 == 1)
               printf("1 ");
           else
              printf("0 ");
       }
        printf("\n");
    }
   printf("\n");
    printf("\n");
   printf("\n");
   int p, n, m;
    for (p = 5; p >= 1; p--) {
       for (n = 1; n < p; n++) {
           printf("  ");
       }
       for (m = p; m <= 5; m++) {
            printf("%d ", m);
       }
     for (m = 4; m>= i; m--) {
          printf("%d ", m);
       }
      printf("\n");
   }
   printf("\n");
    printf("\n");
    printf("\n");
   
    int d = 5;

    for (int e = 1; e <= d; e++)
    {
        for (int f = 1; f <= e; f++)
        {
            printf("%d ", f);
        }
        if (e != d)
        {
            for (int m = 1; m <= 2 * (d - e); m++)
            {
                printf("  ");
            }
        }
        for (int g = e; g >= 1; g--)
        {
           printf("%d ", g);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    printf("\n");
     int r, a;

    for (r = 1; r <= 5;r++) {
        for (a = 1; a <= 5; a++) {

            if (r == 1 || r == 3 || a == 1 || a == 5) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
}
