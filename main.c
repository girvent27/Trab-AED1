#include "src/func.h"

int main()
{
    int Menu = 0, ID;
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
            // sNode trens
            // criatrem(trens)
            break;
        case 2:
            // if (listarTrens(trens))
            //     listarTrens(trens);
            // else
            //     printf("Nao ha trens criados");
            break;
        case 3:
            // if (listarTrens(trens)){
            //     printf("digite o ID do trem: ");
            //     scanf("%d", ID);
            //     if (apagarTrem(trens, ID))
            //         printf("Trem excluido com Sucesso!");
            //     else
            //         printf("Erro ao excluir trem, tente novamente");
            // }
            // else
            //     printf("Nao ha trens criados");
            //     break;
        case 4:
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
        printf("\n");

    } while (Menu >= 0 && Menu <= 9);
    if (Menu < 0 || Menu > 9)
    {
        printf("Erro: Numero invalido, tente novamente mais tarde...\n");
    }
}