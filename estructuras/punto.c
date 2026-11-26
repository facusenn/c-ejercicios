// Estructuras: un Punto en el plano y un arreglo de puntos en memoria dinámica.
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x, y;
} Punto;

int main(void) {
    Punto origen = {0.0, 0.0};
    printf("Punto: (%.2f, %.2f)\n", origen.x, origen.y);

    const int cantidad = 3;
    Punto *puntos = malloc(sizeof(Punto) * cantidad);
    if (puntos == NULL) {
        fprintf(stderr, "Error al asignar memoria.\n");
        return 1;
    }
    for (int i = 0; i < cantidad; i++) {
        (puntos + i)->x = i * 1.5;   // aritmética de punteros, equivalente a puntos[i].x
        (puntos + i)->y = i * 2.0;
    }

    printf("Arreglo de puntos:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("(%.2f, %.2f)\n", puntos[i].x, puntos[i].y);
    }
    free(puntos);
    return 0;
}
