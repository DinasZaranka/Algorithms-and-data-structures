#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "granary.h"

GranaryResult simulateGranary(const GranaryParams* p, int seed){

    srand(seed); // random number generation used for deviation

    int sandelioKiekis = 0;
    double sandelioVerte = 0; // Total value of all grains inside storage. Used for lifo calculations

    double fifoPelnas = 0;
    double lifoPelnas = 0;

    queue* fifoKiekis = Create(500);
    queue* fifoKaina  = Create(500);

    Stack lifoKiekis, lifoKainos;
    initStack(&lifoKiekis, 500);
    initStack(&lifoKainos, 500);


    for(int i = 0; i < p->dienos; i++){
        // Buying grain

        int minKiekis = p->kiekioNorma - (p->kiekioNorma * p->kiekioNuokrypis / 100);
        int maxKiekis = p->kiekioNorma + (p->kiekioNorma * p->kiekioNuokrypis / 100);
        int rangeKiekis = maxKiekis - minKiekis;

        int minKaina = p->kainosNorma - (p->kainosNorma * p->kainosNuokrypis / 100);
        int maxKaina = p->kainosNorma + (p->kainosNorma * p->kainosNuokrypis / 100);
        int rangeKaina = maxKaina - minKaina;

        int nupirktasKiekis = 
        (p->kiekioNuokrypis > 0) 
        ? minKiekis + rand() % (rangeKiekis + 1) 
        : p->kiekioNorma;

        int pirkimoKaina = 
            (p->kainosNuokrypis > 0) 
            ? minKaina + rand() % (rangeKaina + 1) 
            : p->kainosNorma;

        double naujaSvertineKaina =
            (sandelioKiekis == 0)
            ? pirkimoKaina
            : (sandelioVerte + (double)nupirktasKiekis * pirkimoKaina) / (sandelioKiekis + nupirktasKiekis);

        // Storing data
        enqueue(fifoKaina, pirkimoKaina);
        enqueue(fifoKiekis, nupirktasKiekis);

        push(&lifoKainos, naujaSvertineKaina);
        push(&lifoKiekis, nupirktasKiekis);

        sandelioKiekis += nupirktasKiekis;
        sandelioVerte += (double)nupirktasKiekis * pirkimoKaina;

        int parduotasKiekis = sandelioKiekis * (rand() % 101) / 100;


        // Selling the grain

        // FIFO
        int fifoLikutis = parduotasKiekis;

        while(fifoLikutis > 0 && !q_isEmpty(fifoKiekis)){
            int batchKiekis = q_peek(fifoKiekis);
            int batchKaina = q_peek(fifoKaina);

            if(batchKiekis <= fifoLikutis){
                // The whole batch is sold
                fifoPelnas += (double)batchKiekis * batchKaina * p->antkainis / 100.0;
                fifoLikutis -= batchKiekis;
                dequeue(fifoKiekis);
                dequeue(fifoKaina);
            } else {
                // Only part of the batch is sold
                int parduota = fifoLikutis;
                q_updateFirst(fifoKiekis, batchKiekis - parduota);

                fifoPelnas += (double)parduota * batchKaina * p->antkainis / 100.0;
                fifoLikutis = 0;
            }
        }

        // LIFO
        int lifoLikutis = parduotasKiekis;

        while(lifoLikutis > 0 && !st_isEmpty(&lifoKiekis)){
            int batchKiekis = peek(&lifoKiekis);
            double batchKaina = peek(&lifoKainos);

            if(batchKiekis <= lifoLikutis){
                lifoPelnas += (double)batchKiekis * batchKaina * (p->antkainis / 100.0);
                lifoLikutis -= batchKiekis;
                pop(&lifoKiekis);
                pop(&lifoKainos);
            } else {
                lifoPelnas += (double)lifoLikutis * batchKaina * (p->antkainis / 100.0);

                pop(&lifoKiekis);
                push(&lifoKiekis, batchKiekis - lifoLikutis);

                lifoLikutis = 0; // Finished selling
            }
        }

        if(sandelioKiekis > 0){
            sandelioVerte -= (double)parduotasKiekis * (sandelioVerte / sandelioKiekis);
            sandelioKiekis -= parduotasKiekis;
        }
    }

    GranaryResult r;
    r.fifoPelnas = fifoPelnas;
    r.lifoPelnas = lifoPelnas;

    Done(fifoKiekis);
    Done(fifoKaina);
    destroyStack(&lifoKiekis);
    destroyStack(&lifoKainos);

    return r;
}

void printGranarySimulationResults(const GranaryResult* r){
    printf("----Rezultatai----\n");
    printf("FIFO pelnas: %lf\n", r->fifoPelnas);
    printf("LIFO pelnas: %lf\n", r->lifoPelnas);

    if (r->fifoPelnas > r->lifoPelnas)
        printf("Naudingesnis metodas: FIFO\n");
    else if (r->lifoPelnas > r->fifoPelnas)
        printf("Naudingesnis metodas: LIFO\n");
    else
        printf("Abu metodai davė vienodą pelną\n");
}