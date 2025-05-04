#include "func.h"

int menu()
{
    int Menu;
    printf("\n        ____      ____\n");
    printf(" |[_n_i_| (   ___/    |\n");
    printf("(__________|_[________]_\n");
    printf(" 0--0--0      00    00 \n");
    printf("+===============================+\n");
    printf("|    -=GERENCIADOR DE TRENS=-\t|\n");
    printf("+===============================+\n");
    printf("| [1] Adicionar Trem\t\t|\n");
    printf("| [2] Listar Trens\t\t|\n");
    printf("| [3] Excluir Trem\t\t|\n");
    printf("| [4] Adicionar Vagao\t\t|\n");
    printf("| [5] Mudar Carga de Vagao\t|\n");
    printf("| [6] Listar Vagoes\t\t|\n");
    printf("| [7] Reorganizar Vagao\t\t|\n");
    printf("| [8] Excluir Vagao\t\t|\n");
    printf("+===============================+\n");
    printf("| [0] Sair\t\t\t|\n");
    printf("+===============================+\nOpcao: ");
    scanf("%d", &Menu);
    return Menu;
}

Vagao structVagao(char *Carga, double QTD, char *Unidade)
{
    Vagao vagao;
    strcpy(vagao.carga, Carga);
    vagao.carga_size = QTD;
    strcpy(vagao.unidade, Unidade);

    return vagao;
}
void mainCriaVagao(sNode *trens)
{
    int ID, esc = 0, posicao;
    char carga[50], unidade[3];
    double qtdCarga;

    if (!trensVazio(trens))
        printf("Nao ha trens criados");
    else
    {
        printf("Digite o ID do trem: ");
        scanf("%d", &ID);
        printf("Digite a Carga: ");
        scanf(" %45[^\n]", carga);
        printf("Digite a Quantidade: ");
        scanf("%lf", &qtdCarga);
        printf("Qual a medida {[1] - Unidade | [2] Kilograma}\n(Padrao [1]): ");
        scanf("%d", &esc);
        switch (esc)
        {
        case 1:
            strcpy(unidade, "un");
            break;
        case 2:
            strcpy(unidade, "kg");
            break;

        default:
            strcpy(unidade, "un");
            break;
        }
        do
        {
            printf("Qual Posicao: [0] - Inicio, [%d] - Final: ", buscaTrem(trens, ID)->vagoes);
            scanf("%d", &posicao);
        } while (posicao > buscaTrem(trens, ID)->vagoes || posicao < 0);

        if (!insereVagao(&trens, ID, structVagao(carga, qtdCarga, unidade), posicao))
            printf("erro");
    }
}
void mainReorganizaVagao(sNode *trens)
{
    int ID = 0, posicao, IdVag;
    if (!trensVazio(trens))
        printf("Nao ha trem com este ID");
    else
    {
        printf("Digite o ID do Trem: ");
        scanf("%d", &ID);
        if (!listaVagao(trens, ID))
            printf("Nao ha trem com este ID");
        do
        {
            if (IdVag == 0)
                printf("Locomotiva nao pode ser alterada\n");
            if (IdVag > maiorIdVagao((buscaTrem(trens, ID)->trem)))
                printf("ID invalido\n");
            printf("\nDigite o ID do vagao: ");
            scanf("%d", &IdVag);

        } while (IdVag < 1 || IdVag > maiorIdVagao((buscaTrem(trens, ID)->trem)));
        do
        {
            printf("Qual Posicao: [0] - Inicio, [%d] - Final: ", buscaTrem(trens, ID)->vagoes - 1);
            scanf("%d", &posicao);
        } while (posicao > buscaTrem(trens, ID)->vagoes - 1 || posicao < 0);
        if (!organizarVagao(&trens, ID, IdVag, posicao))
            printf("erro");
    }
}
void mainExcluiVagao(sNode *trens)
{
    int ID, IdVag;
    if (!trensVazio(trens))
        printf("Nao ha trens criados.");
    else
    {
        printf("Digite o ID do Trem: ");
        scanf("%d", &ID);
        if (!listaVagao(trens, ID))
            printf("Nao ha trem com este ID");
        else
        {
            if (buscaTrem(trens, ID)->vagoes == 0)
                printf("\n\nNao ha vagoes neste trem\n");
            else
            {
                IdVag = 0;
                do
                {
                    printf("\nDigite o ID do vagao: ");
                    scanf("%d", &IdVag);
                } while (IdVag < 1);
                if (!excluiVagao(&trens, ID, IdVag))
                    printf("erro");
            }
        }
    }
}
void mainMudarCarga(sNode *trens)
{
    int ID, IdVag, esc = 0;
    char carga[50], unidade[3];
    double qtdCarga;
    if (!trensVazio(trens))
        printf("Nao ha trens criados");
    else
    {
        printf("Digite o ID do Trem: ");
        scanf("%d", &ID);
        if (!listaVagao(trens, ID))
            printf("Nao ha trem com este ID");
        if (buscaTrem(trens, ID)->vagoes == 0)
            printf("\n\nNao ha vagoes\n");
        else
        {
            printf("\nDigite o ID do vagao: ");
            scanf("%d", &IdVag);
            while (IdVag == 0)
            {
                printf("Locomotiva nao pode ser alterada\nDigite o ID do vagao: ");
                scanf("%d", &IdVag);
            }
            printf("Digite a Carga: ");
            scanf(" %45[^\n]", carga);
            printf("Digite a Quantidade: ");
            scanf("%lf", &qtdCarga);
            printf("Qual a medida {[1] - Unidade | [2] Kilograma}\n(Padrao [1]): ");
            scanf("%d", &esc);
            switch (esc)
            {
            case 1:
                strcpy(unidade, "un");
                break;
            case 2:
                strcpy(unidade, "kg");
                break;

            default:
                strcpy(unidade, "un");
                break;
            }
            if (!mudaCarga(&trens, ID, IdVag, structVagao(carga, qtdCarga, unidade)))
                printf("erro");
        }
    }
}
void mainExcluirVagao(sNode *trens)
{
    int ID;
    if (trensVazio(trens))
    {
        printf("digite o ID do trem: ");
        scanf("%d", &ID);
        if (removerTrem(&trens, ID))
            printf("Trem excluido com Sucesso!");
        else
            printf("Erro ao excluir trem, tente novamente");
    }
    else
        printf("Nao ha trens criados");
}
void teste(sNode **trem)
{
    adicionaTrem(trem);
    adicionaTrem(trem);
    adicionaTrem(trem);
    adicionaTrem(trem);
    insereVagao(trem, 1, structVagao("Carvao", 80, "kg"), 0);
    insereVagao(trem, 1, structVagao("Frutas", 12, "kg"), 0);
    insereVagao(trem, 1, structVagao("Madeira", 25, "un"), 0);
    insereVagao(trem, 1, structVagao("Circo", 1, "un"), 0);
    insereVagao(trem, 1, structVagao("Macaco", 5, "un"), 0);
    insereVagao(trem, 2, structVagao("Je", 12, "kg"), 0);
    insereVagao(trem, 2, structVagao("an", 12, "kg"), 0);
    insereVagao(trem, 2, structVagao("Lu", 12, "kg"), 0);
    insereVagao(trem, 2, structVagao("cG", 12, "kg"), 0);
    insereVagao(trem, 2, structVagao("ir", 12, "un"), 0);
    insereVagao(trem, 2, structVagao("ve", 12, "kg"), 0);
    insereVagao(trem, 2, structVagao("nt", 12, "un"), 0);
    insereVagao(trem, 3, structVagao("Ana", 4, "kg"), 0);
    insereVagao(trem, 3, structVagao("Luiza", 9, "un"), 0);
    insereVagao(trem, 4, structVagao("Mat", 4, "kg"), 0);
    insereVagao(trem, 4, structVagao("heus", 3, "un"), 0);
    insereVagao(trem, 4, structVagao("Res", 994, "kg"), 0);
    insereVagao(trem, 4, structVagao("ende", 0, "kg"), 0);
}