#include <stdio.h>

int main() {
    int i, j, space, rows;
    char ch;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++) {
        for (space = i; space < rows; space++)
            printf(" ");
        ch = 'A';
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("%c", ch);
            ch++;
        }
        printf("\n");
    }

    return 0;
}
