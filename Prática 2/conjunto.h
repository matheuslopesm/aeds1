
//Trabalho Pr�tico 1 - AEDS I
//Nome: Lucas Nunes Silveira - 20.2.8040
//Nome: Matheus Lopes Moreira - 20.2.8002


typedef struct Nodo{
    int info;
    struct Nodo *prox;
}TNodo;

typedef struct {
    TNodo *primeiro;
    TNodo *ultimo;
    int tam;
}TConjunto;

void criar_conj_vazio(TConjunto *conj);

void ler_conjunto(TConjunto *conj, int info);

void uniao_de_conjuntos(TConjunto *conj1, TConjunto *conj2, TConjunto *conj3);

void intersec_de_conjuntos(TConjunto *conj1, TConjunto *conj2, TConjunto *conj3);

void verifica_igual(TConjunto *conj1, TConjunto *conj2);

void imprime_conj(TConjunto *conj);
