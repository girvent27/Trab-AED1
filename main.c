#include "src/func.h"

int main()
{
    int Menu = 0, ID, IdVag;
    sNode *trens;
    char carga[50];
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
            if (!insereVagao(&trens, ID, structVagao(carga, qtdCarga)))
                printf("erro");

            break;
        case 5:
            printf("Digite o ID do Trem: ");
            scanf("%d", &ID);
            if (!listaVagao(trens, ID))
                printf("Nao há trem com este ID");
            printf("\nDigite o ID do vagao: ");
            scanf("%d", &IdVag);
            printf("Digite a Carga: ");
            scanf(" %45[^\n]", carga);
            printf("Digite a Quantidade: ");
            scanf("%lf", &qtdCarga);
            if (!mudaCarga(&trens, ID, IdVag, structVagao(carga, qtdCarga)))
                printf("erro");
            break;
        case 6:
            printf("Digite o ID do Trem: ");
            scanf("%d", &ID);
            if (!listaVagao(trens, ID))
                printf("Nao há trem com este ID");
            break;
        case 7:
            break;
        case 8:

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