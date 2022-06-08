#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"


//Trabalho Pr�tico 1 - AEDS I
//Nome: Lucas Nunes Silveira - 20.2.8040
//Nome: Matheus Lopes Moreira - 20.2.8002

int main()
{
    printf("Hello world!\n");

    TConjunto a;
    criar_conj_vazio(&a);
    int num, cond=0, op;

    do{
        printf("\nMenu:\n1 = inserir no conjunto\n2 = imprime conjunto\n3 = Sair \n- ");
        scanf("%d", &op);
        switch(op){
            case 1:
            printf("Digite o numero que deseja inserir: ");
            scanf("%d", &num);
            ler_conjunto(&a, num);
                break;
            case 2:
                imprime_conj(&a);
                break;
            case 3:
                cond = -1;
                break;
            default:
                printf("Opcao invalida! tente novamente");
        }
    }while(cond != -1);
    return 0;
}
