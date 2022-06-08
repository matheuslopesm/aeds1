#include <stdio.h>
#include <stdlib.h>
#include "conj.h"

void criar_conj_vazio(Conjunto *conjA){
    conjA->ultimo = 0;
    for(int i=0; i<MAXTAM; i++){
        conjA->vet[i] = 0;
    }
}

void ler_conjunto(Conjunto *conj){
    int n, i=0,valor,verificador=0;
    printf("Quantos elementos deseja inserir? = ");
    scanf("%d", &n);
    do{
        printf("Digite o numero %d: ", i+1);
        scanf("%d",&valor);
        for(int j=0; j<conj->ultimo; j++){
            if(conj->vet[j] == valor){
                verificador = -1;
            }
        }
        if(verificador == -1){
            printf("\nEste elemento ja pertence ao conjunto! \n");
        }else{
            conj->vet[i] = valor;
            conj->ultimo++;
            i++;
        }
        verificador = 0;
    }while(i<n);
}

void uniao_de_conjuntos(Conjunto *conj1, Conjunto *conj2, Conjunto *conj3){
    int a=0, verificador = 0;
    for(int k=0; k<conj1->ultimo; k++){
        conj3->vet[k] = conj1->vet[k];
        conj3->ultimo++;
        a++;
    }
    for(int i=0; i<conj2->ultimo; i++){
        for(int j=0; j<conj1->ultimo; j++){
            if(conj2->vet[i] == conj1->vet[j]){
                verificador = -1;
            }
        }
        if(verificador != -1){
            conj3->vet[a] = conj2->vet[i];
            conj3->ultimo++;
            a++;
        }
        verificador = 0;
    }
}


void intersec_de_conjuntos(Conjunto *conj1, Conjunto *conj2, Conjunto *conj3){
    int k=0;
    ordena_vetor(&conj1);
    ordena_vetor(&conj2);
    for(int i=0; i<conj1->ultimo; i++){
        for(int j=0; j<conj2->ultimo; j++){
            if(conj1->vet[i] == conj2->vet[j]){
            conj3->vet[k] = conj1->vet[i];
            conj3->ultimo++;
            k++;
            }
        }
    }
}
void ordena_vetor(Conjunto *conj){
    int aux;
    for (int i = 0; i < conj->ultimo; i++){
        for (int j = 0; j < conj->ultimo; j++){
            if (conj->vet[i] < conj->vet[j]){
                aux = conj->vet[i];
                conj->vet[i] = conj->vet[j];
                conj->vet[j] = aux;
            }
        }
    }
}

void verifica_igual(Conjunto *conj1, Conjunto *conj2){
    int verificador = 0;
    ordena_vetor(&conj1);
    ordena_vetor(&conj2);
    if(conj1->ultimo != conj2->ultimo){
        verificador = -1;
    }
    for(int i=0; i<conj1->ultimo; i++){
        if(conj1->vet[i] != conj2->vet[i]){
            verificador = -1;
        }
    }
    if(verificador == -1){
        printf("Os conjuntos nao sao iguais");
    }else{
        printf("Os conjuntos sao iguais");
    }
}


void imprime_conj(Conjunto *conj){
    printf("//");
    for(int i=0; i<conj->ultimo; i++){
        printf(" %d", conj->vet[i]);
    }
    printf(" //");
}
