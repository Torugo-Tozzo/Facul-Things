#pragma

#define true 1
#define false 0

//typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux {
    TIPOCHAVE chave;
    struct aux *esq;
    struct aux *dir;
    int bal; // fator de balanceamento (0, -1 ou +1) => alt. direita - alt. esquerda
} NO, *PONT;

/* Cria um novo (aloca memoria e preenche valores) no com chave=ch e retorna 
   seu endereco. */
PONT criarNovoNo(TIPOCHAVE ch){
    //PONT novoNo = (PONT)malloc(sizeof(NO));
    NO *novoNo = new(NO);
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    novoNo->bal = 0;
    return novoNo;
}

int max(int a, int b);
int altura(PONT p);
void exibirArvoreEmOrdem(PONT raiz);
void exibirArvorePreOrdem(PONT raiz);
void exibirArvorePosOrdem(PONT raiz);
void exibirArvore(PONT raiz);
void exibirArvore2(PONT raiz, TIPOCHAVE chavePai);
bool ehAVL(PONT p);
bool ehAVL2(PONT p, int* alt);
int atualizarBalanceamentoTotal(PONT raiz);
PONT rotacaoL(PONT p);
PONT rotacaoR(PONT p);
void inserirAVL(PONT* pp, TIPOCHAVE ch, bool* alterou);
PONT buscaBinaria(TIPOCHAVE ch, PONT raiz);
PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai);
PONT maiorAEsquerda(PONT p, PONT *ant);
bool excluirAVL(PONT* raiz, TIPOCHAVE ch, bool* alterou);
void rotacaoL2(PONT *p);
void rotacaoR2(PONT *p);
void inserirAVL2(PONT *pp, TIPOCHAVE ch, bool *alterou);
void destruirAux(PONT subRaiz);
void destruirArvore(PONT * raiz);
void inicializar(PONT * raiz);
void travessiaAux(PONT p, int *niv, TIPOCHAVE ch, bool *achou);
bool travessia(PONT p, int *niv, TIPOCHAVE ch);
void mostraArvore(NO* node, int level);