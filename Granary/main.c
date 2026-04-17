#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "granary.h"


int main(){

    // User inputs
    int dienos; // How many days the simulation will run
    int kiekioNorma; // Daily purchase quantity (tonnes)
    int kiekioNuokrypis; // Max quantity deviation (%)
    int kainosNorma; // Daily purchase price (Eur/tonne)
    int kainosNuokrypis; // Max purchase price deviation (%)
    int antkainis; // markup % applied when selling 

    GranaryParams p;

    printf("Prašome įvesti pradinius duomenis\n");
    printf("Pirkimo trukmė dienomis: ");
    scanf("%d", &p.dienos);

    printf("Kiekio norma (t): ");
    scanf("%d", &p.kiekioNorma);

    printf("Didžiausias kiekio nuokrypis (%%): ");
    scanf("%d", &p.kiekioNuokrypis);

    printf("Kainos norma (Eur/toną): ");
    scanf("%d", &p.kainosNorma);

    printf("Didžiausias kainos nuokrypis (%%): ");
    scanf("%d", &p.kainosNuokrypis);

    printf("Pardavimo antkainis (%%): ");
    scanf("%d", &p.antkainis);

    GranaryResult simulationResult = simulateGranary(&p, 10);

    printGranarySimulationResults(&simulationResult);


    return 0;
}