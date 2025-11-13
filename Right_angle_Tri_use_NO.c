#include <stdio.h>

int main() {
    int i, j, rows;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}




\\allgo
Start

Read number of rows n

For i = 1 to n
  For j = 1 to i
   Print j
  End inner loop
  Print new line

End
