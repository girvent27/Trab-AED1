#include "src/func.h"

int main()
{
    int Menu = 0, ID;
    sNode *trens;
    char carga[50];
    double qtdCarga;
    trens = criaTrem(trens);
    // NodeStart -> menu() -> Adicionar de Trem -> criaTrem() -> menu()
    //   ||
    //   \/
    // menu() -> Adicionar Vagao -> Se nn tiver trem criado -> menu()
    //                           -> criaVagao()
    //   ||
    //   \/
    // menu() -> Organizar Vagao -> Qula o ID do Trem? -> ID vagao e nova posição

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
            if (!trensVazio(trens))
                printf("Nao ha trens criados");
            else
            {
                printf("Digite o ID do trem que deseja adicionar o vagão: ");
                scanf("%d", &ID);
                printf("Digite a carga do vagao: ");
                scanf("%49[^\n]", carga);
                adicionaVagao(trens, ID, structVagao(carga[50], qtdCarga));
            }

            break;
        case 5:
            break;
        case 6:
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