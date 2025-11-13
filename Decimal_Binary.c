#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = x;
}

int pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int main() {
    int num, rem;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    while (num > 0) {
        rem = num % 2;
        push(rem);
        num = num / 2;
    }

    printf("Binary equivalent: ");
    while (top != -1)
        printf("%d", pop());

    return 0;
}
