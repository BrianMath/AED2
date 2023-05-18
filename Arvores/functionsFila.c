#include "fila.h"

Fila* criarFila() {
	Fila* head = (Fila*) calloc(1, sizeof(Fila));

	if (head == NULL) {
		return NULL;
	}
	
	head->inicio = NULL;

	return head;
}

NoFila* criarNoFila(int valor) {
	NoFila* node = (NoFila*) calloc(1, sizeof(NoFila));

	if (node == NULL) {
		return NULL;
	}
	
	node->valor = valor;
	node->proximo = NULL;

	return node;
}

void adicionarNoFila(Fila* head, int valor) {
	if (head == NULL) {
		return;
	}

	NoFila* node = criarNoFila(valor);

	if (head->inicio == NULL) {
		head->inicio = node;
		return;
	}

	NoFila* aux = head->inicio;
	
	while (aux->proximo != NULL) {
		aux = aux->proximo;
	}

	aux->proximo = node;
}

int removeNoFila(Fila* head) {
	if (head == NULL) {
		return -1;
	}

	NoFila* aux = head->inicio;
	int valor = aux->valor;

	head->inicio = head->inicio->proximo;
	free(aux);

	return valor;
}
