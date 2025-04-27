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

sNode *buscaTrem(sNode *lista, int ID)
{
    sNode *aux = lista;
    while (aux != NULL)
    {
        printf("Id do trem: %d \n", aux->id);
        aux = aux->next;
        if (aux->id == ID)
            return aux;
    }
    return NULL;
}

dNode *criaLocomotiva()
{

    dNode locomotiva = (dNode *)malloc(sizeof(dNode));
    locomotiva->id = 0;
    strcpy(locomotiva->vagao.carga, "LOCOMOTIVA");
    locomotiva->vagao.carga_size = 0;
    locomotiva->next = NULL;
    locomotiva->prev = NULL;

    return locomotiva;
}

int adicionaVagao(sNode *l, int ID, Vagao vagao)
{
    sNode *Trem = buscaTrem(l, ID);

    dNode novo = (dNode *)malloc(sizeof(dNode));
    if (novo == NULL)
    {
        return 0;
    }

    novo->id = maiorIdVagao(Trem) + 1;
    novo->prev = Trem->trem;
    novo->next = Trem->trem->next;
    novo->vagao = vagao;

    if (Trem->trem->next == NULL)
        novo->next = NULL;

    Trem->trem->next = novo;
    return 1;
}

void listarVagao(sNode *l, int ID, Vagao vagao)
{
    sNode *Trem = buscaTrem(l, ID);
    for (dNode aux = Trem; aux->next != NULL; aux = aux->next)
    {
        printf("Id do Vagao: %d\n", Trem->trem->id);
    }
}
