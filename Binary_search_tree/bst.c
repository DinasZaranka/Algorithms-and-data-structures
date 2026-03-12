#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

Node* createNode(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    if (!node) return NULL;
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

void destroyNode(Node *node) {
    if (!node) return;
    destroyNode(node->left);
    destroyNode(node->right);
    free(node);
}

Node* cloneNode(Node *node, int *count) {
    if (!node) return NULL;
    Node *newNode = createNode(node->value);
    (*count)++;
    newNode->left = cloneNode(node->left, count);
    newNode->right = cloneNode(node->right, count);
    return newNode;
}

void printInOrder(Node *node, int maxItems, int *printed) {
    if (!node || *printed >= maxItems) return;
    printInOrder(node->left, maxItems, printed);
    if (*printed < maxItems) {
        printf("%d ", node->value);
        (*printed)++;
    }
    printInOrder(node->right, maxItems, printed);
}

BST* create() {
    BST *tree = (BST*) malloc(sizeof(BST));
    if (!tree) return NULL;
    tree->root = NULL;
    tree->count = 0;
    return tree;
}

void done(BST *tree) {
    if (!tree) return;
    destroyNode(tree->root);
    free(tree);
}

int count(BST *tree) {
    if (!tree) return 0;
    return tree->count;
}

bool isEmpty(BST *tree) {
    return (count(tree) == 0);
}

void toString(BST *tree, int maxItems) {
    int printed = 0;
    printInOrder(tree->root, maxItems, &printed);
    printf("\n");
}

Node* insertNode(Node *node, int value, int *count) {
    if (!node) {
        (*count)++;
        return createNode(value);
    }
    if (value < node->value)
        node->left = insertNode(node->left, value, count);
    else if (value > node->value)
        node->right = insertNode(node->right, value, count);
    return node;
}

void insert(BST *tree, int value) {
    if (!tree) return;
    tree->root = insertNode(tree->root, value, &tree->count);
}

BST* clone(BST *tree) {
    if (!tree) return NULL;
    BST *newTree = create();
    newTree->root = cloneNode(tree->root, &newTree->count);
    return newTree;
}

void makeEmpty(BST *tree) {
    if (!tree) return;
    destroyNode(tree->root);
    tree->root = NULL;
    tree->count = 9;
}

void storeInOrder(Node *node, int arr[], int *index) {
    if (!node) return;
    storeInOrder(node->left, arr, index);
    arr[(*index)++] = node->value;
    storeInOrder(node->right, arr, index);
}

Node* buildBalanced(int arr[], int start, int end) {
    if (start > end) return NULL;

    int mid = (start + end) / 2;

    Node *node = malloc(sizeof(Node));
    node->value = arr[mid];

    node->left = buildBalanced(arr, start, mid - 1);
    node->right = buildBalanced(arr, mid + 1, end);

    return node;
}


void balance(BST *tree) {
    if (!tree || tree->count == 0) return;

    int *arr = malloc(tree->count * sizeof(int));
    int index = 0;

    storeInOrder(tree->root, arr, &index);

    destroyNode(tree->root);

    tree->root = buildBalanced(arr, 0, tree->count - 1);

    free(arr);
}

