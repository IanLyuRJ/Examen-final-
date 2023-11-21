#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANIO 10000
#define NUM_EJECUCIONES 100 //Esto lo puse para definir el numero de ejecuciones para cada metodo de ordenamiento, osea que tienen que leer el conjunto de datos 100 veces jiji :)


void intercambiar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particion(int arr[], int bajo, int alto) {
    int pivote = arr[alto];
    int i = (bajo - 1);

    for (int j = bajo; j <= alto - 1; j++) {
        if (arr[j] < pivote) {
            i++;
            intercambiar(&arr[i], &arr[j]);
        }
    }
    intercambiar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}


void ordenamientoPorInsercion(int arr[], int n) {
    int i, clave, j;
    for (i = 1; i < n; i++) {
        clave = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = clave;
    }
}


void ordenamientoRapido(int arr[], int bajo, int alto) {
    if (bajo < alto) {
        int pi = particion(arr, bajo, alto);
        ordenamientoRapido(arr, bajo, pi - 1);
        ordenamientoRapido(arr, pi + 1, alto);
    }
}


void ordenamientoDeBurbuja(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)     
        for (int j = 0; j < n - i - 1; j++) 
            if (arr[j] > arr[j + 1])
                intercambiar(&arr[j], &arr[j + 1]);
}


void copiarArreglo(int fuente[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = fuente[i];
    }
}


void generarArregloAleatorio(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; 
    }
}


void imprimirEstadisticas(double tiempos[], int n) {
    double total = 0.0, min = tiempos[0], max = tiempos[0];
    for (int i = 0; i < n; i++) {
        total += tiempos[i];
        if (tiempos[i] < min) min = tiempos[i];
        if (tiempos[i] > max) max = tiempos[i];
    }
    printf("Tiempo Promedio: %f ms\n", total / n);
    printf("Tiempo Minimo: %f ms\n", min);
    printf("Tiempo Maximo: %f ms\n", max);
}

int main() {
    int arr[TAMANIO], arrCopia[TAMANIO];
    double tiempos[NUM_EJECUCIONES];
    clock_t inicio, fin;

    srand(time(NULL));
    generarArregloAleatorio(arr, TAMANIO);


    for (int i = 0; i < NUM_EJECUCIONES; i++) {
        copiarArreglo(arr, arrCopia, TAMANIO);
        inicio = clock();
        ordenamientoPorInsercion(arrCopia, TAMANIO);
        fin = clock();
        tiempos[i] = ((double) (fin - inicio)) / CLOCKS_PER_SEC * 1000;
    }
    printf("Ordenamiento por Insertion Sort:\n");
    imprimirEstadisticas(tiempos, NUM_EJECUCIONES);

    
    for (int i = 0; i < NUM_EJECUCIONES; i++) {
        copiarArreglo(arr, arrCopia, TAMANIO);
        inicio = clock();
        ordenamientoRapido(arrCopia, 0, TAMANIO - 1);
        fin = clock();
        tiempos[i] = ((double) (fin - inicio)) / CLOCKS_PER_SEC * 1000;
    }
    printf("\nOrdenamiento Quick Sort:\n");
    imprimirEstadisticas(tiempos, NUM_EJECUCIONES);

    // Ordenamiento de burbuja (Bubble) :)
    for (int i = 0; i < NUM_EJECUCIONES; i++) {
        copiarArreglo(arr, arrCopia, TAMANIO);
        inicio = clock();
        ordenamientoDeBurbuja(arrCopia, TAMANIO);
        fin = clock();
        tiempos[i] = ((double) (fin - inicio)) / CLOCKS_PER_SEC * 1000;
    }
    printf("\nOrdenamiento de Burbuja:\n");
    imprimirEstadisticas(tiempos, NUM_EJECUCIONES);

    return 0;
}

