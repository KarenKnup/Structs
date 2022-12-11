#include <stdio.h>

/*
  Faça um programa que capture os registros de
consumo da frota de uma empresa com: o nº
identificador do carro, o mês, a quantidade de litros
consumidos pelo carro naquele mês, exibindo o
quantidade total de litros gasto por mês pela
empresa.
  */

#define m 2
#define carros 2

typedef struct {
  int carro[carros];
  int litros[carros];
}TMeses;

void preenche (TMeses mes[m]){
  //Janeiro
  mes[0].carro[0]=1;
  mes[0].litros[0]=10;
  
  mes[0].carro[1]=3;
  mes[0].litros[1]=30;

  //Fevereiro
  mes[1].carro[0]=2;
  mes[1].litros[0]=20;

  mes[1].carro[1]=4;
  mes[1].litros[1]=40;
}

int Gasto (TMeses mes[m], int me){
  me--;

  int gasto=0;

  for(int i=0; i<m; i++){
    if(i == me){
      for(int j=0; j<carros; j++){
        gasto+=mes[i].litros[j];
      }
    }
  }
  return gasto;
}


int main(void) {
  TMeses mes[m];
  int me, c;

  preenche(mes);
  
  printf("Verificar em qual mês: ");
  scanf("%d",&me);
  if(me>0 && m<=12){
    printf("\n\t%d Litros",Gasto(mes,me));
    } else {
    printf("\n\tEsse mês não existe. Tente novamente.");
    printf("\nVerificar em qual mês: ");
    scanf("%d",&me);
      printf("\n\t%d Litros",Gasto(mes,me));
    }
  
  return 0;
}