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
    novo->vagoes = 0;
    novo->kg = novo->un = 0;
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
    printf("|ID\t|Vagoes\t|Ttl Kg\t|Ttl Un\n");
    while (aux != NULL)
    {
        printf("|%d\t|%d\t|%.3lf\t|%.0lf\n", aux->id, aux->vagoes, aux->kg, aux->un);
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
        int i = 1;
        dNode *aux_t = aux->trem;
        printf("Posic.\t|Id\t|Carga\t|Quantidade");
        while (aux_t != NULL)
        {
            printf("\n%d    |\t", i);
            printf("|%d\t", aux_t->id);
            printf("|%s\t", aux_t->vagao.carga);
            if (aux_t->id != 0)
                printf("|%.3lf\t", aux_t->vagao.carga_size);
            printf("|");
            aux_t = aux_t->next;
            i++;
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

// FAZER PARA QUALQUER POSICAO MENOS LOCOMOTIVA
int insereVagao(sNode **Trem, int ID, Vagao vagao, int posicao)
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
        // para aumentar valores de totais
        if (!strcmp(vagao.unidade, "kg"))
            aux->kg += vagao.carga_size;
        else
            aux->un += vagao.carga_size;

        // Insercao posicional ou no inicio
        if (posicao == 0) // insercao no inicio
        {
            // coloco que o no anterior eh NULL
            novo->prev = NULL;
            // coloco que o vagao seguinte é o primeiro nó anterior
            novo->next = aux->trem;
            // coloco que o anterior do primeiro agora eh o novo
            aux->trem->prev = novo;
            // cabeca da lista eh o novo
            aux->trem = novo;
        }
        else // insercao posicional
        {
            dNode *aux_t = aux->trem;

            for (int i = 0; i < posicao - 1; i++)
                aux_t = aux_t->next;

            // pega os anteriores e proximos da posicao atual
            novo->next = aux_t->next;
            novo->prev = aux_t->prev;

            aux_t->next = aux_t->next->prev = novo;
        }

        aux->vagoes++;
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
            {
                if (!strcmp(aux_t->vagao.unidade, "kg"))
                    aux->kg -= aux_t->vagao.carga_size;
                else
                    aux->un -= aux_t->vagao.carga_size;
                aux_t->vagao = vagao;

                // coloca mais carga no totalizador do no
                if (!strcmp(vagao.unidade, "kg"))
                    aux->kg += vagao.carga_size;
                else
                    aux->un += vagao.carga_size;
            }

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

                if (!strcmp(aux_t->vagao.unidade, "kg"))
                    aux->kg -= aux_t->vagao.carga_size;
                else
                    aux->un -= aux_t->vagao.carga_size;

                free(aux_t);
                aux->vagoes--;
                return 1;
            }
            aux_t = aux_t->next;
        }
    }
    return 1;
}

int organizarVagao(sNode **Trem, int ID, int posi_atual, int posi_nova)
{
    sNode *aux = buscaTrem(*Trem, ID);
    // excluiVagao(posiataual)
    // insereVagao(vagao, posinova)
}