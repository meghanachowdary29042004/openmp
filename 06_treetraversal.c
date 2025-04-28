#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void parallelPreorder(Node *root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    #pragma omp parallel sections
    {
        #pragma omp section
        parallelPreorder(root->left);
        #pragma omp section
        parallelPreorder(root->right);
    }
}

int main() {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Parallel Preorder Traversal: ");
    parallelPreorder(root);
    printf("\n");
}
