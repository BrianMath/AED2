#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED


// Includes
#include <stdio.h>
#include <stdlib.h>

// Structs
typedef struct noFila {
	int valor;
	struct noFila* proximo;
} NoFila;

typedef struct fila {
	NoFila* inicio;
} Fila;

// Métodos
Fila* criarFila();
NoFila* criarNoFila(int valor);
void adicionarNoFila(Fila* head, int valor);
int removeNoFila(Fila* head);


#endif // FILA_H_INCLUDED