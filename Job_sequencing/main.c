#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algorithm.h"

int main(int argc, char* argv[]){
    if (argc < 2){
        fprintf(stderr, "Usage: %s [-|failo_vardas] [-mode [fullSearch|firstMatchSearch|heuristic heuristic_number]] [-timeout miliseconds]\n", argv[0]);
        return 1;
    }

    FILE *inputFile;
    if(strcmp(argv[1],"-") == 0){
        inputFile = stdin;
    } else {
        inputFile = fopen(argv[1], "r");
        if(inputFile == NULL){
            printf("Couldn't open file");
            return 1;
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
        fscanf(inputFile,"%d %d %d", &jobs[i].timeToComplete,&jobs[i].deadline,&jobs[i].penalty);
    }
    
    if(inputFile != stdin) {
        fclose(inputFile);
    }
    

    printf("--Input Job Information--\n");
    for(int i = 0; i < n; i++){
        printf("Job %d - Time: %d, Deadline: %d, Penalty: %d\n", i+1, jobs[i].timeToComplete,jobs[i].deadline,jobs[i].penalty);
    }

    free(jobs);

    return 0;
}