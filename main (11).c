/*
Considere a existência de um vetor de structs com quant posições, onde cada uma destas armazena os seguintes dados sobre os funcionários de uma empresa: 
- matricula (int)
- nome (string)
- gênero (char) 
- salário (float). 

Pede-se uma função que, dado um gênero, desloque todos os funcionários deste gênero para o início do vetor (e, consequentemente, os funcionários do outro gênero ficarão ao final do conjunto).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definição de constantes
#define TRUE 1
#define FALSE 0
#define quant 2

typedef struct {
  int matricula;
  char nome[50];
  char genero;
  float salario;
} Info;

void PreencheV (Info v[]){
  int i;
  for(i=0; i<quant; i++){
    printf("\n\n------ PESSOA %d -------\n",i+1);
    //printf("Matrícula: ");
   // scanf("%d",&v[i].matricula);
    printf("Nome: ");
    scanf(" %[^\n]",v[i].nome);
    printf("Gênero (M/F): ");
    scanf(" %c",&v[i].genero);
   // printf("Salário: ");
   // scanf("%f",&v[i].salario);
  }
}

void zeraVetor(int v2[], int c){
  for ( int i = 0 ; i < c ; i++){
    v2[i]=0;
  }
}

void ExibeV (Info v[]){
  int i;
  for(i=0; i<quant; i++){
    printf("\n\n------ PESSOA %d -------\n",i+1);
    //printf("\n\n\tMatrícula %d: %d",i+1,v[i].matricula);
    printf("\n\tNome: %s",v[i].nome);
    printf("\n\tGênero: %c",v[i].genero);
   // printf("\n\tSalário %d: %.2f",i+1,v[i].salario);
  }  
}

int contaGenero (Info v[], char g){
  int cont=0, i;

 for (i=0; i<quant; i++){
    if (v[i].genero == g){
      cont++;
    }
  }
  
  return cont;
}

void Func (Info v[quant], char g){// desloque todos os funcionários deste gênero para o início do vetor e o resto para o fim
  int i,k=0,pos, n=contaGenero(v,g);
  int v2[n]; //armazena as posiçoes das pessoas de g
  Info temp[quant];
  
  zeraVetor(v2,n);

  for(i=0; i<quant; i++){//bota em v2 as posições das pessoas com o gênero 'g'
    if(v[i].genero == g){
      v2[k]=i;
        k++;
    }
  }

  for(i=0; i<n; i++){//bota no início do vetor temporário as pessoas com o gênero 'g'
    pos=v2[i];
    temp[i]=v[pos];
  }

  for(i=0; i<quant; i++){//bota no restante do vetor as pessoas com o outro gênero
    if(v[i].genero != g){
      temp[n]=v[i];
        n++;
    }
  }

  for (i=0; i<quant; i++){//passa as informações no temporário para o vetor
    v[i]=temp[i];
  }

}

int main(void) {
  Info v[quant];
  char g;
  
  PreencheV(v);
  //ExibeV(v);

  printf("\n\nEscolha um gênero (M/F): ");
  scanf(" %c",&g);
  
  if(g=='M' || g=='F' || g=='m' || g=='f'){
    printf("\n\n======= RESULTADO =========\n");
    Func(v,g);
    ExibeV(v);
  } else {
    printf("\n\nGênero digitado errado! Tente novamente.\n\n");
    printf("Escolha um gênero (M/F): ");
    scanf(" %c",&g);
  }
 
  
  return 0;
  }