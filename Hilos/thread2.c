#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int m= 0;
int n = 0;

void contar(int **a)
{
    int count2 = 0;
    int **matriz2 = **a;
    printf("\nSe encontro %d veces el numero 3 con HILOs\n\n", count2);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (matriz2[i][j] == 3)
            {
                count2++;
            }
        }
    }
   // printf("\nSe encontro %d veces el numero 3 con HILOs\n\n", count2);
}


int **matriz;


int main(int argc, char *argv[])
{
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    printf("Ejercicio 1 Hilos\n");

    
    int count = 0;

    // Se reservan las filas
    matriz = malloc(atoi(argv[1]) * sizeof(int *));

    // Comprueba que tengamos memoria, si no se tiene mallo retorna NULL
    if (matriz == NULL)
    {
        printf("No se dispone de memoria suficiente\n");
        exit(1);
    }

    for (int i = 0; i < atoi(argv[1]); i++)
    {
        // Se reserva espacio para cada columna en una fila
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

    // Un solo Hilo Secuencial
    printf("\nSe encontro %d veces el numero 3\n\n", count);

    // Hilos concurrentes
    pthread_t *hilo;

    hilo = malloc(atoi(argv[3]) * sizeof(pthread_t));

    for (int i = 0; i < atoi(argv[3]); i++)
    {
        pthread_create(&hilo[i], NULL, (void *)contar, (void *)&matriz);
    }

    for(int i = 0; i<atoi(argv[3]);i++){
        pthread_join(hilo[i], NULL);
    }

    printf("\n\nFin del Programa\n\n");
    return 0;
}