#include<stdio.h>
#include<string.h>

#define TAM 8

int funcionrara( int v[], int i, int alfa, int correcto, int suma );

int main()
{
    int vector[TAM] = {1, 3, 9, 54, 4, 5, 2, 3};
    int resultado;

    resultado = funcionrara( vector, 2, 1, 1, vector[0]*vector[TAM-1] );

    if( resultado == 0 )
    {
        printf( "Se cumple la condicion.\n" );
    }else{
        printf( "No se cumple la condicion.\n" );
    }
}

///Cabecera: int v[], int i, int alfa, int correcto, int suma
///Precondicion: Recibe un vector con diferentes numeros, un iterador que recorre el vector desde 2 hasta la mitad del tamaño del vector, un 1 si no se cumple la condicion inicilamente y la suma de la primera iteracion
///Postcondicion: Devuelve un 0 si cumple la condicion y un 1 si no la cumple

int funcionrara( int v[], int i, int alfa, int correcto, int suma )
{
    if( i > TAM/2 )     ///Caso base se ha recorrido la primera mitad del vector
    {
        if( correcto == 0 )
        {
            return 0;
        }else{
            return 1;
        }
    }else{

        if( i-1 >= alfa && v[i-1] == suma )       ///Caso base para el sumatorio
        {
            if( i-1 < alfa+1 )                  ///Caso en el que se llegue al final del sumatorio
            {
                return funcionrara( v, i+1, 1, 0, suma+=(v[alfa] * v[TAM - alfa-1]) );
            }else{                              ///caso en el que se no se haya llegado al final del sumatorio
                return funcionrara( v, i, alfa+1, 0, suma );
            }
        }else{                                  ///caso en el que no cumple la condicion
            return 1;
        }

    }

}