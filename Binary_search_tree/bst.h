#ifndef BST_H
#define BST_H

#include <stdbool.h>

/*
 * Node struktura saugo viena medzio saka.
 * 
 * Kiekviena medzio saka saugo:
 *   value - sakos virsunes reiksme
 *   left - rodykle i kaire saka (reiksme mazesne uz virsune) 
 *   right - rodykle i desine saka (reiksme didesne uz virsune) 
 */
typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

/*
 * BST Struktura saugo visa dvejetaini paieskos medi
 *
 * root - rodykle i medzio sakni
 * count - kiekis elementu medyje
 */
typedef struct BST {
    Node *root;
    int count;
} BST;

/*
 * Konstrukorius.
 * Dinamiskai sukuria tuscia medzio(BST) objekta
 *
 * Postcondition:
 *   root == NULL
 *   count == 0
 */
BST* create();

/*
 * Destruktorius.
 *
 * Rekursiskai pasalini visas medzio sakas
 * Atlaisvina pati medzio objekta
 *
 * Po iskvietimo daugiau nebegalima naudoti medzio
 */
void done(BST *tree);

int count(BST *tree); // Grazina medzio elementu kieki
bool isEmpty(BST *tree); // Grazina True jeigu medis tuscias; False priesingu atveju
void toString(BST *tree, int maxItems); // Grazina maxItems kieki medzio elementu didejancia tvarka

/*
 * Ideda nauja elementa i medi.
 *
 * Jei reiksme jau egzistuoja - nededama.
 * 
 * Postcondition:
 *   Jeigu reiksme nauja - count padideja 1 
 */
void insert(BST *tree, int value);

/*
 * Rekursiskai sukuria medzio kopija.
 *
 * Sukuriamas naujas nepriklausomas medzio objektas.
 */
BST* clone(BST *tree);

/*
 * Isvalo visas medzio sakas.
 * Pats medzio objektas lieka egzistuoti.
 * 
 * Postcondition:
 *   root == NULL
 *   count == 0
 *   isEmpty() == true
 */
void makeEmpty(BST *tree);

/*
 * Subalansuoja duota medi.
 *
 * Algoritmas:
 *   1.Apeina visa medi KVD tvarka ir issaugo visas medzio reiksmes i masyva.
 *   2.Perrenka nauja medi is vidurio.
 * 
 * Komanda pakeicia medzio struktura.
 */
void balance(BST *tree);

#endif
