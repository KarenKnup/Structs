#include <stdio.h>
#include <string.h>
/*
Considere a existência de um vetor no qual cada posição pode armazenar o nome do aluno, as notas de AV1 e AV2, sua média e a situação (aprovado, reprovado ou em AVF). Pede-se:

-- A declaração do vetor, assim como de todos os tipos de dados necessários, caso existam;
-- Uma função que leia os dados de todos os alunos da turma;
-- Uma função que calcule a média de cada aluno (e a armazene no vetor), assim como a sua situação;
-- Uma função que, dado um número inteiro (1-aprovado;2-reprovado;3-em AVF), exiba todos os alunos que estão nesta situação.
  */

//Quantos alunos (TAM):
#define TAM 3

typedef struct {
  char nome[50]; 
  int AV1,
      AV2,
      media,
      situacao;
} TAluno;

void preencheAluno (TAluno alunos[]){
  int i;

  for(i=0; i<TAM; i++){
    printf("\n-------- ALUNO(A) %d ------------\n",i+1);
    printf("Nome do(a) aluno(a): ");
    fflush(stdin);
    scanf(" %[^\n]",alunos[i].nome);
    printf("Digite a nota da AV1: ");
    scanf("%d",&alunos[i].AV1);
    printf("Digite a nota da AV2: ");
    scanf("%d",&alunos[i].AV2);   
    printf("\n");
  }
}
int Sit (int i, TAluno alunos[i]){//(1-aprovado;2-reprovado;3-em AVF)
  
  if (alunos[i].media>=6){//aprovado
    return 1;
    } else {//reprovado
    if(alunos[i].media<3){//Reprovado
    return 2;
      } else {//AVF
      return 3;
        }
      }
    
  }


void calculaMedia_Situacao(TAluno alunos[]){
  int i;

  for(i=0; i<TAM; i++){
    printf("\n-------- ALUNO(A) %d ------------\n",i+1);
    alunos[i].media=((alunos[i].AV1)+(alunos[i].AV2))/2;
    printf("Média do aluno %d: %d",i+1,alunos[i].media);
    alunos[i].situacao=Sit(i,alunos);
    if(alunos[i].situacao==1){//(1-aprovado;2-reprovado;3-em AVF)
      printf("\nSituação: APROVADO(A)");
    } else if (alunos[i].situacao==2){
      printf("\nSituação: REPROVADO(A)");
    } else {
      printf("\nSituação: EM AVF");
    }
    printf("\n");
  }
}

void AlunosAVF (TAluno alunos[]){
  int i;

  printf("\n-------- ALUNOS EM AVF: --------\n");
  for(i=0; i<TAM; i++){
    if (alunos[i].situacao==3){
      printf("%s \n",alunos[i].nome);
    }
  }
}

int main(void) {
  TAluno alunos[TAM];

  preencheAluno(alunos);
  calculaMedia_Situacao(alunos);
  AlunosAVF(alunos);
  
  return 0;
}