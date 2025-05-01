#include<stdio.h>
#include<stdlib.h>

#define N 5

void numeromaxmin( int vector[], int max, int min, int cont );

int main()
{
    int vector[N] = {9, 6, 52, 10, 5};

    numeromaxmin( vector, vector[0], vector[0], 0 );

}

///Cabecera: int vector[], int max, int min, int cont
///Precondicion: Se le pasa a la funcion un vector no nulo
///Postcondicion: Devuelve el maximo y el minimo de los numeros dentro del vector en max y min

void numeromaxmin( int vector[], int max, int min, int cont )
{
    if( cont == N )
    {
        printf( "El numero maximo es: %d.\n", max );
        printf( "El numero minimo es: %d.\n", min );

    }else{
        if( vector[cont] > max )
        {
            max = vector[cont];
        }
        if( vector[cont] < min )
        {
            min = vector[cont];
        }

        return numeromaxmin( vector, max, min, cont+1 );
    }

}