#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algorithm.h"

int main(int argc, char* argv[]){
    if (argc < 2){
        fprintf(stderr, "Usage: %s [-|failo_vardas] [-mode [fullSearch|firstMatchSearch|heuristic heuristic_number]] [-timeout miliseconds]\n", argv[0]);
        return 1;
    }

    int searchMode = 2;
    // Searching for file
    FILE *inputFile = stdin;
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i],"-mode") == 0 || strcmp(argv[i], "-timeout") == 0){
            continue;
        } else if(strcmp(argv[i],"-") == 0){
            inputFile = stdin;
            if(inputFile == NULL){
                printf("ERROR: Programa nesugebėjo atidaryti failo\n");
                return 1;
            }
            break;
        } else if(argv[i][0] != '-'){
            inputFile = fopen(argv[i], "r");
            if(inputFile == NULL){
                printf("ERROR: Programa nesugebėjo atidaryti failo\n");
                return 1;
            }
            break;
        }
    }
    
    for(int i = 0; i < argc; i++){
        if(strcmp(argv[i],"-mode") == 0){
            if(i+1 >= argc){
                fprintf(stderr, "Usage: %s [-|failo_vardas] [-mode [fullSearch|firstMatchSearch|heuristic heuristic_number]] [-timeout miliseconds]\n", argv[0]);
                return 1;
            }
            
            if(strcmp(argv[i+1],"fullSearch") == 0){
                searchMode = 1;
            } else if(strcmp(argv[i+1], "firstMatchSearch") == 0){
                searchMode = 2;
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
    

    printf("==================================Pradiniai duomenys===================================\n");
    printf("Darbai kurie turi būti atliekami:\n");
    for(int i = 0; i < n; i++){
        printf(" - Darbas Nr. %d - Atlikimo trukmė: %d, Baigimo terminas: %d, Bauda už neatliktą darbą: %d\n", jobs[i].jobNr, jobs[i].timeToComplete,jobs[i].deadline,jobs[i].penalty);
    }
    printf("\n");

    if(searchMode == 1){
        printf("Paieškos režimas: fullSearch\n");
    } else if(searchMode == 2){
        printf("Paieškos rėžimas: firstMatchSearch\n");
    }
    printf("Skaičiavimų laiko apribojimas: \n");

    calculate(jobs,n,searchMode);


    free(jobs);

    return 0;
}