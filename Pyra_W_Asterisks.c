#include <stdio.h>

int main() {
    int i, j, space, rows;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++) {
        for (space = i; space < rows; space++)
            printf(" ");
        for (j = 1; j <= (2 * i - 1); j++)
            printf("*");
        printf("\n");
    }

    return 0;
}

//algo
Start

Read number of rows n

For i = 1 to n
  a. Print spaces (n - i)
  b. Print asterisks * from 1 to (2*i - 1)
  c. Print new line

End
