/* Algoritmos y Programación — ejercicio de examen

 Dado un array de 10(diez) enteros en el rango [100 a 999] (validar esto), los cuales deben ser ingresados manualmente, se solicita crear las siguientes funciones:

a) greater_distance devuelve el valor de la máxima distancia que separa a dos números cualesquiera presentes en el array (2 Puntos)

b) sum_mults recibe el array y un entero d en [2,10], retorna la suma de los elementos del array que son múltiplos de d (2 Puntos)

even_odd recibe el array y lo modifica colocando primero los pares y luego impares, no importa orden creciente o decreciente (2 Puntos)*/

#include <stdio.h>

int greater_distance(int arr[], int size) {
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return max - min;
}   

int sum_mults(int arr[], int size, int d) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % d == 0) {
            sum += arr[i];
        }
    }

    return sum;
}

void even_odd(int arr[], int size) { // Particiona en el lugar (O(n), memoria O(1)): dos índices que avanzan desde los extremos
    int left = 0;
    int right = size - 1;

    while (left < right) {
        while (left < right && arr[left] % 2 == 0) {
            left++;
        }
        while (left < right && arr[right] % 2 != 0) {
            right--;
        }
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

int main() {
    int arr[10];
    int size = 10;
    int d;

    // Ingreso de los elementos del array
    for (int i = 0; i < size; i++) {
        do {
            printf("Ingrese un número entero en el rango [100, 999] para el elemento %d: ", i + 1);
            if (scanf("%d", &arr[i]) != 1) return 1;   // entrada no numérica o EOF
        } while (arr[i] < 100 || arr[i] > 999);
    }

    // Llamada a greater_distance
    int max_distance = greater_distance(arr, size);
    printf("La máxima distancia entre dos números es: %d\n", max_distance);

    // Ingreso del valor d
    do {
        printf("Ingrese un entero d en el rango [2, 10]: ");
        if (scanf("%d", &d) != 1) return 1;
    } while (d < 2 || d > 10);

    // Llamada a sum_mults
    int sum = sum_mults(arr, size, d);
    printf("La suma de los elementos múltiplos de %d es: %d\n", d, sum);

    // Llamada a even_odd
    even_odd(arr, size);
    printf("Array modificado con pares primero y luego impares:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
