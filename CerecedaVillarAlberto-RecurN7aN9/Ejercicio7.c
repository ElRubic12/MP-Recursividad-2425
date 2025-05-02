#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define M 5
#define N 5

void funcionmatriz( int m[M][N], int x, int y, int i, int j, int cont, int filas, int colum );

int main()
{
    int i, j, x, y;

    int matriz[M][N] = {
        {4, 7, 2, 1, 9},
        {5, 8, 4, 3, 6},
        {8, 9, 7, 2, 1},
        {4, 7, 2, 9, 2},
        {5, 8, 1, 3, 7}
    };

    printf( "  " );               ///Espacio para alinear con los índices de fila
    for( j = 0; j < N; j++ ){
        printf( "  %d ", j );
    }
    printf( "\n" );

    printf( "   " );            ///Espacio para alinear los - con los numeros de la matriz
    for( j = 0; j < N; j++ ){
        printf( " -  ");
    }
    printf( "\n" );

    ///Imprimir la matriz con los indices de las filas
    for( i = 0; i < M; i++ ){
        printf( "%d | ", i );     ///Indice de fila con separador
        for( j = 0; j < N; j++ ){
            printf( "%d   ", matriz[i][j] );    ///Espaciado uniforme
        }
        printf( "\n" );
    }

    do{                            ///Se introducen las coordenadas de la matriz
        printf( "Introduce las coordenadas de una posicion de la matriz(0-%d):\n", M-1 );
        printf( "Introduce la coordenada x: " );
        scanf( "%d", &x );
        printf( "Introduce la coordenada y: " );
        scanf( "%d", &y );
    }while( x < 0 || x >= M || y < 0 || y >= N );       ///Mientras sea menor que 0 y mayor que el tamaño de la matriz

    printf( "Numero elegido: %d.\n", matriz[x][y] );

    funcionmatriz( matriz, x, y, 0 , 0, 0, 0, 0 );

}

///Cabecera: int m[M][N], int x, int y, int i, int j, int cont, int filas, int colum
///Precondicion: Recibe una matriz desordenada, las posiciones x e y elegidas, 2 iteradores i y j, un contador para contar
///              las veces que recorre las filas y columnas, el numero de elementos de filas y columnas
///Postcondicion: Devuelve el numero de elementos que son menores que los elementos de la fila y el numero de elementos que 
///              son mayores que los elementos de la columna del numero elegido

void funcionmatriz( int m[M][N], int x, int y, int i, int j, int cont, int filas, int colum )
{
    if( cont == M*2 )           ///Caso base cuando se han recorrido todos los elementos de las filas y columnas desde el numero elegido
    {
        printf( "El numero %d es mayor que %d numeros de su fila.\n", m[x][y], filas );
        printf( "El numero %d es menor que %d numeros de su columna.\n", m[x][y], colum );
    }else{

        if( j < N )             ///Primero recorren los elementos de la fila desde el numero elegido
        {
            if( m[x][j] < m[x][y] )         ///Caso en que el elemento de la fila sea menor que el numero elegido aumenta la variable filas
            {
                return funcionmatriz( m, x, y, i, j+=1, cont+=1, filas+=1, colum );
            }else{
                return funcionmatriz( m, x, y, i, j+=1, cont+=1, filas, colum );
            }
        }

        if( i < M )             ///Despues se recorren los elementos de la columna desde el numero elegido
        {
            if( m[i][y] > m[x][y] )         ///Caso en que el elemento de la columna sea mayor que el numero elegido aumenta la variable colum
            {
                return funcionmatriz( m, x, y, i+=1, j, cont+=1, filas, colum+=1 );
            }else{
                return funcionmatriz( m, x, y, i+=1, j, cont+=1, filas, colum );
            }
        }

    }
}