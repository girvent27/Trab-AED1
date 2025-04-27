#include "src/func.h"

void criaDNode(dNode **l)
{
    *l = NULL;
}

int maiorIdVagao(dNode **lista)
{
    int x = 0;
    dNode aux = lista;
    for (aux = lista; aux->next != NULL; aux = aux->next)
    {
        if (aux->id > x)
            x = aux->id;
    }
    return x;
}

sNode *buscaTrem(sNode **lista, int ID)
{
    sNode *aux = lista;
    for (aux = lista; aux->next != NULL; aux = aux->next)
    {
        if (aux->id == ID)
            return aux;
        else
            return NULL;
    }
}

int insereVagao(sNode *l, int ID, Vagao vagao)
{
    sNode *trem = buscaTrem(l, ID);
    if (trem == NULL)
    {
        dNode locomotiva = (dNode *)malloc(sizeof(dNode));
        locomotiva->id = 0;
        strcpy(locomotiva->vagao.carga, "LOCOMOTIVA");
        locomotiva->next = NULL;
        locomotiva->prev = NULL;
    }

    dNode vagoes = l->trem;

    dNode novo = (dNode *)malloc(sizeof(dNode));
    if (novo == NULL)
    {
        return 0;
    }

    novo->id = maiorIdVagao(&vagoes) + 1;

    if (l == NULL)
        novo->next = NULL;

    vagoes->prev = novo;
    novo->prev = NULL;
    novo->vagao = vagao;
    novo->next = l;

    l = novo;
    return 1;
}
