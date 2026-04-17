#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "granary.h"

static char* makeCfgName(const char* exePath) {
    size_t len = strlen(exePath);
    char* cfg = (char*)malloc(len + 5);
    if (!cfg) return NULL;
    strcpy(cfg, exePath);

    char* dot = strrchr(cfg, '.');
    if (dot && strcmp(dot, ".exe") == 0) {
        strcpy(dot, ".cfg");
    } else {
        strcat(cfg, ".cfg");
    }
    return cfg;
}

int main(int argc, char* argv[]){

    const char* paramsFile = NULL;
    int seed = -1; // -1 == use time();
    
    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-rnd") == 0) {
            if (i + 1 < argc) {
                seed = atoi(argv[++i]);
            } else {
                fprintf(stderr, "Klaida: -rnd reikalauja skaičiaus.\n");
                return 1;
            }
        } else {
            paramsFile = argv[i];
        }
    }

    // If no params file was given in the command line, use .cfg 
    char* cfgName = NULL;
    if (paramsFile == NULL) {
        cfgName = makeCfgName(argv[0]);
        if (!cfgName) {
            fprintf(stderr, "Klaida: nepavyko sudaryti konfigūracijos failo vardo.\n");
            return 1;
        }
        paramsFile = cfgName;
    }

    // Read parameters from file
    FILE* f = fopen(paramsFile, "r");
    if (!f) {
        fprintf(stderr, "Klaida: nepavyko atidaryti parametrų failo '%s'.\n", paramsFile);
        if (cfgName) free(cfgName);
        return 1;
    }

    GranaryParams p;
    char lineBuf[256];

    if (!fgets(lineBuf, sizeof(lineBuf), f) || sscanf(lineBuf, "%d", &p.dienos) != 1 ||
        !fgets(lineBuf, sizeof(lineBuf), f) || sscanf(lineBuf, "%d", &p.kiekioNorma) != 1 ||
        !fgets(lineBuf, sizeof(lineBuf), f) || sscanf(lineBuf, "%d", &p.kiekioNuokrypis) != 1 ||
        !fgets(lineBuf, sizeof(lineBuf), f) || sscanf(lineBuf, "%d", &p.kainosNorma) != 1 ||
        !fgets(lineBuf, sizeof(lineBuf), f) || sscanf(lineBuf, "%d", &p.kainosNuokrypis) != 1 ||
        !fgets(lineBuf, sizeof(lineBuf), f) || sscanf(lineBuf, "%d", &p.antkainis) != 1) {
        fprintf(stderr, "Klaida: parametrų failas '%s' yra netinkamo formato.\n", paramsFile);
        fclose(f);
        if (cfgName) free(cfgName);
        return 1;
    }
    fclose(f);
    if (cfgName) free(cfgName);

    // Determine the seed used
    if (seed == -1) {
        seed = (int)time(NULL);
    }

    GranaryResult simulationResult = simulateGranary(&p, seed);
    printGranarySimulationResults(&simulationResult);
    
    printf("\nPseudo-atsitiktinių skaičių daviklio (seed) reikšmė: %d\n", seed);

    return 0;
}