// Node de criação de listas simples
struct sNode
{
    struct dNode *trem;
    int id;
    int vagoes;
    double un, kg;
    struct sNode *next;
};
typedef struct sNode sNode;

typedef struct TrainCar
{
    char carga[50];
    double carga_size;
    char unidade[3];
} Vagao;

struct dNode
{
    Vagao vagao;
    int id;
    struct dNode *next;
    struct dNode *prev;
};
typedef struct dNode dNode;

// No simplesmente encadeado
sNode *criaTrem();
int adicionaTrem(sNode **trens);
void listarTrens(sNode *trens);
int removerTrem(sNode **trens, int id);
int trensVazio(sNode *trens);

// No duplamente encadeado
dNode *criaLocomotiva();
int listaVagao(sNode *, int);
int insereVagao(sNode **, int, Vagao, int);
sNode *buscaTrem(sNode *, int);
int mudaCarga(sNode **Trem, int ID, int IdVag, Vagao vagao);
int excluiVagao(sNode **Trem, int ID, int IdVag);
int organizarVagao(sNode **Trem, int ID, int IdVag, int posi_nova);