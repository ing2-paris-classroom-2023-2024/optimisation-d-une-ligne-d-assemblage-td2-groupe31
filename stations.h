//
// Created by pauld on 26/11/2023.
//

#ifndef PROJET_STATIONS_H
#define PROJET_STATIONS_H

struct Operation
{
    int num;
    struct Operation *operation_suvante;
};

typedef struct Operation* pOperation;

typedef struct Station
{
    int num;
    struct Operation *operation;
    struct Station * station_suivant;

} Station;

typedef struct Station * pStation;

typedef struct Usine
{
    struct Station *station;

} Usine;
#endif //PROJET_STATIONS_H
