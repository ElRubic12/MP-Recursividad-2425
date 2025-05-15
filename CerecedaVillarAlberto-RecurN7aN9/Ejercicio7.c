#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int funcionelementosmatriz( int **m, int dimensiones, int cont, int elementos, int i, int j, int conti, int contj, int filas, int columnas );

int main()
{
    int i, j, resultado;

    int valores[4][4] = {                ///*****Se puede pegar cualquier matriz, definida de la misma forma en la que está definida, y con el nombre valores*****
        {4, 4, 4, 5},
        {4, 5, 1, 3},
        {4, 8, 4, 7},
        {2, 2, 2, 2}
    };

    int dimensiones = sqrt(sizeof(valores) / 4);         ///Calcula la dimension de la matriz en funcion de los bytes que ocupa

    printf( "Las dimensiones de la matriz son: %d x %d.\n", dimensiones, dimensiones );

    int **matriz = (int **)malloc( dimensiones * sizeof(int *) );             ///Tamaño de la matriz definido de forma dinamica
    for( i = 0; i < dimensiones; i++ )
    {
        matriz[i] = (int *)malloc( dimensiones * sizeof(int) );
    }

    ///Se introducen los elementos de la matriz valores en la matriz definida dinamicamente
    for( i = 0; i < dimensiones; i++ )
    {
        for( j = 0; j < dimensiones; j++ )
        {
            matriz[i][j] = valores[i][j];
        }
    }

    ///Imprime la matriz previamente definida
    printf( "  " );               ///Espacio para alinear con los índices de fila
    for( j = 0; j < dimensiones; j++ ){
        printf( "  %d ", j );
    }
    printf( "\n" );

    printf( "   " );            ///Espacio para alinear los - con los numeros de la matriz
    for( j = 0; j < dimensiones; j++ ){
        printf( " -  ");
    }
    printf( "\n" );

    ///Imprimir la matriz con los indices de las filas
    for( i = 0; i < dimensiones; i++ ){
        printf( "%d | ", i );     ///Indice de fila con separador
        for( j = 0; j < dimensiones; j++ ){
            printf( "%d   ", matriz[i][j] );
        }
        printf( "\n" );
    }


    ///Llamada a la funcion recursiva
    resultado = funcionelementosmatriz( matriz, dimensiones, 0, 0, 0, 0, 0, 0, 0, 0 );
    printf( "Valor Devuelto: %d.\n", resultado );


    system( "pause" );
}

///Cabecera: int funcionelementosmatriz( int **m, int n, int cont, int elementos, int i, int j, int conti, int contj, int filas, int columnas )
///Precondicion: Se puede elegir cualquier matriz cuadrada que se desee definiendola como está definida la matriz default y poniendole el nombre "valores".
///              Se le pasa una matriz definida de forma dinamica, las dimensiones de la matriz(n), el contador general de la funcion, el numero de elementos que
///              cumplen la condicion, la variable que controla las columnas, la variable que controla las filas, una variable contador para recorrer las columnas
///              para cada numero, una variable contador para recorrer las filas para cada numero, una variable filas que cuenta el numero de valores de la fila
///              que son menores que el numero actual y una variable columnas que cuenta el numero de valores de cada columna que son mayores que el numero actual.
///Postcondicion: Se va a calcular el numero de elementos que son mayores que todos los numeros de su fila y menores que todos los elementos de su columna

int funcionelementosmatriz( int **m, int n, int cont, int elementos, int i, int j, int conti, int contj, int filas, int columnas )
{
    if( cont == n*n )       ///CASO BASE: Se han recorrido todas las posiciones de la matriz
    {
        return elementos;           ///Devuelve el numero de elementos de la matriz que cumplen con la condicion
    }else{

        if( j < n )             ///La matriz se recorre fila a fila y cuando se llega al final de la fila no entra en esta condicion
        {
            
            if( contj >= n || conti >= n )      ///Caso en el que se han recorrido todos los valores de la fila y columna del valor de la posicion que se esta comprobando
            {
                if( filas == n-1 && columnas == n-1 )       ///Si las variables filas y columnas valen uno menos que la dimension de la matriz significa que el numero que se esta comprobando cumple la condicion
                {
                    return funcionelementosmatriz( m, n, cont+=1, elementos+=1, i, j+=1, 0, 0, 0, 0 );
                }else{                                      ///Si filas o columnas no valen uno menos que la dimension de la matriz ese numero que se esta comprobando no cumple con la condicion
                    return funcionelementosmatriz( m, n, cont+=1, elementos, i, j+=1, 0, 0, 0, 0 );
                }

            }else{      ///Caso en el que se esta recorriendo la fila y columna del numero que se esta comprobando

                if( contj == j )        ///Caso para que, recorriendo la fila, no se compruebe la condicion sobre el numero que se esta comprobando actual
                {
                    contj++;
                }
                if( conti == i )        ///Caso para que, recorriendo la columna, no se compruebe la condicion sobre el numero que se esta comprobando actual
                {
                    conti++;
                }

                if( conti == n && contj == n )      ///Caso en el que se esta comprobando el ultimo numero de la matriz(ultima posicion)
                {
                    conti++;
                    contj++;
                }else{              ///Mientras no se haya llegado al ultimo numero de la matriz

                    if( m[i][j] > m[i][contj] )         ///Realiza la comparacion de el numero que se esta comprobando con los de su fila
                    {
                        filas++;
                    }

                    if( m[i][j] < m[conti][j] )         ///Realiza la comparacion de el numero que se esta comprobando con los de su columna
                    {
                        columnas++;
                    }
                }

                return funcionelementosmatriz( m, n, cont, elementos, i, j, conti+=1, contj+=1, filas, columnas );
            }
        }else{      ///Caso en el que se ha recorrido cada fila, aumenta el numero de i(de la columna)
            return funcionelementosmatriz( m, n, cont, elementos, i+=1, 0, 0, 0, 0, 0 );
        }
    }
}