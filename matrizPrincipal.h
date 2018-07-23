#ifndef MATRIZPRINCIPAL_H_INCLUDED
#define MATRIZPRINCIPAL_H_INCLUDED

void imprimirMatriz(const int FIL,const int COL,char matriz[][COL])
{
    int i,j;
    printf("\n");
    for(i=0;i<FIL;i++)
    {
        printf("\t\t%i\t",i);
        for(j=0;j<COL;j++)
        {
            printf("%c",matriz[i][j]);

        }
        putchar('\n');

    }
}

void actualizarGeneracion(int FIL,int COL,char matriz[][COL],char matrizCopia[][COL],int generacion,int apocalipsis,int delay)
{
    int i,j;
    ///nueva generacion actualizada
    for(i=0; i<FIL; i++)
        for(j=0; j<COL; j++)
            matriz[i][j] = matrizCopia[i][j];

    ///Para el fin del juego
    if(generacion==apocalipsis) system("pause");

    ///retraso en la impresion


}
#endif // MATRIZPRINCIPAL_H_INCLUDED
