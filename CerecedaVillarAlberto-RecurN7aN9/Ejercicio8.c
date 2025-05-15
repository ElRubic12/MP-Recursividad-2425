#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TAM 4

int funcionvector( int v[], int j, int k, int parejas, int suma1, int suma2, int cont, int contj, int contk, int nueva_k );

int main()
{
    int  vector[TAM] = {1, 3, 2, 3};
    int resultado;

    resultado = funcionvector( vector, 0, 0, 0, 0, 0, 0, 0, 0, 0 );

    printf( "El numero de parejas que cumplen la condicion es: %d.\n", resultado );

    system( "pause" );
}

///Cabecera: int funcionvector( int v[], int j, int k, int parejas, int suma1, int suma2, int cont, int contj, int contk, int nueva_k )
///Precondicion: Se recibe un vector, las parejas(j y k), el contador de las parejas que cumplen la condicion, las sumas de ambas condiciones(desde 0 hasta j y desde k 
///              hasta TAM), el contador general del programa(finaliza cuando se hayan operado sobre todas las parejas posibles), los contadores para ir recorriendo y
///              sumando los valores tanto desde 0 hasta j como desde k hasta TAM, y una variable para aumentar el valor de una de las parejas(k)
///Postcondicion: Devuelve el numero de parejas que cumplen la condicion de que la suma desde 0 hasta el primer valor de la pareja es igual a la suma desde el segundo
///              valor de la pareja hasta el final del vector

int funcionvector( int v[], int j, int k, int parejas, int suma1, int suma2, int cont, int contj, int contk, int nueva_k )
{
    if( cont > TAM*TAM )        ///Caso base: cuando el contador del programa supere el numero maximo de recorridos del vector
    {
        return parejas;
    }else{

        if( j != k )            ///Caso en que las posiciones del vector no sean las mismas(se esta operando sobre una pareja de posiciones distintas)
        {
            if( contj <= j && contk < TAM )         ///Se realizan las sumas que corresponden a cada posicion de la pareja: de 0 a j y de k a n
            {
                suma1 += v[contj];
                suma2 += v[contk];

                return funcionvector( v, j, k, parejas, suma1, suma2, cont, contj+=1, contk+=1, 0 );    ///Llama a la funcion aumentando los contadores
            }else{                                  ///Caso en el que al menos un contador que suman los numeros de las posiciones correspondientes supere el limite que tiene que sumar(j o TAM)
                if( contk+1 <= TAM )                ///Suma el elemento de la siguiente posicion si aun no ha llegado al final del vector
                {
                    suma2 += v[contk];
                }
                if( contj+1 <= j )                  ///Suma el elemento de la siguiente posicion si aun no ha llegado a la posicion j
                {
                    suma1 += v[contj];
                }

                if( k == TAM-1 )                    ///Caso en que k ha llegado al final del vector y provoca que aumente en 1 a j y se reinicia k a 0
                {
                    if( suma1 == suma2 )            ///Caso en que las sumas sean iguales aumenta el contador de las parejas
                    {
                        return funcionvector( v, j+=1, 0, parejas+=1, 0, 0, cont+=1, 0, 0, 0 );
                    }else{                          ///Caso en que las sumas no sean iguales y no aumenta el contador de las parejas
                        return funcionvector( v, j+=1, 0, parejas, 0, 0, cont+=1, 0, 0, 0 );
                    }
                }else{                              ///Caso en el que k aun no ha llegado al final del vector y k aumenta en uno
                    nueva_k = k + 1;
                    if( suma1 == suma2 )            ///Caso en que las sumas sean iguales y aumenta el contador de las parejas
                    {
                        return funcionvector( v, j, nueva_k, parejas+=1, 0, 0, cont+=1, 0, nueva_k, 0 );
                    }else{                          ///Caso en el que las sumas no sean iguales y no aumenta el contador de las parejas
                        return funcionvector( v, j, nueva_k, parejas, 0, 0, cont+=1, 0, nueva_k, 0 );
                    }
                }
            }
        }else{                  ///Caso en el que las posiciones del vector sean las mismas(se estaria operando sobre el mismo numero)
            nueva_k = k + 1;

            return funcionvector( v, j, nueva_k, parejas, 0, 0, cont+=1, 0, nueva_k, 0 );
        }

    }
}