#include "src/func.h"
int maiorID(sNode **trens);

sNode *criaTrem(sNode *trem)
{
    return NULL;
}

int adicionaTrem(sNode **trens)
{
    sNode *novo;
    int maior;
    novo = (sNode *)malloc(sizeof(sNode));
    if (novo == NULL)
    {
        return 0;
    }
    novo->trem = NULL;
    if ((*trens) == NULL)
    {
        novo->next = NULL;
        novo->id = 1;
    }
    else
    {
        maior = maiorID(trens);
        novo->id = maior + 1;
        novo->next = (*trens);
    }
    (*trens) = novo;
    return 1;
}

int maiorID(sNode **trens)
{
    sNode *aux;
    int maior;
    maior = (*trens)->id;
    aux = (*trens);
    while (aux != NULL)
    {
        if (maior < aux->id)
        {
            maior = aux->id;
        }
        aux = aux->next;
    }
    return maior;
}

int trensVazio(sNode *trens)
{
    return (trens != NULL);
}

void listarTrens(sNode *trens)
{
    sNode *aux;
    aux = trens;
    while (aux != NULL)
    {
        printf("Id do trem: %d \n", aux->id);
        aux = aux->next;
    }
}

int removerTrem(sNode **trens, int id)
{
    sNode *aux;
    sNode *ant;
    int achou = 0;
    ant = NULL;
    aux = (*trens);
    while (aux != NULL)
    {
        if (id == aux->id)
        {
            achou = 1;
            break;
        }
        ant = aux;
        aux = aux->next;
    }
    if (achou == 0)
    {
        return achou;
    }
    if (aux == (*trens))
    {
        (*trens) = (*trens)->next;
    }
    else
    {
        ant->next = aux->next;
    }
    free(aux);
    return achou;
}