#include <stdio.h>

/*
  Considere um vetor que armazene alguns
dados coletados de um grupo de pessoas em
uma pesquisa, a saber: nome, gênero, idade e
altura.
Desenvolver uma função que receba os
parâmetros gênero, faixa de idade (idade inicial
e idade final) e faixa de altura (altura inferior e
altura superior) e retorne a quantidade de
pessoas que atendem aos filtros por ele
representados.
Nota: caso o gênero especificado seja igual a
M, serão considerados os homens que
estiverem nas faixas de idade e altura
especificadas; o mesmo ocorrerá com as
mulheres, quando o gênero for F. Porém, se o
gênero contiver qualquer valor diferente de M
ou F, todas as pessoas que atenderem aos
filtros de idade e altura serão contabilizadas.
  */

//Quantidade de pessoas(TAM):
#define TAM 3

#define TRUE 0
#define FALSE 1

typedef struct {
  char nome[50],
       genero;
  int  idade;
  float altura;
} TPessoa;

void preenche (TPessoa pessoas[]){
  int i;
  for(i=0; i<TAM; i++){
    printf("\n-------- %dª PESSOA ------------\n",i+1);
    printf("Digite o nome: ");
    scanf(" %[^\n]",pessoas[i].nome);
   printf("Gênero (M / F / O): ");
    scanf(" %c",&pessoas[i].genero);
    printf("Idade da pessoa: ");
    scanf("%d",&pessoas[i].idade);
    printf("Altura da pessoa: ");
    scanf("%f",&pessoas[i].altura);
    printf("\n");
  }
}

int VerificaIdade(int idade, int idade_inicial, int idade_final){
  if (idade>=idade_inicial && idade<=idade_final){
    return TRUE;
  } 
    return FALSE;
}

int VerificaAltura(float altura, float maior_altura, float menor_altura){
  if (altura>=menor_altura && altura<=maior_altura){
    return TRUE;
  }
  return FALSE;
}

int VerificaGeneroIdadeAltura(char genero, int idade_inicial, int idade_final, float maior_altura, float menor_altura, TPessoa pessoas[]){
  int i, qtde=0;

  if (genero=='M' || genero=='F'){//F ou M
    for (i=0; i<TAM; i++){
      if (genero==pessoas[i].genero){
        if ((VerificaIdade(pessoas[i].idade,idade_inicial,idade_final) && VerificaAltura(pessoas[i].altura, maior_altura, menor_altura))==TRUE){
        qtde++;
        }
      }
    }
  } else {//Outros
 for (i=0; i<TAM; i++){
      if ((VerificaIdade(pessoas[i].idade,idade_inicial,idade_final) && VerificaAltura(pessoas[i].altura, maior_altura, menor_altura))==TRUE){
        qtde++;
      }
    }
  }
  
  return qtde;
}

int main(void) {
 TPessoa pessoas[TAM];
  char v_genero;
  int idade_inicial, idade_final, qtde;
  float maior_altura, menor_altura;

  preenche(pessoas);

  printf("\n----------------------------------------\n");
  printf("Verificar qual gênero (M / F / O): ");
  scanf(" %c",&v_genero);
  printf("Verificar com idade inicial: ");
  scanf("%d",&idade_inicial);
  printf("E idade final: ");
  scanf("%d",&idade_final);
  printf("Verificar da maior altura: ");
  scanf("%f",&maior_altura);
  printf("E menor altura: ");
  scanf("%f",&menor_altura);
  printf("\n----------------------------------------\n");

  qtde=VerificaGeneroIdadeAltura(v_genero,idade_inicial,idade_final,maior_altura,menor_altura,pessoas);
  
  if (qtde>0){
    printf("\n\n\tHá %d pessoa(s) dentro dos filtros selecionados.",qtde);
  } else{
    printf("\n\n\tNão há pessoas dentro dos filtros selecionados.");
  }
  
  return 0;
}