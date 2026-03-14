#ifndef Algorithm_H
#define Algorithm_H


typedef struct
{
    int jobNr;
    int timeToComplete;
    int deadline;
    int penalty;
} Job;

int findMaxDeadline(Job *job, int n);

void rearrangeJobsByPenalty(Job *jobs, int n);

void findHeuristicOrder(Job *jobs, int n);

void fullMatchSearch(Job *jobs, int n);

#endif
