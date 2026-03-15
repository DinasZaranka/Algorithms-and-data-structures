#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include "algorithm.h"

void initializeStack(Stack *stack) {
    stack->top = -1;  
}

bool isStackFull(Stack *stack) {
    return stack->top >= MAX_STACK_SIZE - 1;  
}

bool isStackEmpty(Stack *stack) {
    return stack->top == -1;  
}

void push(Stack *stack, Node node) {
    if (isStackFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = node;
}

Node pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack Underflow\n");
    }

    return stack->arr[stack->top--];
}

void calculate(Job *jobs, int n,int searchMode,int timeoutMs){
    
    // Stat variables
    int nodesChecked = 1;
    int bestSchedules[MAX_SOLUTIONS][MAX_JOB_COUNT];
    int bestCount = 0;
    int bestPenalty = INT_MAX;
    bool jobsWithPenalty[MAX_JOB_COUNT];
    bool timeoutReached = false;
    
    //Initialize root node
    Node root;
    root.penaltyCost = 0;
    root.level = 0;
    root.currentTime = 0;
    for(int i = 0; i < n; i++){
        root.used[i] = 0;
        root.schedule[i] = -1;
        jobsWithPenalty[i] = false;
    }
    
    // Initializing timer for timeout
    clock_t startTime = clock();
    double elapsed;
    //Create stack that holds all the solutions
    Stack stack;
    initializeStack(&stack);

    push(&stack,root);

    while(!isStackEmpty(&stack)){
        elapsed = (double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC;
        if(timeoutMs > 0 && elapsed >= timeoutMs){
            timeoutReached = true;
            break;
        }
        // Taking the next node to process
        Node current = pop(&stack);

        // Checking whether it is a complete solution
        if(current.level == n){
            int finishTime = 0;
            bool currentJobsWithPenalty[MAX_JOB_COUNT];
            for(int i = 0; i < n; i++){
                // Finding jobs that exceed the deadline and penalty will need to be paid
                finishTime += jobs[current.schedule[i]].timeToComplete;
                if(finishTime > jobs[current.schedule[i]].deadline){
                    currentJobsWithPenalty[i] = true;
                } else {
                    currentJobsWithPenalty[i] = false;
                }
            }
           
           if(current.penaltyCost < bestPenalty){
                bestPenalty = current.penaltyCost;
                bestCount = 0;

                memcpy(bestSchedules[bestCount], current.schedule, sizeof(int)*n);
                bestCount++;
            } else if(current.penaltyCost == bestPenalty){
                memcpy(bestSchedules[bestCount], current.schedule, sizeof(int)*n);
                bestCount++;
            }

        }

        // Creating all possible solutions
        for(int i = 0; i < n; i++){
            if(!current.used[i]){
                Node child = current;
                child.level = current.level + 1;
                child.schedule[current.level] = i;
                child.used[i] = true;

                int finishTime = child.currentTime + jobs[i].timeToComplete;
                child.currentTime = finishTime;

                //If jobs can't be completed in time
                if(finishTime>jobs[i].deadline){
                    child.penaltyCost += jobs[i].penalty;
                };

                //If current job schedule has a higher penalty than the previous best cost, we discard it
                if(child.penaltyCost >= bestPenalty && searchMode != 1){
                    continue;
                }
                nodesChecked++;
                push(&stack, child);
            }
        }

    }

    printf("\n======================================Sprendimai=======================================\n");

    for(int s = 0; s < bestCount; s++){
        printf("Sprendimas %d:\n", s+1);
        int finishTime = 0;

        for(int i = 0; i < n; i++){
            int jobIndex = bestSchedules[s][i];
            finishTime += jobs[jobIndex].timeToComplete;

            if(finishTime > jobs[jobIndex].deadline){
                printf(" %d. Darbas Nr. %d paveluotas, bauda: %d\n",i+1,jobIndex+1, jobs[jobIndex].penalty);
            } else {
                printf(" %d. Darbas Nr. %d atliktas laiku\n",i+1,jobIndex+1);
            }
        }

        printf("Baudų suma: %d\n\n", bestPenalty);
    }

    int AllNodesCount = countAllNodes(n);
    float percentageChecked = ((float)nodesChecked / AllNodesCount) * 100;
    printf("======================================Rezultatai=======================================\n");
    printf("Iš viso egzistuoja variantų:   %d\n", AllNodesCount);
    printf("Patikrinta variantų:           %d\n", nodesChecked);
    printf("Rasti sprendiniai:             %d\n", bestCount);
    
    if(!timeoutReached){
        printf("Paieška baigta iki galo, išnagrinėta %.2f%% variantų\n",percentageChecked);
    } else {
        printf("Paieška nutraukta. Pasiektas timeout, išnagrineta %.2f%% variantų\n", percentageChecked);
    }
    printf("\nPrograma užtruko:  %.3f ms.\n", elapsed);
    printf("\nMažiausia bauda, kurią teks sumokėti: %d\n", bestPenalty);
}

int countAllNodes(int n){
    int total = 1;
    int prod = 1;
    for(int k = 1; k <= n; k++){
        prod *= (n - k + 1);
        total += prod;
    }
    return total;
}