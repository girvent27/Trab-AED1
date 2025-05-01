#include "src/func.h"

int main()
{
    int Menu = 0, ID, IdVag, esc = 0, posicao;
    sNode *trens;
    char carga[50], unidade[3];
    double qtdCarga;
    trens = criaTrem();
    do
    {
        Menu = menu();
        printf("\n");
        // printf("\e[1;1H\e[2J");
        switch (Menu)
        {
        case 1:
            adicionaTrem(&trens);
            break;
        case 2:
            if (trensVazio(trens))
                listarTrens(trens);
            else
                printf("Nao ha trens criados");
            break;
        case 3:
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
            break;
        case 4:
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

            break;
        case 5:
            printf("Digite o ID do Trem: ");
            scanf("%d", &ID);
            if (!listaVagao(trens, ID))
                printf("Nao ha trem com este ID");

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
            break;
        case 6:
            printf("Digite o ID do Trem: ");
            scanf("%d", &ID);
            if (!listaVagao(trens, ID))
                printf("Nao ha trem com este ID");
            break;
        case 7:
            printf("Digite o ID do Trem: ");
            scanf("%d", &ID);
            if (!listaVagao(trens, ID))
                printf("Nao ha trem com este ID");

            printf("\nDigite o ID do vagao: ");
            scanf("%d", &IdVag);
            do
            {
                printf("Qual Posicao: [0] - Inicio, [%d] - Final: ", buscaTrem(trens, ID)->vagoes - 1);
                scanf("%d", &posicao);
            } while (posicao > buscaTrem(trens, ID)->vagoes - 1 || posicao < 0);
            if (!organizarVagao(&trens, ID, IdVag, posicao))
                printf("erro");

            break;
        case 8:
            printf("Digite o ID do Trem: ");
            scanf("%d", &ID);
            if (!listaVagao(trens, ID))
                printf("Nao ha trem com este ID");
            else
            {
                printf("\nDigite o ID do vagao: ");
                scanf("%d", &IdVag);
                while (IdVag == 0)
                {
                    printf("Locomotiva nao pode ser alterada\nDigite o ID do vagao: ");
                    scanf("%d", &IdVag);
                }

                if (!excluiVagao(&trens, ID, IdVag))
                    printf("erro");
            }
            break;

        default:

            break;
        }
        Sleep(1000);

        printf("\n");

    } while (Menu >= 1 && Menu <= 9);
    if (Menu < 0 || Menu > 9)
    {
        printf("Erro: Numero invalido, tente novamente mais tarde...\n");
    }
}