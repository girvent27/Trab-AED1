typedef struct TrainCar
{
    char carga[50];
    double carga_size;
} Vagao;

struct dNode
{
    Vagao vagao;
    int id;
    struct dNode *next;
    struct dNode *prev;
};
typedef struct dNode *dNode;

int criaVagao(dNode **);
int adicionaVagao(dNode **, int, Vagao);
int listarVagoes(dNode **);
int buscarVagao(dNode **, int);
int removerVagao(dNode **, int);