#ifndef VECINDADCELULA_H_INCLUDED
#define VECINDADCELULA_H_INCLUDED

void obtenerGeneracion(int const f,int const c,char matriz[][c],char matrizCopia[][c],char valorCelVivas,char valorCelMuertas)
{
    int i,j,k,vecinos=0;

    for(i=1; i<f-1; i++)
    {
        for(j=1; j<c-1; j++)
        {
            int posiciones[8][2] =
            {
                {i-1,j},
                {i-1,j+1},
                {i,j+1},
                {i+1,j+1},
                {i+1,j},
                {i+1,j-1},
                {i,j-1},
                {i-1,j-1}
            };

            for(k=0; k<8; k++)
                if(matriz[posiciones[k][0]][posiciones[k][1]]==valorCelVivas)
                    vecinos++;

            if((vecinos==3 && matriz[i][j]==valorCelMuertas)||((vecinos==2||vecinos==3) && matriz[i][j]==valorCelVivas))
                matrizCopia[i][j]=valorCelVivas;

            if((vecinos<2||vecinos>3) && matriz[i][j]==valorCelVivas)
                matrizCopia[i][j]=valorCelMuertas;
            vecinos=0;
        }
    }
}




#endif // VECINDADCELULA_H_INCLUDED
