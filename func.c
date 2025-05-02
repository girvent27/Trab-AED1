#include "src/func.h"

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

void teste(sNode **trem)
{
    adicionaTrem(trem);
    adicionaTrem(trem);
    insereVagao(trem, 1, structVagao("Carvao", 80, "kg"), 0);
    insereVagao(trem, 1, structVagao("Frutas", 12, "kg"), 0);
    insereVagao(trem, 1, structVagao("Madeira", 25, "un"), 0);
    insereVagao(trem, 1, structVagao("Circo", 1, "un"), 0);
    insereVagao(trem, 1, structVagao("ij", 12, "kg"), 0);
    insereVagao(trem, 2, structVagao("je", 12, "kg"), 0);
    insereVagao(trem, 2, structVagao("an", 12, "kg"), 0);
    insereVagao(trem, 2, structVagao("lu", 12, "kg"), 0);
    insereVagao(trem, 2, structVagao("cg", 12, "kg"), 0);
    insereVagao(trem, 2, structVagao("ir", 12, "kg"), 0);
}
