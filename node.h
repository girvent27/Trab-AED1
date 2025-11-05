// Node de listas simples
struct sNode
{
    struct dNode *trem; // Lista de Vagoes
    int id;             // Identificacao
    int vagoes;         // Numero de Vagoes
    double un, kg;      // Pesso e quantidades total
    struct sNode *next; // No do proximo
};
typedef struct sNode sNode;
// Struc dos vagões
typedef struct TrainCar
{
    char carga[50];
    double carga_size;
    char unidade[3];
} Vagao;
// Node de listas duplamente encadeadas
struct dNode
{
    Vagao vagao;
    int id;
    struct dNode *next;
    struct dNode *prev;
};
typedef struct dNode dNode;

// Funções de No Simplesmente Encadeado
sNode *criaTrem();
int adicionaTrem(sNode **trens);
void listarTrens(sNode *trens);
int removerTrem(sNode **trens, int id);
int trensVazio(sNode *trens);

// Funções de No Duplamente Encadeado
dNode *criaLocomotiva();
int listaVagao(sNode *, int);
int maiorIdVagao(dNode *l);
int insereVagao(sNode **, int, Vagao, int);
sNode *buscaTrem(sNode *, int);
int mudaCarga(sNode **Trem, int ID, int IdVag, Vagao vagao);
int excluiVagao(sNode **Trem, int ID, int IdVag);
int organizarVagao(sNode **Trem, int ID, int IdVag, int posi_nova);