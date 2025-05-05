#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

// funções auxiliares
int menu();
Vagao structVagao(char *, double, char *);
void teste(sNode **);
void mainCriaVagao(sNode *);
void mainReorganizaVagao(sNode *);
void mainExcluiVagao(sNode *);
void mainMudarCarga(sNode *);
void mainExcluirVagao(sNode *);