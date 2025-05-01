#include<stdio.h>
#include<string.h>

#define TAM 10

int main()
{
    int  vector[TAM] = {2, 7, 3, 2, 8, 5, 1, 9, 1, 6};

    funcionvector( vector, 0, 0, 0, 0, 0 );
}

int funcionvector( int v[], int i, int cont, int parejas, int suma1, int suma2 )
{
    if( cont == TAM-1 )
    {
        return parejas;
    }else{

        if( suma1 == suma2 )
        {
            return funcionvector( v, i+=1, cont+=1, parejas+=1, 0, 0 );
        }else{

            
        }

    }
}