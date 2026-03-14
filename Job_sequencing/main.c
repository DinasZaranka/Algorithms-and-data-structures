#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "algorithm.h"
#include "branchAndBound.h"

int main(int argc, char* argv[]){
    if (argc < 2){
        fprintf(stderr, "Usage: %s [-|failo_vardas] [-mode [fullSearch|firstMatchSearch|heuristic heuristic_number]] [-timeout miliseconds]\n", argv[0]);
        return 1;
    }

    FILE *inputFile;
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i],"-") == 0){
        inputFile = stdin;
        } else {
            inputFile = fopen(argv[i], "r");
            if(inputFile == NULL){
                inputFile = stdin;
                printf("ERROR: Programa nesugebėjo atidaryti failo");
                return 1;
            }
        }
    
        if(strcmp(argv[i],"-mode") == 0){
            if(i+1 >= argc){
                fprintf(stderr, "Usage: %s [-|failo_vardas] [-mode [fullSearch|firstMatchSearch|heuristic heuristic_number]] [-timeout miliseconds]\n", argv[0]);
                return 1;
            }
            
            if(strcmp(argv[i+1],"fullSearch") == 0){
                printf("Full search mode\n");
            } else if(strcmp(argv[i+1], "firstMatchSearch") == 0){
                printf("Algorithm stops at the first Match\n");
            } else if(strcmp(argv[i+1], "heuristic") == 0){
                printf("euristika dar nerealizuota\n");
                return 1;
            } else {
                printf("Error: nežinomas paieškos režimas!\n");
                fprintf(stderr, "Usage: %s [-|failo_vardas] [-mode [fullSearch|firstMatchSearch|heuristic heuristic_number]] [-timeout miliseconds]\n", argv[0]);
                return 1;
            }
        }
    }

    int n;
    fscanf(inputFile,"%d",&n);

    Job *jobs = (Job*) malloc(n * sizeof(Job));

    if(jobs == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }

    for(int i = 0; i < n; i++){
        jobs[i].jobNr = i+1;
        fscanf(inputFile,"%d %d %d", &jobs[i].timeToComplete,&jobs[i].deadline,&jobs[i].penalty);
    }
    
    if(inputFile != stdin) {
        fclose(inputFile);
    }
    

    printf("--Darbai kurie turi būti atlikti--\n");
    for(int i = 0; i < n; i++){
        printf("Darbas Nr. %d - Atlikimo trukmė: %d, Baigimo terminas: %d, Bauda už neatliktą darbą: %d\n", jobs[i].jobNr, jobs[i].timeToComplete,jobs[i].deadline,jobs[i].penalty);
    }
    printf("\n");

    branchAndBoundCalculation(jobs,n);


    free(jobs);

    return 0;
}