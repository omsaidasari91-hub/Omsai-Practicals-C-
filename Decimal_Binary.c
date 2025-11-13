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

//algo
Start

Initialize an empty stack.

Input a decimal number.

While the number > 0:

Push (number % 2) onto the stack.

Divide the number by 2.

Pop and display all elements from the stack (binary digits).

Stop
