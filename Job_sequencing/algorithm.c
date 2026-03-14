#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include "algorithm.h"

int findMaxDeadline(Job *job, int n){
    int max = 0;
    for(int i = 0; i < n; i++){
        if(job[i].deadline > max){
            max = job[i].deadline;
        }
    }
    return max;
}

int min(int num1, int num2) {
   return (num1 < num2) ? num1 : num2;
}

int compareJobPenalty(const void* a, const void* b){
    if(((Job*)b)->timeToComplete>1 && ((Job*)a)->timeToComplete == 1){
        return (((Job*)b)->penalty)/(((Job*)b)->timeToComplete) - ((Job*)a)->penalty;
    } else if (((Job*)b)->timeToComplete == 1 && ((Job*)a)->timeToComplete > 1){
        return ((Job*)b)->penalty - (((Job*)a)->penalty)/(((Job*)a)->timeToComplete);
    } else {
        return ((Job*)b)->penalty - ((Job*)a)->penalty;
    }
}

void reorderangeJobsByPenalty(Job *jobs, int n){
    Job temp;
    qsort(jobs,n,sizeof(Job),compareJobPenalty);
}

void findHeuristicOrder(Job *jobs, int n){
    int maxDeadline = findMaxDeadline(jobs,n);
    bool slots[maxDeadline];
    memset(slots, 0, sizeof(slots)); //Initialize with all false values

    int result[maxDeadline];

    for(int i = 0; i < n; i++){
        for(int j = min(maxDeadline,jobs[i].deadline); j >= 0; j--){
            if(slots[j] == false){
                if(jobs[i].timeToComplete > 1){
                    int timeTaken = jobs[i].timeToComplete;
                    int availablePlaces = 0;
                    for(int x = j; x >= timeTaken; x--){
                        if(slots[x] == false){
                            availablePlaces++;
                        }
                    }
                    if(availablePlaces >= timeTaken){
                        while(timeTaken > 0){
                            slots[j-timeTaken] = true;
                            result[j-timeTaken] = i;
                            printf("Scheduled Job Nr.%d in slot %d\n",jobs[i].jobNr,j-timeTaken);
                            timeTaken--;
                        }
                        break;
                    }
                    
                } else {
                    result[j] = i;
                    slots[j] = true;
                    printf("Scheduled Job Nr.%d in slot %d\n",jobs[i].jobNr,j);
                    break;
                }
            }
        }
    }

    for(int i = 0; i < maxDeadline; i++){
        printf("time frame: [%d,%d] is reserved for Job Nr.%d\n",i,i+1,result[i]+1);
    }
}

int bestPenalty = INT_MAX;

void fullMatchSearch(Job *jobs, int n){
    
}
