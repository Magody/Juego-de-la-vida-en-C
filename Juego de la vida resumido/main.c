#include <stdio.h>
#include <stdlib.h>
#include <time.h>

  void main(){
    srand(clock());
    int f=20,c=50,vecinos=0; int i,j,k;
    int matriz[f][c]; int copiaMatriz[f][c];

    for(i=0;i<f;i++) for(j=0;j<c;j++){//borde y base
        if(i==0||j==0||j==c-1||i==f-1){matriz[i][j] = 3;copiaMatriz[i][j] = 3; }else{matriz[i][j] = 1;copiaMatriz[i][j] = 1;}}

    for(j=0;j<(int)c/2;j++) for(i=1;i<=10;i++) matriz[1+rand()%(f-1)][1+rand()%(c-1)] = 0; //celulas inicio

    while(1){
      for(i=0;i<f;i++){for(j=0;j<c;j++) printf("%d",matriz[i][j]); printf("\n");}

      for(i=1;i<f-1;i++){for(j=1;j<c-1;j++){
          int posiciones[8][2] = {{i-1,j},{i-1,j+1},{i,j+1},{i+1,j+1},{i+1,j},{i+1,j-1},{i,j-1},{i-1,j-1}};

          for(k=0;k<8;k++) if(matriz[posiciones[k][0]][posiciones[k][1]]==0) vecinos++;

          if((vecinos==3 && matriz[i][j]==1)||((vecinos==2||vecinos==3) && matriz[i][j]==0)) copiaMatriz[i][j]=0;

          if((vecinos<2||vecinos>3) && matriz[i][j]==0) copiaMatriz[i][j]=1; vecinos=0;}}

      for(i=0;i<f;i++) for(j=0;j<c;j++) matriz[i][j] = copiaMatriz[i][j]; system("cls");
    }
  }
