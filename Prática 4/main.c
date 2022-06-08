#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Matheus Lopes Moreira - 20.2.8002
// Lucas Nunes Silveira - 20.2.8040

#define MAXTAM 100

typedef struct {
    char Nome[MAXTAM];
}Tpaciente;

typedef struct{
    Tpaciente Vpaciente[MAXTAM+1];
    int frente, tras, tam, qtdPaciente;
}TFila;

typedef struct{
    char chave[MAXTAM];
}TRegistro;

typedef struct{
    TRegistro item[MAXTAM+1];
    int n;
}TTabela;

int Enfileira(TFila* pFila, Tpaciente* Vpaciente);
int desenfileira(TFila* pFila, Tpaciente* Vpaciente);
void criaFilaVazia(TFila *pFila);
int FVazia(TFila* pFila);
void imprimeRelatorio(TFila *pFila);
void inicializa(TTabela *T);
int pesquisa_seq(TTabela *T, char nome[MAXTAM]);
void insere(TRegistro reg, TTabela *T);

//======================================//
int main(){

    int qtd_vacina = 0, qtdPaciente = 0, num;
    int opcao;
    char search_name[MAXTAM];
    TFila filaVacinacao;
    criaFilaVazia(&filaVacinacao);
    TTabela Tabela;
    inicializa(&Tabela);

    printf("******* Programa Nacional de Imunizacao *******");
    printf("\n\nDigite a quantidade de Vacinas Disponiveis = ");
    scanf("%d", &qtd_vacina);
   do{
        printf("\n== Menu ==\n\n");
        printf("[1] - Adicionar Pacientes\n");
        printf("[2] - Consultar numero de Vacinas\n");
        printf("[3] - Conferir quantidade de pacientes\n");
        printf("[4] - Atualizar estoque de Vacinas\n");
        printf("[5] - Pesquisar paciente cadastrado\n");
        printf("[0] - Sair\n= ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
            if((qtd_vacina != 0)){
                Tpaciente paciente;
                TRegistro reg;
                printf("------- Dados do Paciente --------\n");
                fflush(stdin);
                printf("\n* Nome: ");
                getchar();
                gets(paciente.Nome);

                Enfileira(&filaVacinacao, &paciente);
                strcpy(reg.chave, paciente.Nome);
                strcspn(reg.chave, "\n");
                insere(reg, &Tabela);

                qtd_vacina--;
                qtdPaciente++;
                printf("\n* Paciente cadastrado com sucesso!!\n");
            }else{
                printf("\n!!! O estoque de vacinas esta vazio. Nao foi possivel inserir paciente !!!\n");
            }
            break;

            case 2:
            printf("\n* Vacinas disponiveis: %d\n\n", qtd_vacina);
            break;

            case 3:
            printf("\n* Pacientes cadastrados: %d\n\n", qtdPaciente);
            break;

            case 4:
                printf("\nEstoque atual: [ %i ] ", qtd_vacina);
                printf("\nDigite a quantidade de vacinas que deseja inserir no estoque: ");
                scanf("%d", &num);
                qtd_vacina += num;
                num = 0;
            break;

            case 5:
                printf("\nDigite o nome do paciente que você quer pesquisar:\n");
                getchar();
                fflush(stdin);
                gets(search_name);
                int n = pesquisa_seq(&Tabela, search_name);
                if(n == 0){
                    printf("\n!! O Paciente | %s | não consta na base de dados !!\n", search_name);
                }else{
                    printf("\n!! O Paciente %s esta cadastrado !!\n* Trata-se do paciente [%i]\n", search_name, n);
                }
            break;
            case 0:
                printf("\n\n=== Pacientes cadastrados no sistema: ===");
                imprimeRelatorio(&filaVacinacao);

            break;
        }
    }while(opcao != 0);

    printf("// Dados Gerais //\n\n");
    printf("* Quantidade total de pacientes vacinados = %i", qtdPaciente);
    printf("\n\n* Quantidade de Vacinas restantes = %i", qtd_vacina);
    printf("\n\n");

}

//======================================//

void criaFilaVazia(TFila *pFila){
    pFila->frente = 0;
    pFila->tras = pFila->frente;
}
int FVazia(TFila* pFila){
    return(pFila->frente == pFila->tras);
}

//======================================//

int Enfileira(TFila* pFila, Tpaciente* Vpaciente){
    // int qtdPaciente;
    if(((pFila->tras + 1) % (MAXTAM + 1)) == pFila->frente){
        return 0;
    }
    pFila->Vpaciente[pFila->tras] = *Vpaciente;
    pFila->tras = (pFila->tras+1) % (MAXTAM + 1);
    return 1;
}

//======================================//

int desenfileira(TFila* pFila, Tpaciente* Vpaciente){
    if(FVazia(pFila)){
        return 0;
    }
    *Vpaciente = pFila->Vpaciente[pFila->frente];
    pFila->frente = (pFila->frente + 1) % (MAXTAM + 1);
    return 1;
}

//======================================//

void imprimeRelatorio(TFila *pFila){
    int qtdPaciente=0, qtd_vacina=0;
    printf("\n\n");

    for(int i=pFila->frente; i < pFila->tras; i++){
        printf("=== Paciente [%i]", i+1);
        printf("\n* Nome: %s", pFila->Vpaciente[i].Nome);
        printf("\n====================================//\n\n");
    }
}

//======================================//

void inicializa(TTabela *T){
    T->n = 0;
}

//======================================//

int pesquisa_seq(TTabela *T, char nome[MAXTAM]){
    int i;
    strcpy(T->item[0].chave, nome);
    i = T->n;
    while(strcmp(T->item[i].chave, nome) != 0){
        i--;
    }
    return i;
}

//======================================//

void insere(TRegistro reg, TTabela *T){
    if(T->n == MAXTAM){
        printf("\n!! Tabela Cheia !!\n");
    } else{
        T->n++;
        T->item[T->n] = reg;
    }
}

//======================================//