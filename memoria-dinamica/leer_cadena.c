// Lectura de una cadena de largo arbitrario con memoria dinámica (malloc/realloc).
#include <stdio.h>
#include <stdlib.h>

// Lee una línea completa de stdin. La capacidad arranca en 10 y se duplica
// cada vez que se llena. Quien llama debe liberar el resultado con free().
char *leer_cadena(void) {
    size_t longitud = 0;
    size_t capacidad = 10;
    char *cadena = malloc(capacidad);
    if (cadena == NULL) {
        fprintf(stderr, "Error al asignar memoria.\n");
        exit(1);
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (longitud + 1 >= capacidad) {
            capacidad *= 2;
            // Se usa un puntero auxiliar: si realloc falla, el bloque original sigue siendo válido.
            char *nueva = realloc(cadena, capacidad);
            if (nueva == NULL) {
                free(cadena);
                fprintf(stderr, "Error al reasignar memoria.\n");
                exit(1);
            }
            cadena = nueva;
        }
        cadena[longitud++] = (char)c;
    }
    cadena[longitud] = '\0';
    return cadena;
}

int main(void) {
    printf("Ingrese una cadena de caracteres: ");
    char *texto = leer_cadena();
    printf("Leiste: \"%s\"\n", texto);
    free(texto);
    return 0;
}
