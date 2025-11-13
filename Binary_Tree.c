#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert function
struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Inorder Traversal
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node* root = NULL;
    int choice, n, data, i;

    do {
        printf("\n\nBinary Search Tree Operations");
        printf("\n1. Creation of BST");
        printf("\n2. Traverse in Inorder");
        printf("\n3. Traverse in Preorder");
        printf("\n4. Traverse in Postorder");
        printf("\n5. Exit");
        printf("\n\nEnter Choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nBST for How Many Nodes ? ");
                scanf("%d", &n);
                for (i = 1; i <= n; i++) {
                    printf("Enter data for node %d : ", i);
                    scanf("%d", &data);
                    root = insert(root, data);
                }
                printf("\nBST with %d nodes is ready to Use!!\n", n);
                break;

            case 2:
                printf("\nBST Traversal in INORDER : ");
                inorder(root);
                break;

            case 3:
                printf("\nBST Traversal in PREORDER : ");
                preorder(root);
                break;

            case 4:
                printf("\nBST Traversal in POSTORDER : ");
                postorder(root);
                break;

            case 5:
                printf("\nTerminating\n");
                break;

            default:
                printf("\nInvalid Choice! Try again.\n");
        }
    } while (choice != 5);

    printf("\n=== Code Execution Successful ===\n");
    return 0;
}


//algo
Start

Define structure for BST node (data, left, right).

Create BST:

Input number of nodes.

Insert each node using BST rules.

Traversals (recursive):

Inorder: Left → Root → Right

Preorder: Root → Left → Right

Postorder: Left → Right → Root

Display menu repeatedly until user chooses Exit.

Stop
