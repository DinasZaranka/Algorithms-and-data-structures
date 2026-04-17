#ifndef GRANARY_H
#define GRANARY_H

#include "stack.h"
#include "queue.h"

typedef struct {
    int dienos;
    int kiekioNorma;
    int kiekioNuokrypis;
    int kainosNorma;
    int kainosNuokrypis;
    int antkainis;
} GranaryParams;

typedef struct {
    double fifoPelnas;
    double lifoPelnas;
} GranaryResult;

GranaryResult simulateGranary(const GranaryParams* p, int seed);

void printGranarySimulationResults(const GranaryResult* r);

#endif