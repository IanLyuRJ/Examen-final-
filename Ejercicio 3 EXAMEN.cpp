#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANIO 50000
#define NUM_EJECUCIONES 100

void generarArregloOrdenado(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

int busquedaSecuencial(int arr[], int n, int clave) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == clave) {
            return i;
        }
    }
    return -1;
}

int busquedaBinaria(int arr[], int izquierda, int derecha, int clave) {
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arr[medio] == clave) {
            return medio;
        }
        if (arr[medio] < clave) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    return -1;
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
    int arr[TAMANIO];
    double tiemposSecuencial[NUM_EJECUCIONES], tiemposBinario[NUM_EJECUCIONES];
    clock_t inicio, fin;

    srand(time(NULL));
    generarArregloOrdenado(arr, TAMANIO);

   
    for (int i = 0; i < NUM_EJECUCIONES; i++) {
        int clave = rand() % TAMANIO;
        inicio = clock();
        busquedaSecuencial(arr, TAMANIO, clave);
        fin = clock();
        tiemposSecuencial[i] = ((double) (fin - inicio)) / CLOCKS_PER_SEC * 1000;
    }
    printf("Busqueda Secuencial:\n");
    imprimirEstadisticas(tiemposSecuencial, NUM_EJECUCIONES);

    
    for (int i = 0; i < NUM_EJECUCIONES; i++) {
        int clave = rand() % TAMANIO;
        inicio = clock();
        busquedaBinaria(arr, 0, TAMANIO - 1, clave);
        fin = clock();
        tiemposBinario[i] = ((double) (fin - inicio)) / CLOCKS_PER_SEC * 1000;
    }
    printf("\nBusqueda Binaria:\n");
    imprimirEstadisticas(tiemposBinario, NUM_EJECUCIONES);

    return 0;
}

