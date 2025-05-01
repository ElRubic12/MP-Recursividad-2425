#include<stdio.h>
#include<string.h>

#define TAM 10

int contarescalera( int vector[], int cont, int longitud, int longitud_max );

int main()
{
    int vector[TAM] = {5, 2, 3, 4, 9, 8, 1, 3, 2, 1};
    int longitud;

    longitud = contarescalera( vector, 0, 1, 1 );

    printf( "Longitud: %d.\n", longitud );
}

///Cabecera: int vector[], int cont, int longitud, int longitud_max
///Precondicion: Se le pasa un vector desordenado con una escalera de numeros crecientemente, un contador para recorrer el vector, la longitud de la escalera que esta contando en la posicion actual y la longitud de la escalera mas larga
///Postcondicion: Devuelve la longitud de la escalera mas larga del vector

int contarescalera( int vector[], int cont, int longitud, int longitud_max )
{
    if( cont == TAM-1 )
    {
        return longitud_max;
    }else{

        if( vector[cont] < vector[cont+1] )     ///Compara el valor de la posicion actual con la siguiente
        {
            if( longitud >= longitud_max )      ///Si la escalera que esta comparando en la posicion actual tiene una longitud mayor que la escalera previamente leida, actualiza el valor de la longitud maxima
            {
                return contarescalera( vector, cont+1, longitud+1, longitud+1 );
            }else{                              ///Si la longitud de la escalera que esta comparando en la posicion actual aun no es mayor que la longitud de alguna escalera leida anteriormente
                return contarescalera( vector, cont+1, longitud+1, longitud_max );
            }
        }else{                                  ///En caso de que la posicion actual del vector sea mayor o igual que la posicion siguiente del vector
            return contarescalera( vector, cont+1, 1, longitud_max );
        }

    }
}