CC      = gcc
CXX     = g++
CFLAGS  = -std=c11 -Wall -Wextra -Werror
CXXFLAGS= -std=c++17 -Wall -Wextra -Werror
BIN     = bin

all: $(BIN)/arrays $(BIN)/calculadora $(BIN)/leer_cadena $(BIN)/punto

$(BIN):
	mkdir -p $(BIN)

$(BIN)/arrays: arrays/arrays.c | $(BIN)
	$(CC) $(CFLAGS) $< -o $@
$(BIN)/calculadora: calculadora/calculadora.cpp | $(BIN)
	$(CXX) $(CXXFLAGS) $< -o $@
$(BIN)/leer_cadena: memoria-dinamica/leer_cadena.c | $(BIN)
	$(CC) $(CFLAGS) $< -o $@
$(BIN)/punto: estructuras/punto.c | $(BIN)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BIN)

.PHONY: all clean
