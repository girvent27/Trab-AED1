// Node de criação de listas simples
struct sNode
{
    struct dNode *trem;
    int id;
    struct sNode *next;
};
typedef struct sNode sNode;

sNode *criaTrem(sNode *trens);
int adicionaTrem(sNode **trens);
void listarTrens(sNode *trens);
int removerTrem(sNode **trens, int id);
int trensVazio(sNode *trens);
