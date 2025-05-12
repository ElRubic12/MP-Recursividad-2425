#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5
#define M 5

int main()
{
    int i, j;

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
}