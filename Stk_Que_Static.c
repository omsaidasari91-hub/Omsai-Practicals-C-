#include <stdio.h>
#define SIZE 5

int stack[SIZE], top = -1;
int queue[SIZE], front = -1, rear = -1;

// ---------- STACK FUNCTIONS ----------
void push() {
    int value;
    if (top == SIZE - 1)
        printf("Stack Overflow!\n");
    else {
        printf("Enter value to push: ");
        scanf("%d", &value);
        stack[++top] = value;
        printf("Inserted %d into Stack\n", value);
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow!\n");
    else
        printf("Popped %d from Stack\n", stack[top--]);
}

void displayStack() {
    if (top == -1)
        printf("Stack is Empty!\n");
    else {
        printf("Stack Elements: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

// ---------- QUEUE FUNCTIONS ----------
void add() {
    int value;
    if (rear == SIZE - 1)
        printf("Queue Overflow!\n");
    else {
        printf("Enter value to add: ");
        scanf("%d", &value);
        if (front == -1)
            front = 0;
        queue[++rear] = value;
        printf("Inserted %d into Queue\n", value);
    }
}

void delete() {
    if (front == -1 || front > rear)
        printf("Queue Underflow!\n");
    else
        printf("Deleted %d from Queue\n", queue[front++]);
}

void displayQueue() {
    if (front == -1 || front > rear)
        printf("Queue is Empty!\n");
    else {
        printf("Queue Elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

// ---------- MAIN PROGRAM ----------
int main() {
    int choice, option;
    printf("Choose Model:\n1. Stack\n2. Queue\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        do {
            printf("\n--- STACK MENU ---\n");
            printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
            printf("Enter your option: ");
            scanf("%d", &option);
            switch (option) {
                case 1: push(); break;
                case 2: pop(); break;
                case 3: displayStack(); break;
                case 4: printf("Exiting Stack...\n"); break;
                default: printf("Invalid Option!\n");
            }
        } while (option != 4);
    }

    else if (choice == 2) {
        do {
            printf("\n--- QUEUE MENU ---\n");
            printf("1. Add\n2. Delete\n3. Display\n4. Exit\n");
            printf("Enter your option: ");
            scanf("%d", &option);
            switch (option) {
                case 1: add(); break;
                case 2: delete(); break;
                case 3: displayQueue(); break;
                case 4: printf("Exiting Queue...\n"); break;
                default: printf("Invalid Option!\n");
            }
        } while (option != 4);
    }

    else
        printf("Invalid Choice! Please choose 1 or 2.\n");

    return 0;
}

//algo
For Stack (using array)

Start

Initialize top = -1

Push: Insert element if top < SIZE-1

Pop: Remove element if top >= 0

Display: Print elements from top to 0

Stop

For Queue (using array)

Start

Initialize front = -1, rear = -1

Add (Enqueue): Insert element if rear < SIZE-1

Delete (Dequeue): Remove element if queue not empty

Display: Print elements from front to rear

Stop
