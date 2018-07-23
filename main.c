#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "matrizPrincipal.h"
#include "vecindadCelula.h"
#include "inicializacion.h"

int main()
{

    char color[9] = "color 0f";
    long int generacion,apocalipsis=1000,poblacion;
    int FIL=30,COL=FIL*2,i,j;
    int delay=0;
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tCargando...");
    Sleep(delay);
    system("cls");

    tiempoColor(color);

    srand(clock());
    char matriz[FIL][COL];
    char matrizCopia[FIL][COL];

    char valorCelMuertas='-'; char valorCelVivas=2; char valorBorde[] = {3,4,5,6};

    inicioMatrizBase(FIL,COL,matriz,matrizCopia,valorCelMuertas,valorCelVivas,valorBorde[rand()%4]);


    for(generacion=1; generacion<=apocalipsis; generacion++)
    {
        printf("Generacion: %ld",generacion);

        poblacion = 0;

        for(i=0; i<FIL; i++)
            for(j=0; j<COL; j++)
                if(matriz[i][j]==valorCelVivas)
                    poblacion++; ///Contador de poblacion

        printf("\nPoblacion: %ld",poblacion);

        imprimirMatriz(FIL,COL,matriz);
        obtenerGeneracion(FIL,COL,matriz,matrizCopia,valorCelVivas,valorCelMuertas);
        actualizarGeneracion(FIL,COL,matriz,matrizCopia,generacion,apocalipsis,delay);
         Sleep(30);system("cls");


    }


    return 0;
}
