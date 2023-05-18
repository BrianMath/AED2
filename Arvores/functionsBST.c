#include "BST.h"

Raiz* criarRaiz() {
	Raiz* root = (Raiz*) calloc(1, sizeof(Raiz));

	root->inicio = NULL;

	return root;
}

No* criarNo(int valor) {
	No* node = (No*) calloc(1, sizeof(No));

	if (node == NULL) {
		return NULL;
	}

	node->valor = valor;
	node->esquerda = NULL;
	node->direita = NULL;
	node->altura = 0;

	return node;
}

int adicionarNo(Raiz* root, int valor) {
	if (root == NULL) {
		return -1;
	}
	
	if (root->inicio == NULL) {
		root->inicio = criarNo(valor);

		return 1;
	}
	
	No* anterior = root->inicio;
	No* atual = anterior;

	while (1) {
		// Esquerda == valor menor
		if (valor < atual->valor) {
			// Esquerda vazia
			if (atual->esquerda == NULL) {
				atual->esquerda = criarNo(valor);
				return 1;
			}
			
			anterior = atual;
			atual = atual->esquerda;
			continue;
		}
		// Direita == valor maior
		else if (valor > atual->valor) {
			// Direita vazia
			if (atual->direita == NULL) {
				atual->direita = criarNo(valor);
				return 1;
			}
			
			anterior = atual;
			atual = atual->direita;
			continue;
		}
		// Igual
		else {
			printf("O valor informado já está na raiz!\n\n");
			return 0;
		}
	}
}

int alturaArvore(No* inicio) {
	if (inicio == NULL) {
		return -1;
	}
	else {
		int valorEsquerda = alturaArvore(inicio->esquerda);
		int valorDireita = alturaArvore(inicio->direita);

		if (valorEsquerda > valorDireita) {
			return valorEsquerda + 1;
		} else {
			return valorDireita + 1;
		}
	}
}

void printPreorder(No* inicio) {
	if (inicio != NULL) {
		printf("%d ", inicio->valor);
		printPreorder(inicio->esquerda);
		printPreorder(inicio->direita);
	}
}

void printInorder(No* inicio) {
	if (inicio != NULL) {
		printInorder(inicio->esquerda);
		printf("%d ", inicio->valor);
		printInorder(inicio->direita);
	}
}

void printPostorder(No* inicio) {
	if (inicio != NULL) {
		printPostorder(inicio->esquerda);
		printPostorder(inicio->direita);
		printf("%d ", inicio->valor);
	}
}

void apagarArvore(No* inicio) {
	if (inicio != NULL) {
		apagarArvore(inicio->esquerda);
		apagarArvore(inicio->direita);
		free(inicio);
	}
}