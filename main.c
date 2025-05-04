#include "func.h"

int main()
{
    int Menu = 0, ID;
    sNode *trens;

    trens = criaTrem();
    do
    {
        Menu = menu();
        printf("\n");

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
            mainExcluirVagao(trens);
            break;
        case 4:
            mainCriaVagao(trens);
            break;
        case 5:
            mainMudarCarga(trens);
            break;
        case 6:
            printf("Digite o ID do Trem: ");
            scanf("%d", &ID);
            if (!listaVagao(trens, ID))
                printf("Nao ha trem com este ID");
            break;
        case 7:
            mainReorganizaVagao(trens);

            break;
        case 8:
            mainExcluiVagao(trens);
            break;

        case 9:
            printf("Criando Testes");
            teste(&trens);
            break;
        default:
            break;
        }
        printf("\n");

    } while ((Menu >= 1 && Menu <= 9));
    if (Menu < 0 || Menu > 9)
    {
        printf("Erro: Numero invalido, tente novamente mais tarde...\n\n");
    }
}