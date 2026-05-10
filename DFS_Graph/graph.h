#ifndef GRAPH_H
#define GRAPH_H

#define MAX_V 100 // Max viršūnių skaičius

typedef struct {
    int n;                    // viršūnių skaičius 
    int matrix[MAX_V][MAX_V]; // kaimynystės matrica 
} GraphParams;

typedef struct {
    int tree_from[MAX_V];   // tree_from[i] = tėvas; -1 jei šaknis arba neaplankyta
    int edge_count;         // medžio briaunų skaičius (turi būti n-1)
    int visit_order[MAX_V]; // aplankymo tvarka
    int visit_count;        // kiek viršūnių aplankyta
    int edge_from[MAX_V];   // aplankymo tvarka: briaunos tėvas 
    int edge_to[MAX_V];     // aplankymo tvarka: briauno vaikas 
} DFSResult;

// Nuskaito pradinius duomenis
int readGraphData(const char *filename, GraphParams *p);

// Atspausdina nuskaitytą kaimynystės matricą
void printGraphData(const GraphParams *p);

// Vykdo DFS ir grąžina rezultatą
DFSResult graphDFS(const GraphParams *p);

// Atspausdina sukonstruota medį
void printGraphTree(const DFSResult *r);

#endif
