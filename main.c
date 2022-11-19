#include <stdio.h>
/*

- Tipos de dados básicos - int, float, char
- Variáveis simples -  armazena 1 único dado por momento
- Estrutura de dados - são variáveis capazes de manipular, simultaneamente, diversos valores 
  -- Estrutura de dados HOMOGÊNEA - armazenam diversos valores ao mesmo tempo (estrutura de dados) e são dados do mesmo tipo (homogênea)
  -- Estrutura de dados HETEROGÊNEA - dados de tipos diferentes

*/

/*

typedef - definindo um tipo de dado

strcpy(aluno.nome,"Joao");
strcpy(aluno.matricula,"212...");

TAluno turma[30]; --> cada aluno dos 30 do vetor turma tem as mesmas características do TAluno
*/

int main(void) {
TAluno aluno;
  
  printf("Nome: ");
  gets(aluno.nome);
  ....
printf("CR: ");
  scanf("%f",&aluno.cr);

TAluno turma[30];
  for (i=0; i<30; i++){
    printf("Nome: ");
  gets(turma[i].nome);
  ....
printf("CR: ");
  scanf("%f",&turma[i].cr);
  }

  void funcaoA(TAluno a){
    
  }

  void funcaoB(TAluno *b){
    
  }

  TAluno a1,a2; --> a2=a1 //copia tudo de a1 p/ a2, evita ter que ficar repetindo a operação
  
  return 0;
}