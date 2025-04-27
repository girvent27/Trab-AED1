#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sNode.h"
#include "dNode.h"

// // if(!strcomp( wagon.id, "Locomotive" ))
// // Wagon pode ser uma locomotiva
typedef struct TrainCar
{
    char carga[50];
    double carga_size;
} Vagao;

struct dNode
{
    Vagao vagao;
    int id;
    struct dNode *next;
    struct dNode *prev;
};
typedef struct dNode *dNode;

// Node de criação de listas simples
struct sNode
{
    struct dNode *Trem;
    int id;
    struct sNode *next;
};
typedef struct sNode *sNode;

int menu();
