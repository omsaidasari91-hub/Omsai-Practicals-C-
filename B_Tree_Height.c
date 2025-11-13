#include <stdio.h>
#include <stdlib.h>

// Define structure for BST node
struct node {
    int data;
    struct node *left, *right;
};

// Create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node in BST
struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Inorder traversal
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Calculate height of tree
int height(struct node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Find depth of a node
int findDepth(struct node* root, int x, int depth) {
    if (root == NULL)
        return -1; // not found
    if (root->data == x)
        return depth;
    else if (x < root->data)
        return findDepth(root->left, x, depth + 1);
    else
        return findDepth(root->right, x, depth + 1);
}

int main() {
    struct node* root = NULL;
    int n, data, i, key, d;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the node values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("\nInorder traversal of BST: ");
    inorder(root);

    printf("\nHeight of the tree: %d", height(root));

    printf("\nEnter a node value to find its depth: ");
    scanf("%d", &key);

    d = findDepth(root, key, 0);
    if (d >= 0)
        printf("\nDepth of node %d: %d\n", key, d);
    else
        printf("\nNode %d not found in the tree\n", key);

    printf("\n=== Code Execution Successful ===\n");
    return 0;
}

//algo
Start

Define a structure for BST node (data, left, right).

Insert nodes into BST using standard BST insertion rules.

Perform Inorder Traversal (Left → Root → Right).

To find Height:

Recursively find the height of left and right subtrees.

Height = 1 + max(leftHeight, rightHeight).

To find Depth of a given node:

Start from the root,

Traverse until the node is found, counting the levels.

Display inorder traversal, height, and depth.

Stop
