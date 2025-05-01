#include<stdio.h>
#include<stdlib.h>

#define N 3

int productoescalar( int vect1[], int vect2[], int cont, int suma  );

int main()
{
    int prodescalar;

    int vector1[N] = {2, 4, -1};
    int vector2[N] = {5, -1, 1};

    prodescalar = productoescalar( vector1, vector2, 0, 0 );

    printf( "El producto escalar es: %d.\n", prodescalar );

}

///Cabecera: int vect1[], int vect2[], int cont, int suma
///Precondicion: Se le pasan 2 vectores de la misma condicion, un contador para calcular la posicion del vector y suma para calcular en cada pasada el producto escalar
///Postcondicion: Calcula el producto escalar de los 2 vectores pasados a la funcion

int productoescalar( int vect1[], int vect2[], int cont, int suma )
{
    if( cont == N )
    {
        return suma;
    }else{
        return productoescalar( vect1, vect2, cont+1, suma+=vect1[cont]*vect2[cont] );
    }
}