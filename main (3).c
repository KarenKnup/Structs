#include <stdio.h>
#include <string.h>
//Quantos alunos (TAM):
#define TAM 2
/*
typedef struct {
  char nome[50]; //aluno.nome
  int matricula,
      serie,
      genero;
  float CR;

} TAluno;


void preencheAluno (TAluno alunos[]){
  int i;

  for(i=0; i<TAM; i++){
    printf("---------- ALUNO(A) %d -------------\n",i+1);
     printf("Nome do(a) aluno(a): ");
    fflush(stdin);
    scanf(" %[^\n]", alunos[i].nome);
    printf("Matrícula do(a) aluno(a): ");
    scanf("%d",&alunos[i].matricula);
    printf("Série do(a) aluno(a): ");
    scanf("%d",&alunos[i].serie);
    printf("Digite o gênero do(a) aluno(a) - (1-Feminino / 2-Masculino): ");
    scanf("%d",&alunos[i].genero);
    printf("Digite o CR do(a) aluno(a): ");
    scanf("%f",&alunos[i].CR);
    printf("\n");
  }
}*/
int main(void) {
 //TAluno aluno;
  TAluno alunos[TAM];//turma
  char aluno;

  preencheAluno(alunos);

  printf("\n------------------------------------------\n");
  printf("Digite o nome do(a) aluno(a): ");
  fflush(stdin);
  scanf(" %[^\n]", &aluno);
  printf("\n------------------------------------------\n");  return 0;
}