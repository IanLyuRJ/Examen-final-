#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANIO 30
#define REPETICIONES 10000 //Esto es para que se repita la multiplicacion en el mismo bucle de tiempo, luego lo dividimos y sacamos el promedio de tiempo, esto porque si no me daba 0.00000 :( 

void llenarMatriz(int matriz[TAMANIO][TAMANIO]) {
    for (int i = 0; i < TAMANIO; i++) {
        for (int j = 0; j < TAMANIO; j++) {
            matriz[i][j] = rand() % 10;
        }
    }
}

void imprimirMatriz(int matriz[TAMANIO][TAMANIO]) {
    for (int i = 0; i < TAMANIO; i++) {
        for (int j = 0; j < TAMANIO; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void multiplicarMatrices(int matriz1[TAMANIO][TAMANIO], int matriz2[TAMANIO][TAMANIO], int resultado[TAMANIO][TAMANIO]) {
    for (int i = 0; i < TAMANIO; i++) {
        for (int j = 0; j < TAMANIO; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < TAMANIO; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}

int main() {
    int matriz1[TAMANIO][TAMANIO], matriz2[TAMANIO][TAMANIO], resultado[TAMANIO][TAMANIO];
    clock_t inicio, fin;
    double tiempo_usado;

    srand(time(NULL));

    llenarMatriz(matriz1);
    llenarMatriz(matriz2);

    printf("Matriz 1:\n");
    imprimirMatriz(matriz1);
    printf("\nMatriz 2:\n");
    imprimirMatriz(matriz2);

    inicio = clock();
    for (int i = 0; i < REPETICIONES; i++) {
        multiplicarMatrices(matriz1, matriz2, resultado);
    }
    fin = clock();

    tiempo_usado = ((double) (fin - inicio)) / CLOCKS_PER_SEC / REPETICIONES * 1000.0;

    printf("\nResultado de la multiplicacion:\n");
    imprimirMatriz(resultado);

    printf("\nTiempo de ejecucion promedio por multiplicacion: %lf milisegundos\n", tiempo_usado);

    return 0;
}

