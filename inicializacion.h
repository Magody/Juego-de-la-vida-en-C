#ifndef INICIALIZACION_H_INCLUDED
#define INICIALIZACION_H_INCLUDED


void seleccionColor(char color[])
{
    int lenCad;

    do{
        printf("\t\t\tColores\n\n");
        printf("\n\t0 = Negro   \t8 = Gris");
        printf("\n\t1 = Azul    \t9 = azul claro");
        printf("\n\t2 = Verde   \tA = verde claro");
        printf("\n\t3 = Aqua    \tB = Aqua claro");
        printf("\n\t4 = Rojo    \tC = Rojo claro");
        printf("\n\t5 = Morado  \tD = morado claro");
        printf("\n\t6 = Amarillo\tE = amarillo claro");
        printf("\n\t7 = Blanco  \tF = blanco brillante");

        printf("\n\nEscriba el color,\nEjemplo1 escribir 'color 0a' dara un color de fondo negro con letras verdes"
               "\nRecomendacion: escribir 'color f0' para fondo apacible blanco y letras negras\n\nEscriba : ");
        gets(color);

        for(lenCad=0;color[lenCad]!='\0';lenCad++)
        {
            lenCad++;
        }

        if(lenCad!=8)
        {
            printf("\nError. Ingrese un valor adecuado\n");
        }

    }while(lenCad!=8);

}

void tiempoColor(char color[])
{
    clock_t tiempo = clock();
    system(color);

    float tiempoA;

    tiempoA = (clock()-tiempo);

    srand(tiempoA);
    system("mode 160");

}

void inicioMatrizBase(const int f,const int c,char matriz[][c],char matrizCopia[][c],char valorCelMuertas,char valorCelVivas,char valorBorde)
{
    int i,j;

    for(i=0; i<f; i++)
        for(j=0; j<c; j++)
        {
            //borde y base
            if(i==0||j==0||j==c-1||i==f-1)
            {
                matriz[i][j] = valorBorde;
                matrizCopia[i][j] = valorBorde;
            }
            else
            {
                matriz[i][j] = valorCelMuertas;
                matrizCopia[i][j] = valorCelMuertas;
            }
        }

    inicioPatronConway(f,c,matriz,valorCelVivas);
    /*for(j=0; j<c; j++)
        for(i=1; i<=5; i++)
            matriz[1+rand()%(f-1)][1+rand()%(c-1)] = valorCelVivas; //celulas inicio*/


}

void inicioPatronConway(int FIL,int COL,char matriz[][COL],int valorCelVivas)
{
    matriz[FIL/2][COL/2] = valorCelVivas;
    matriz[FIL/2][COL/2+1] = valorCelVivas;
    matriz[FIL/2+1][COL/2+1] = valorCelVivas;
    matriz[FIL/2+2][COL/2+1] = valorCelVivas;
    matriz[FIL/2+1][COL/2+2] = valorCelVivas;
}


#endif // INICIALIZACION_H_INCLUDED
