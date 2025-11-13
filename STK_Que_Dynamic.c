#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;     // For Stack
struct node *front = NULL;   // For Queue
struct node *rear = NULL;

// ---------- STACK FUNCTIONS ----------
void push() {
    struct node *newNode;
    int value;
    newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL)
        printf("Memory allocation failed!\n");
    else {
        printf("Enter value to push: ");
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        printf("Inserted %d into Stack\n", value);
    }
}

void pop() {
    if (top == NULL)
        printf("Stack Underflow!\n");
    else {
        struct node *temp = top;
        printf("Popped %d from Stack\n", top->data);
        top = top->next;
        free(temp);
    }
}

void displayStack() {
    if (top == NULL)
        printf("Stack is Empty!\n");
    else {
        struct node *temp = top;
        printf("Stack Elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// ---------- QUEUE FUNCTIONS ----------
void add() {
    struct node *newNode;
    int value;
    newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL)
        printf("Memory allocation failed!\n");
    else {
        printf("Enter value to add: ");
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        printf("Inserted %d into Queue\n", value);
    }
}

void delete() {
    if (front == NULL)
        printf("Queue Underflow!\n");
    else {
        struct node *temp = front;
        printf("Deleted %d from Queue\n", front->data);
        front = front->next;
        if (front == NULL)
            rear = NULL;
        free(temp);
    }
}

void displayQueue() {
    if (front == NULL)
        printf("Queue is Empty!\n");
    else {
        struct node *temp = front;
        printf("Queue Elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// ---------- MAIN FUNCTION ----------
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
