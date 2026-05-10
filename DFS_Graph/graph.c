#include <stdio.h>
#include <string.h>
#include "graph.h"

static int visited[MAX_V];

static void dfs_recursive(const GraphParams *p, int v, DFSResult *r){
    visited[v] = 1;
    r->visit_order[r->visit_count++] = v;
 
    for (int i = 0; i < p->n; i++) {
        if (p->matrix[v][i] == 1 && !visited[i]) {
            /* Išsaugome briauną aplankymo tvarka */
            r->edge_from[r->edge_count] = v;
            r->edge_to[r->edge_count]   = i;
            r->tree_from[i] = v;
            r->edge_count++;
            dfs_recursive(p, i, r);
        }
    }
}

int readGraphData(const char *filename, GraphParams *p){
    FILE *f = fopen(filename, "r");
    if (!f) {
        fprintf(stderr, "Klaida: nepavyko atidaryti failo '%s'\n", filename);
        return 0;
    }

    char line[256];
    if (!fgets(line, sizeof(line), f) || sscanf(line, "%d", &p->n) != 1 || p->n <= 0 || p->n > MAX_V) {
        fprintf(stderr, "Klaida: netinkamas virsunių skaičius faile '%s'\n", filename);
        fclose(f);
        return 0;
    }

    for (int i = 0; i < p->n; i++) {
        for (int j = 0; j < p->n; j++) {
            if (fscanf(f, "%d", &p->matrix[i][j]) != 1) {
                fprintf(stderr, "Klaida: trūksta duomenų matricoje (eilutė %d, stulpelis %d)\n", i, j);
                fclose(f);
                return 0;
            }
        }
    }

    fclose(f);
    return 1;
}


void printGraphData(const GraphParams *p){
    printf("Kaimynystės matrica:\n\n");
    printf("   ");
    for (int i = 0; i < p->n; i++) printf(" %d", i+1);
    printf("\n\n");
    for (int i = 0; i < p->n; i++) {
        printf("%d  ", i+1);
        for (int j = 0; j < p->n; j++) printf(" %d", p->matrix[i][j]);
        printf("\n");
    }
    printf("\nViršūnių skaičius: %d\n", p->n);
}

// Vykdo DFS nuo viršūnės 0 ir grąžina DFSResult
DFSResult graphDFS(const GraphParams *p){
    DFSResult r;
    r.edge_count  = 0;
    r.visit_count = 0;
    for (int i = 0; i < MAX_V; i++) {
        r.tree_from[i] = -1;
    }

    memset(visited, 0, sizeof(visited));

    dfs_recursive(p, 0, &r);

    return r;
}

void printGraphTree(const DFSResult *r){
    printf("DFS medžio briaunos:\n");
    for (int i = 0; i < r->edge_count; i++) {
        printf("  (%d -> %d)\n", r->edge_from[i]+1, r->edge_to[i]+1);
    }

    printf("\nDFS aplankymo tvarka: ");
    for (int i = 0; i < r->visit_count; i++) {
        printf("%d", r->visit_order[i]+1);
        if (i < r->visit_count - 1) printf(" -> ");
    }
    printf("\n");
}
