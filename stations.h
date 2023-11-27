//
// Created by pauld on 26/11/2023.
//

#ifndef PROJET_STATIONS_H
#define PROJET_STATIONS_H

struct Operation
{
    int num;
};

typedef struct Operation* pOperation;

typedef struct Station
{
    int num;
    pOperation *operation;

} Station;

typedef struct Station* pStation;

typedef struct Usine
{
    pStation *pStation;

} Usine;
#endif //PROJET_STATIONS_H
