#include <stdio.h>
#include <assert.h>
#include "bst.h"

int main() {
    BST *tree = create();
    
    insert(tree, 50);
    insert(tree, 30);
    insert(tree, 70);
    insert(tree, 20);
    insert(tree, 40);
    insert(tree, 60);
    insert(tree, 80);

    printf("BST turinys (max 5 elementai): ");
    toString(tree, 5);

    printf("Ar medis tuscias? %s\n", isEmpty(tree) ? "Taip" : "Ne");
    printf("Elementų skaičius: %d\n", count(tree));

    BST *treeCopy = clone(tree);
    printf("Medzio kopija (max 10 elementų): ");
    toString(treeCopy, 10);

    printf("Subalansuotas medis: ");
    balance(tree);
    toString(tree,5);

    makeEmpty(tree);
    printf("makeEmpty atliekama medziui, ir bandoma spausdinti tuscio medzio turini.");
    toString(tree, 5);
    printf("Ar medis tuscias? %s\n", isEmpty(tree) ? "Taip" : "Ne");

    done(tree);
    done(treeCopy);
    return 0;
}
