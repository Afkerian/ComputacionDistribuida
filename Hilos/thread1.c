#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int main(int argc, char *argv[])
{
    printf("Ejercicio 1 Hilos\n");

    int **matriz;
    int count = 0;

    //Se reservan las filas
    matriz = malloc(atoi(argv[1]) * sizeof(int *));

    // Comprueba que tengamos memoria, si no se tiene mallo retorna NULL
    if (matriz == NULL)
    {
        printf("No se dispone de memoria suficiente\n");
        exit(1);
    }

    for (int i = 0; i < atoi(argv[1]); i++)
    {
        //Se reserva espacio para cada columna en una fila
        matriz[i] = malloc(atoi(argv[2]) * sizeof(int *));
        // Comprueba que tengamos memoria, si no se tiene mallo retorna NULL
        if (matriz[i] == NULL)
        {
            printf("No se dispone de memoria suficiente\n");
            exit(1);
        }
    }

    if (matriz == NULL)
    {
        printf("Memoria\n");
        exit(1);
    }

    srandom(atoi(argv[1]));

    for (int i = 0; i < atoi(argv[1]); i++)
    {
        for (int j = 0; j < atoi(argv[2]); j++)
        {
            matriz[i][j] = random() % 10;
        }
    }

    for (int i = 0; i < atoi(argv[1]); i++)
    {
        for (int j = 0; j < atoi(argv[2]); j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    // Contamos cuantas veces se repite un numero.

    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matriz[i][j] == 3)
            {
                count++;
            }
        }
    }

    printf("\nSe encontro %d el numero 3\n\n", count);

    printf("\n\nFin del Programa\n\n");
    return 0;
}