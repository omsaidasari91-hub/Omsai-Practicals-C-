#include <stdio.h>

int main() {
    int i, j, space, rows;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    // Upper half
    for (i = 1; i <= rows; i++) {
        for (space = i; space < rows; space++)
            printf(" ");
        for (j = 1; j <= (2 * i - 1); j++)
            printf("%d", j);
        printf("\n");
    }

    // Lower half
    for (i = rows - 1; i >= 1; i--) {
        for (space = rows; space > i; space--)
            printf(" ");
        for (j = 1; j <= (2 * i - 1); j++)
            printf("%d", j);
        printf("\n");
    }

    return 0;
}
