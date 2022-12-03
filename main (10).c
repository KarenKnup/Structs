/*
Considere a existência de um vetor V1 de inteiros, contendo quant elementos. Implementar uma função que, dado o
vetor V1, preencha um vetor V2, do qual cada posição consistirá em um struct com os seguintes campos:

 valor: cada valor do vetor V1;
 ocorrencias: quantidade de ocorrências deste valor em V1;
 posicao: posição da primeira ocorrência do valor em V1.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct {
  int valor;
  int ocorrencias;
  int posicao;
}Info;

int busca (Info v2[], int quant, int buscado){
  for (int i = 0 ; i < quant ; i++){
    if (v2[i].valor == buscado){
      return i;
    }
  }
  return -1;
}

void zeraVetor(Info v2[], int quant){
  for ( int i = 0 ; i < quant ; i++){
    v2[i].ocorrencias=0;
  }
}

void preencheV2(int v1[], Info v2[], int quant){

  int pos;
  int k=0;
  int dif=0;

  zeraVetor(v2, quant);
  for ( int i = 0 ; i < quant ; i++ ){
    pos = busca(v2, k, v1[i]);
    if(pos == -1){
      v2[k].valor=v1[i];
      v2[k].ocorrencias++;
      v2[k].posicao=k+dif;
      k++;
    }
    else{
      v2[pos].ocorrencias++;
      dif++;
    }
  }
    printf("\nValores:");
  for (int i = 0 ; i < k ; i++){
    printf(" %d,", v2[i].valor);
  }
    
    printf("\nOcorrencias:");
  for (int i = 0 ; i < k ; i++){
    printf(" %d,", v2[i].ocorrencias);
  }
  
    printf("\nPosicao:");
  for (int i = 0 ; i < k ; i++){
    printf(" %d,", v2[i].posicao);
  }
}

int main(void) {
  int v1[TAM]={4, 9, 5, 1, 1, 2, 4, 8, 5, 4};
  Info v2[TAM];

  preencheV2(v1, v2, TAM);
  
  return 0;
}
