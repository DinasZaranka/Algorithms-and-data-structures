#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "branchAndBound.h"

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


void branchAndBoundCalculation(Job *jobs, int n){
    
    int bestSchedule[MAX_JOB_COUNT];
    int bestPenalty = INT_MAX;
    int jobsWithPenalty[MAX_JOB_COUNT];
    //Initialize root node
    Node root;
    root.penaltyCost = 0;
    root.level = 0;
    root.currentTime = 0;
    for(int i = 0; i < n; i++){
        root.used[i] = 0;
        root.schedule[i] = -1;
        bestSchedule[i] = -1;
        jobsWithPenalty[i] = -1;
    }
    
    //Create stack that holds all the solutions
    Stack stack;
    initializeStack(&stack);

    push(&stack,root);

    while(!isStackEmpty(&stack)){
        // Taking the next node to process
        Node current = pop(&stack);

        // Checking whether it is a complete solution
        if(current.level == n){
            if(current.penaltyCost < bestPenalty){
                bestPenalty = current.penaltyCost;
                int finishTime = 0;
                for(int i = 0; i < n; i++){
                    bestSchedule[i] = current.schedule[i];
                    
                    // Finding jobs that exceed the deadline and penalty will need to be paid
                    finishTime += jobs[i].timeToComplete;
                    if(finishTime > findMaxDeadline(jobs,n)){
                        jobsWithPenalty[i] = i;
                    } else {
                        jobsWithPenalty[i] = -1;
                    }
                }
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
                if(child.penaltyCost >= bestPenalty){
                    continue;
                }
                push(&stack, child);
            }
        }

    }

    if(bestPenalty > 0){
        printf("--Darbo atlikimo tvarka, su kuria bauda mažiausia--\n");
        for(int i = 0; i < n; i++){
            if(jobsWithPenalty[i] == i){
                int penalty;
                for(int j = 0; j < n; j++){
                    if(jobs[j].jobNr == bestSchedule[i]+1){
                        penalty = jobs[j].penalty;
                    }
                }
                printf("Darbas Nr. %d atliktas paveluotai, bauda: %d\n",bestSchedule[i]+1, penalty);
            } else {
                printf("Darbas Nr. %d atliktas laiku\n",bestSchedule[i]+1);
            }
        }
        printf("\nBaudų, kurias reikės sumokėti suma: %d\n", bestPenalty);
    } else {
        printf("--Darbo atlikimo tvarka, su kuria bauda mažiausia--\n");
        for(int i = 0; i < n; i++){
            printf("Darbas Nr. %d \n",bestSchedule[i]+1);
        }
        printf("\nVisus darbus galima atlikti iki jų nurodytų terminų, jokių baudų mokėti nereikia.\n");
    }

}

int findMaxDeadline(Job *job, int n){
    int max = 0;
    for(int i = 0; i < n; i++){
        if(job[i].deadline > max){
            max = job[i].deadline;
        }
    }
    return max;
}
