#include <stdio.h>

/*
Considere a existência do tipo TAluno contendo as 
seguintes informações sobre um aluno: nome, nota na
AV1, nota na AV2, média e situação. 

Dado, portanto, um vetor do tipo TAluno, contendo 
quant posições, fazer uma função que verifique se o 
vetor está ordenado, conforme os seguintes critérios:
1. As médias devem estar ordenadas de forma 
decrescente;
2. No caso de médias iguais, os respectivos nomes 
dos alunos devem estar ordenados 
crescentemente.

Caso o vetor esteja ordenado conforme regras citadas 
acima, a função deverá retornar a constante TRUE; 
caso contrário, FALSE.
  */

#define TRUE 0
#define FALSE 1

#define quant 3

typedef struct {
  char nome[50];
  float AV1, AV2, media;
  int situacao;
 }TAluno;

void maiuscula(char c) {
 if (c>='a' && c<='z'){
    c=c-'a'+'A';
    }
}

int VerificaOrdem(TAluno alunos[]){
  //1-medias em ordem descrescente - 9 8 7 6 - OK
  //2-medias iguais -> nomes em ordem crescente (alfabética)
  int i, j;

  for(i=0; i<quant; i++){
    for(j=i+1; j<quant; j++){
      if(alunos[i].media < alunos[j].media){
          return FALSE;
        }

      if(alunos[i].media == alunos[j].media){
        if ((alunos[i].nome[0]>='A' && alunos[i].nome[0]<='Z') && (alunos[j].nome[0]>='A' && alunos[j].nome[0]<='Z')){//se for maiuscula
          if(alunos[i].nome[0] > alunos[j].nome[0]){
            return FALSE;
          }
        } else {
          maiuscula(alunos[i].nome[0]);
          maiuscula(alunos[j].nome[0]);
          if(alunos[i].nome[0] > alunos[j].nome[0]){
            return FALSE;
          }
        }
      }
    }
  }

  return TRUE;
}

int VerificaSituacao (TAluno alunos[], int pos){
  int i;

  for(i=0; i<quant; i++){
    if(i==pos){
      if(alunos[i].media >= 6){
        alunos[i].situacao=0; //aprovado
          return TRUE;
      } else {
        alunos[i].situacao=1; //reprovado
          return FALSE;
      }  
    }
  }
}

void Preenche(TAluno alunos[]){
  int i;

  for(i=0; i<quant; i++){
    printf("\n--------- ALUNO %d ------------\n",i+1);
    printf("Nome: ");
    scanf(" %[^\n]",alunos[i].nome);
    printf("AV1: ");
    scanf("%f",&alunos[i].AV1);
    printf("AV2: ");
    scanf("%f",&alunos[i].AV2);
    alunos[i].media=(alunos[i].AV1+alunos[i].AV2)/2;
    if(VerificaSituacao(alunos,i)==TRUE){//aprovado
      printf("\n\tAPROVADO(A)!\n");
    } else {
      printf("\n\tREPROVADO(A)!\n");
    }
  }
}

int main(void) {
  TAluno alunos[quant];

  Preenche(alunos);
  if(VerificaOrdem(alunos)==TRUE){
    printf("\n\tA ordem está de acordo com os critérios!");
  } else {
    printf("\n\tA ordem NÃO está de acordo com os critérios!");
  }
  
  return 0;}