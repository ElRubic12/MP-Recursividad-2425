#include<stdio.h>
#include<stdlib.h>

int numerodecifras( int numero, int cont, int posicion );

int main()
{
    int num, posicion;
    int cifras;

    printf( "Introduce un numero: " );
    scanf( "%d", &num );

    printf( "Numero: %d.\n", num );

    printf( "Introduce la posicion del numero: " );
    scanf( "%d", &posicion );

    cifras = numerodecifras( num, 1, posicion );

    printf( "El numero es : %d.\n", cifras );

}

///Cabecera: int numero, int cont, int posicion
///Precondicion: Se introduce un numero por pantalla y la posicion de ese numero que se quiere averiguar
///Postcondicion: Devuelve el numero que se encuentra en la posicion introducida

int numerodecifras( int numero, int cont, int posicion )
{
    if( posicion == cont )
    {
        return numero % 10;
    }else{
        return numerodecifras( numero/10, cont+1, posicion );
    }
}