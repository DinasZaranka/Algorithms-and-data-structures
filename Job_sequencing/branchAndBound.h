#ifndef branchAndBound_H
#define branchAndBound_H

#include <stdbool.h>

#define MAX_STACK_SIZE 1000
#define MAX_JOB_COUNT 10

/*
 * Node struktura saugo viena medzio saka.
 * 
 * Kiekviena medzio saka saugo:
 *   schedule - darbo atlikimo tvarka
 *   jobsWithPenalty - darbai kurie atlikti paveluotai
 *   used - saugoma darbus, kurie jau buvo įdėti i schedule
 *   cost - visu baudu suma (iki pasirinktos)
 *   time - kiek laiko uztrunka tokia tvarka
 *   level - medzio lygis
 */
typedef struct Node{
    int schedule[MAX_JOB_COUNT];
    int jobsWithPenalty[MAX_JOB_COUNT];
    bool used[MAX_JOB_COUNT];
    int penaltyCost;
    int currentTime;
    int level;
} Node;


//Stack implementation
typedef struct {
    Node arr[MAX_STACK_SIZE];  
    int top;        
} Stack;

void initializeStack(Stack *stack);

bool isStackFull(Stack *stack);

bool isStackEmpty(Stack *stack);

void push(Stack *stack, Node node);

Node pop(Stack *stack);

// Job struct
typedef struct Job
{
    int jobNr;
    int timeToComplete;
    int deadline;
    int penalty;
} Job;

/*
 * fullSearch algorithm.
 *
 * How it works:
 *   1. We go through every possible solution
 *   2. We discard the solutions that aren't feasible (i.e. they take longer to complete than the maximum deadline that is give)
 *   3. Once we have complete solutions we then check through all possible job iterations to find the schedule that has the least penalty.
 *   
 * 
 */
void branchAndBoundCalculation(Job *jobs, int n);

int findMaxDeadline(Job *job, int n);

#endif