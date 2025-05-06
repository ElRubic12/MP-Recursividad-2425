#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int funcionmatrizsimetrica( int **m, int n, int repeticiones, int i, int j, int cont, int contsim );

int main()
{
    int n, first;
    int i, j;
    int sin_diagonal, division, repeticiones;

    printf( "Introduce la dimension de la matriz cuadrada(n): " );          ///Solicita dimension de la matriz
    scanf( "%d", &n );


    int **matriz = (int **)malloc( n * sizeof(int *) );             ///Tamaño de la matriz definido de forma dinamica
    for( i = 0; i < n; i++ )
    {
        matriz[i] = (int *)malloc( n * sizeof(int) );
    }

    printf( "Introduce el valor de la primera posicion de la matriz(0-0): " );      ///Solicita primera posicion
    scanf( "%d", &first );

    matriz[0][0] = first;                                       ///Inicializa la primera posicion con el valor introducido

    ///Numero maximo de bucles
    sin_diagonal = (n * n) - n;
    division = sin_diagonal / 2;
    repeticiones = division + n;                ///Variable que controla el numero de veces que se recorre la matriz para inicializar la diagonal inferior


    funcionmatrizsimetrica( matriz, n, repeticiones, 0, 0, 0, 1 );        ///Llamada a la funcion





    printf( "Funcion Simetrica Generada:\n" );                  ///Funcion simetrica generada en la funcion recursiva
    for( i = 0; i < n; i++ ){
        for( j = 0; j < n; j++ ){
            printf( "%5d", matriz[i][j] );
        }
        printf( "\n" );
    }

    system( "pause" );

}

///Cabecera: int **m, int n, int first, int rep, int i, int j, int cont, int contsim
///Precondicion: Se le pasa la matriz con la primera posicion inicializada, la dimension de la matriz, el numero maximo de veces que se va a llamar a la funcion,
///              el iterador i para las filas, el iterador j para las columnas, el numero de veces que se ha llamado a la funcion y una variable contador para
///              conmutar los valores de abajo de la diagonal por los valores de la derecha de la diagonal de la posicion actual de la diagonal
///Postcondicion: Devuelve una matriz con las dimensiones especificada antes de llamar a la funcion, a la que se ha generado su diagonal inferior de manera recursiva

int funcionmatrizsimetrica( int **m, int n, int rep, int i, int j, int cont, int contsim )
{
    if( cont == rep+n-1 )        ///CASO BASE: Se ha recorrido la matriz una serie de veces para generar la diagonal inferior y una serie de veces para generar la matriz simetrica
    {
        return 0;

    }else{

        if( cont < rep )            ///CASO BASE: Situacion para generar la diagonal inferior
        {
            if( j <= i )            ///Se recorre solo la diagonal inferior(desde 0 hasta i para cada fila)
            {
                if( i == 0 && j == 0 )      ///Caso del primer valor de la matriz(posicion 0-0) porque se define al momento de la creacion de la matriz
                {
                    return funcionmatrizsimetrica( m, n, rep, i+=1, 0, cont+=1, 1 );
                }else{                      ///Caso para el resto de valores desde 1-0 hasta n-n
                    if( j == 0 )            ///Para el primer valor de cada fila se recupera el valor de la diagonal de la fila anterior
                    {
                        m[i][j] = m[i-1][i-1];

                        return funcionmatrizsimetrica( m, n, rep, i, j+=1, cont+=1, 1 );
                    }else{                  ///Para el resto de valores de cada fila(entre el segundo valor de cada fila y la diagonal)
                        if( cont == rep-1 )         ///Caso en el que inicializa la ultima posicion de la matriz(n-n) e inicializa i y j a 0 para generar la matriz simetrica
                        {
                            m[i][j] = m[i][j-1] + m[i-1][j-1];

                            return funcionmatrizsimetrica( m, n, rep, 0, 0, cont+=1, 1 );
                        }else{                      ///Caso en el se inicializan todas las posiciones de la diagonal inferior mientras no sea la ultima posicion de la matriz
                            m[i][j] = m[i][j-1] + m[i-1][j-1];

                            return funcionmatrizsimetrica( m, n, rep, i, j+=1, cont+=1, 1 );
                        }
                    }
                }

            }else{              ///Caso en el que la fila que se esta recorriendo actualmente supere la diagonal
                return funcionmatrizsimetrica( m, n, rep, i+=1, 0, cont, 1 );
            }

        }else{                  ///Situacion para generar la matriz simetrica a partir de la diagonal inferior

            if( i < n-1 )         ///CASO BASE: se recorre la matriz mientras no se haya recorrido toda la diagonal
            {
                if( contsim < n-i )         ///Se van a sustituir los valores de las posiciones que estan debajo de la diagonal actual, por los valores de las posiciones que estan a la derecha de la diagonal actual
                {
                    m[i][j+contsim] = m[i+contsim][j];

                    return funcionmatrizsimetrica( m, n, rep, i, j, cont, contsim+=1 );
                }else{      ///Hasta que se haya sustituido todos los valores de las posiciones que estan debajo de la diagonal de la posicion actual, luego se situa en el valor de la siguiente diagonal
                    return funcionmatrizsimetrica( m, n, rep, i+=1, j+=1, cont+=1, 1 );
                }
            }else{          ///Si i es igual al valor de la dimension menos 1, ya que la ultima posicion no tiene filas a la derecha, termina el programa
                return funcionmatrizsimetrica( m, n, rep, i, j, cont+=1, contsim );
            }

        }

    }
}