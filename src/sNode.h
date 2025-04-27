// Node de criação de listas simples
struct sNode
{
    struct dNode *Trem;
    int id;
    struct sNode *next;
};
typedef struct sNode sNode;

int criaTrem(sNode **);
int adicionaTrem(sNode **);
int listarTrens(sNode **);
int buscarTrem(sNode **, int); // Retorna o endereço do Trem
int removerTrem(sNode **, int);