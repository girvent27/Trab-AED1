#include "src/func.h"

// Fazer funcao de excluir vcagao na de excluir tem parea nao ter memoria vazando
dNode *criaLocomotiva();
int maiorID(sNode **trens);

sNode *criaTrem()
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
    novo->trem = criaLocomotiva();
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

// Nos Duplamente encadeados

dNode *criaDNode()
{
    return NULL;
}
dNode *criaLocomotiva()
{
    dNode *locomotiva = (dNode *)malloc(sizeof(dNode));
    locomotiva->id = 0;
    locomotiva->next = NULL;
    locomotiva->prev = NULL;
    strcpy(locomotiva->vagao.carga, "LOCOMOTIVA");
    locomotiva->vagao.carga_size = 0;

    return locomotiva;
}

// Busca trem reorna o endereço do tem pela ID
sNode *buscaTrem(sNode *l, int ID)
{
    sNode *aux = l;
    while (aux != NULL)
    {
        if (aux->id == ID)
            return aux;
        else
            aux = aux->next;
    }
    return NULL;
}

int listaVagao(sNode *Trem, int ID)
{
    sNode *aux = buscaTrem(Trem, ID);
    if (aux == NULL)
        return 0;
    else
    {
        dNode *aux_t = aux->trem;
        printf("Cod.\tCarga\tQuantidade");
        while (aux_t != NULL)
        {
            printf("\n%d\t", aux_t->id);
            printf("%s\t", aux_t->vagao.carga);
            if (aux_t->id != 0)
                printf("%.3lf\t", aux_t->vagao.carga_size);

            aux_t = aux_t->next;
        }
    }

    return 1;
}

int maiorIdVagao(dNode *l)
{
    int maior = 0;
    dNode *aux = l;
    while (aux != NULL)
    {
        if (aux->id > maior)
            maior = aux->id;

        aux = aux->next;
    }
    return maior;
}

int insereVagao(sNode **Trem, int ID, Vagao vagao)
{
    sNode *aux = buscaTrem(*Trem, ID);
    if (aux == NULL)
        return 0;
    else
    {
        // crio o vagao
        dNode *novo = (dNode *)malloc(sizeof(dNode));

        // coloco a maior id + 1 no vagao
        novo->id = maiorIdVagao(aux->trem) + 1;
        // coloco vagao no vagao
        novo->vagao = vagao;
        // coloco que o no anterior eh a locomotiva
        novo->prev = NULL;
        // coloco que o vagao seguinte é o seguinte nó anterior
        novo->next = aux->trem;

        aux->trem->prev = novo;

        aux->trem = novo;
        return 1;
    }
}
int mudaCarga(sNode **Trem, int ID, int IdVag, Vagao vagao)
{
    sNode *aux = buscaTrem(*Trem, ID);
    if (aux == NULL)
        return 0;
    else
    {
        dNode *aux_t = aux->trem;
        while (aux_t != NULL)
        {
            if (aux_t->id == IdVag)
                aux_t->vagao = vagao;

            aux_t = aux_t->next;
        }
    }
    return 1;
}

int excluiVagao(sNode **Trem, int ID, int IdVag)
{
    sNode *aux = buscaTrem(*Trem, ID);
    if (aux == NULL)
        return 0;
    else
    {
        dNode *aux_t = aux->trem;
        while (aux_t != NULL)
        {
            if (aux_t->id == IdVag)
            {
                if (aux_t == aux->trem)
                    aux->trem = aux_t->next;
                else
                    aux_t->prev->next = aux_t->next;

                if (aux_t != NULL)
                    aux_t->next->prev = aux_t->prev;

                free(aux_t);
                return 1;
            }
            aux_t = aux_t->next;
        }
    }
    return 1;
}
