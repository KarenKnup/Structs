/*Suponha a existência de um vetor de tamanho
TAM, cada posição armazenando o nome da
pessoa e a sua data de aniversário
(representada por um struct do tipo TData,
contendo os campos dia e mes). Pede-se o
desenvolvimento das seguintes funções:

 Determinar a quantidade de pessoas que
fazem aniversário no mês M;

 Exibir os nomes de todas pessoas que fazem
aniversário entre as datas d1 e d2, ambas
do tipo TData.
  */

#include <stdio.h>
#include <string.h>

//Quantas pessoas (TAM):
#define TAM 3

#define TRUE 1
#define FALSE 0
  
typedef struct {
  int dia, mes;
} TData;

typedef struct {
char nome[30];
TData dataAniv;
} TPessoa;

void preenche (TPessoa pessoa[]){
  int i;

  for(i=0; i<TAM; i++){
    printf("\nNome: ");
    scanf(" %[^\n]",pessoa[i].nome);
    printf("Dia de aniversário: ");
    scanf("%d",&pessoa[i].dataAniv.dia);
    printf("Mês de aniversário: ");
    scanf("%d",&pessoa[i].dataAniv.mes);
    printf("\n");
    
  }
}

int quantAniversariantes (TPessoa vetor[], int quant, int m){
  int i, cont=0;

  for (i=0; i<quant; i++){
    if (vetor[i].dataAniv.mes==m){
      cont++;
    }
  }
  return cont;
}

int verificarIntervalo (TData data, TData inf, TData sup){
  //--FALSE--10/6---TRUE---30/10--FALSE--
  if ((data.mes>inf.mes) && (data.mes<sup.mes)){
    return TRUE;
  }

  if ((data.mes==inf.mes) && (data.dia>=inf.dia)){
    return TRUE;
  }

  if ((data.mes==sup.mes) && (data.dia<=sup.dia)){
    return TRUE;
  }

  return FALSE;
}

void exibirAniversariantes (TPessoa vetor[], int quant, TData d1, TData d2){
  int i, cont=0;

  for (i=0; i<quant; i++){
    if (verificarIntervalo (vetor[i].dataAniv,d1,d2)==TRUE){
      printf("%s\n",vetor[i].nome);
      cont++; //contador de aniversariantes nesse intervalo
    }
  }

  if(cont==0){
    printf("Nenhum aniversariante nesse intervalo!");
  }
}


int main(void) {
  TPessoa pessoa[TAM];
  int quant=TAM;
  TData d1={2,6};
  TData d2={2,8};

  preenche(pessoa);

  printf("\n\tQuantidade de aniversariantes em Junho (mês 6): %d",quantAniversariantes(pessoa,quant,6));

  printf("\n\n\tAniversariantes entre 2/6 e 2/8: \n");
  exibirAniversariantes(pessoa,quant,d1, d2);
  
    return 0;
}