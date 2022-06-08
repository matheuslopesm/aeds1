#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"


//Trabalho Pr�tico 1 - AEDS I
//Nome: Lucas Nunes Silveira - 20.2.8040
//Nome: Matheus Lopes Moreira - 20.2.8002


void criar_conj_vazio(TConjunto *conj){
    conj->primeiro = NULL;
    conj->ultimo = NULL;
    conj->tam = 0;
}

void ler_conjunto(TConjunto *conj, int info){
    int verificador = 0;
    TNodo *pAux = conj->primeiro;
    while(pAux != NULL){
        if(pAux->info == info){
            verificador = -1;
            printf("\nEste numero ja pertence ao conjunto\n");
        }
        pAux = pAux->prox;
    }

    if(verificador == 0){
        if(conj->ultimo == NULL){
            conj->ultimo = (TNodo*) malloc(sizeof(TNodo));
            conj->primeiro = conj->ultimo;
        }else{
            conj->ultimo->prox = (TNodo*) malloc(sizeof(TNodo));
            conj->ultimo = conj->ultimo->prox;
        }
        conj->ultimo->info = info;
        conj->ultimo->prox = NULL;
        conj->tam++;
    }
}

void uniao_de_conjuntos(TConjunto *conj1, TConjunto *conj2, TConjunto *conj3){
    //mesma coisa quando usamos vetores, soq dessa vez nao sera for(for()) e sim while(while())
}

void intersec_de_conjuntos(TConjunto *conj1, TConjunto *conj2, TConjunto *conj3){

}

void verifica_igual(TConjunto *conj1, TConjunto *conj2){
    /*int verificador = 0;
    if(conj1->tam != conj2->tam){
        verificador = -1;
    }
    TNodo pAux1 = conj1->primeiro;
    TNodo pAux2 = conj2->primeiro;
    while(pAux1->prox != NULL){
        while(pAux2->prox != NULL){
            if(pAux1->info == pAux2->info){}
        }
    }
    if(verificador == 0){
        printf("Os conjuntos sao iguais");
    }else{
        printf("Os conjuntos sao diferentes");
    }*/
}

void imprime_conj(TConjunto* conj){
    TNodo *pAux;
    pAux = conj->primeiro;
    printf("\n[");
    while(pAux != NULL){
        printf(" %d -", pAux->info);
        pAux = pAux->prox;
    }
    printf("]\n");
}
