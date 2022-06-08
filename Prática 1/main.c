#include <stdio.h>
#include <stdlib.h>
#include "conj.h"

//Trabalho Pr�tico 1 - AEDS I
//Nome: Lucas Nunes Silveira - 20.2.8040
//Nome: Matheus Lopes Moreira - 20.2.8002

int main()
{
    printf("\nHello world!\n\n");

    Conjunto a, b, c, d;

    criar_conj_vazio(&a);
    criar_conj_vazio(&b);
    criar_conj_vazio(&c);
    criar_conj_vazio(&d);

    printf("Dados do conjunto A: \n");
    ler_conjunto(&a);
    printf("\nDados do conjunto B: \n");
    ler_conjunto(&b);

    printf("\n--- Conjunto A: ");
    imprime_conj(&a);
    printf("\n\n--- Conjunto B: ");
    imprime_conj(&b);

    printf("\n\nVerificacao de Igualdade (A e B): ");
    verifica_igual(&a, &b);

    uniao_de_conjuntos(&a, &b, &d);
    printf("\n\n--- Uniao: ");
    imprime_conj(&d);

    intersec_de_conjuntos(&a, &b, &c);
    printf("\n\n--- Interseccao: ");
    imprime_conj(&c);
    printf("\n\n");
    return 0;
}
