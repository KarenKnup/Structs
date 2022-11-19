#include <stdio.h>
#include <string.h>
/*
  Uma pesquisa foi feita e cada entrevistado informou os 
seguintes dados: nome, gênero e idade. Todas as 
informações coletadas foram armazenadas sob a forma 
de um vetor de structs, cada posição armazenando os 
dados de um entrevistado. 
Pede-se o desenvolvimento de uma função que, dado um gênero, retorne a posição do entrevistado que atenda aos seguintes requisitos:
a. Deve ser do gênero especificado como 
parâmetro da função;

b. Caso mais de um entrevistado seja do gênero
definido, deverá ser retornada a posição do 
entrevistado mais novo daquele gênero;

c. Por último, se houver mais de uma pessoa do 
gênero escolhido e com a menor idade, deverá 
ser retornada a posição da que possuir o nome 
que vier primeiro em uma ordem crescente 
alfabética.
  */

//Quantidade de entrevistados(TAM):
#define TAM 3

typedef struct {
  char nome[50],
       genero;
  int idade;
}TEntrevistado;

void preenche (TEntrevistado entrevistados[]){
  int i;
  for (i=0; i<TAM; i++){
    printf("\n------ ENTREVISTADO %d -------\n",i+1);
    printf("Digite o nome: ");
    scanf(" %[^\n]",entrevistados[i].nome);
    printf("Qual o gênero (M / F): ");
    scanf(" %c",&entrevistados[i].genero);
    printf("Qual a idade: ");
    scanf("%d",&entrevistados[i].idade);
    printf("\n");
  }
}

int buscaIdade(int p,TEntrevistado entrevistados[]){
  int i;
  for(i=0;i<TAM;i++){
    if(entrevistados[i].idade==p)
      return i;
  }
  return -1;
}

int buscaOcorrencias(int p,TEntrevistado entrevistados[]){
  int i,c=0;
  for(i=0;i<TAM;i++){
    if(entrevistados[i].idade==p)
      c++;
  }
  return c;
}

int buscaNome(char p[],TEntrevistado entrevistados[]){
  int i;
  for(i=0;i<TAM;i++){
    if(strcmp(p,entrevistados[i].nome)==0)
      return i;
  }
  return -1;
}

int Verifica (TEntrevistado entrevistados [], char genero){
  int i, cont=0, ocorr[TAM], maior_idade=999, idade[TAM];
  char nome[50];

  for(i=0; i<TAM; i++){
    if (genero==entrevistados[i].genero){
      ocorr[cont]=i;//vetor armazena todas as posições i com o genero desejado
      cont++;
      if(entrevistados[i].idade<maior_idade){
         maior_idade=entrevistados[i].idade;//transforma maior idade em menor
      }
    }
  }

  if (cont==0){//se não tiver ninguém do sexo digitado
    return -1;
  } else{
    if(cont==1){//1 pessoa com o sexo digitado
      return ocorr[0];
    } else {//mais de 1 pessoa com o sexo digitado
        if (buscaOcorrencias(maior_idade,entrevistados)==1){//uma pessoa com a maior(menor) idade
          return buscaIdade(maior_idade,entrevistados);//posição do entrevistado com essa maior(menor) idade
        } else {//buscaOcorrencia = mais de 1 pessoa com a maior(menor) idade
          strcpy(nome,"ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ");
      for(i=0;i<cont;i++){
        if((strcmp(entrevistados[ocorr[i]].nome,nome)<0)&&(entrevistados[ocorr[i]].idade==maior_idade)){
           strcpy(nome,entrevistados[ocorr[i]].nome);
        }
      }
      return buscaNome(nome,entrevistados);//posição do nome encontrado na busca com a maior(menor) idade e dentro das ocorrências (do gênero selecionado)
        }
      }
    }
  }


int main(void) {
  TEntrevistado entrevistados[TAM];
  char genero;

  preenche(entrevistados);
  printf("\n---------------------------------------\n");
  printf("Verificar com o gênero (M / F): ");
  scanf(" %c",&genero);
  printf("\n---------------------------------------\n");
  printf("\n\n\tO entrevistado dentro dessa busca é o número %d.",Verifica(entrevistados,genero)+1);
  
  return 0;
}