# Ejercicios de C y C++

Ejercicios de la carrera de **Analista Universitario en Sistemas** (Taller de Programación I y II), ordenados por tema. Todos compilan sin warnings con `-Wall -Wextra -Werror`.

| Carpeta | Tema | Qué muestra |
|---|---|---|
| [`arrays/`](arrays/arrays.c) | Arreglos | Distancia máxima, suma de múltiplos y partición **pares/impares en el lugar** (O(n) de tiempo, O(1) de memoria) con dos índices |
| [`calculadora/`](calculadora/calculadora.cpp) | C++ y strings | Parseo de una expresión (`9x9`, `3+4`, `5/0`) con `std::string`, `std::stod` y manejo de errores |
| [`memoria-dinamica/`](memoria-dinamica/leer_cadena.c) | `malloc` / `realloc` | Lectura de una línea de largo arbitrario, con capacidad que se duplica y `realloc` seguro (sin perder el bloque si falla) |
| [`estructuras/`](estructuras/punto.c) | `struct` y punteros | Estructura `Punto`, arreglo dinámico y aritmética de punteros |

## Compilar

Requiere `gcc`, `g++` y `make` (en Windows: WSL o MSYS2).

```bash
make          # compila todo en bin/
./bin/arrays
./bin/calculadora
./bin/leer_cadena
./bin/punto
make clean
```

Los programas que usan memoria dinámica se verificaron con `valgrind --leak-check=full`, sin pérdidas.

## Otros proyectos

- [Simulador de enrutamiento con Dijkstra](https://github.com/facusenn/simulador-enrutamiento-dijkstra) — C modular, 64 tests, min-heap
- [Lights Out](https://github.com/facusenn/lights-out-c) — juego de consola en C
