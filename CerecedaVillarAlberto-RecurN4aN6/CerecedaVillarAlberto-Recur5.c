#include<stdio.h>
#include<string.h>

#define TAM 6

int contarparejas( int vector[], int cont, int encontrado );

int main()
{
    int vector[TAM] = {5, 3, 6, 4, 5, 5};
    int resultado;

    resultado = contarparejas( vector, 0, 1 );

    if( resultado == 0 )
    {
        printf( "Se ha encontrado al menos 2 parejas consecutivas que suman lo mismo.\n" ); 
    }else{
        printf( "No se ha encontrado ninguna pareja consecutiva que sumen lo mismo.\n" );
    }

}

///Cabecera: int v[], int cont, int encontrado
///Precondicion: Recibe un vector, un contador para recorrer el vector y una variable que controla si se ha encontrado 2 parejas consecutivas que sumen lo mismo
///Postcondicion: Devuelve 0 si ha encontrado una pareja consecutiva que sume lo mismo y 1 si no la ha encontrado

int contarparejas( int v[], int cont, int encontrado )
{
    if( cont > TAM/2 )
    {
        if( encontrado == 0 )
        {
            return 0;
        }else{
            return 1;
        }
    }else{

        if( v[cont]+v[cont+1] == v[cont+2]+v[cont+3] )
        {
            printf( "Aqui entra: %d, %d.\n", v[cont]+v[cont+1], v[cont+2]+v[cont+3] );
            return 0;
        }else{
            return contarparejas( v, cont+1, 1 );
        }

    }
}