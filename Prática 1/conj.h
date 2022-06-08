#define MAXTAM 100

typedef struct{
    int vet[MAXTAM];
    int ultimo;
}Conjunto;

void criar_conj_vazio(Conjunto *conj);

void ler_conjunto(Conjunto *conj);

void uniao_de_conjuntos(Conjunto *conj1, Conjunto *conj2, Conjunto *conj3);

void intersec_de_conjuntos(Conjunto *conj1, Conjunto *conj2, Conjunto *conj3);

void verifica_igual(Conjunto *conj1, Conjunto *conj2);

void ordena_vetor(Conjunto *conj);

void imprime_conj(Conjunto *conj);


