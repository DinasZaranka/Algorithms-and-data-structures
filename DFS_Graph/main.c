#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

static char *make_cfg_name(const char *exe_path){
    size_t len = strlen(exe_path);
    char *cfg = (char *)malloc(len + 5);
    if (!cfg) return NULL;
    strcpy(cfg, exe_path);

    char *dot = strrchr(cfg, '.');
    if (dot && strcmp(dot, ".exe") == 0) {
        strcpy(dot, ".cfg");
    } else {
        strcat(cfg, ".cfg");
    }
    return cfg;
}

int main(int argc, char *argv[]){
    const char *cfg_file = NULL;
    char *auto_cfg = NULL;

    if (argc >= 2) {
        cfg_file = argv[1];
    } else {
        auto_cfg = make_cfg_name(argv[0]);
        if (!auto_cfg) {
            fprintf(stderr, "Klaida: nepavyko sudaryti konfigūracijos failo vardo.\n");
            return 1;
        }
        cfg_file = auto_cfg;
    }

    GraphParams p;
    if (!readGraphData(cfg_file, &p)) {
        free(auto_cfg);
        return 1;
    }

    DFSResult r = graphDFS(&p);

    printf("------------------------------------------------------\n");
    printf("Pradiniai duomenys:\n\n");
    printGraphData(&p);

    printf("------------------------------------------------------\n\n");
    printf("------------------------------------------------------\n");
    printf("Vykdymas:\n\n");
    printGraphTree(&r);
    printf("------------------------------------------------------\n");
    // Medzio briaunu skaicius turi buti: virsuniu skaicius - 1
    if (r.edge_count == p.n - 1) { 
        printf("\nRezultatas: medis suformuotas teisingai.\n");
    } else {
        printf("\nRezultatas: KLAIDA - grafas gali buti nejungus.\n");
    }

    free(auto_cfg);
    return 0;
}