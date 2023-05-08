#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs
typedef struct no {
	int valor;
	struct no* left;
	struct no* right;
} No;

typedef struct raiz {
	No* inicio;
} Raiz;

// Métodos
Raiz* criarRaiz() {
	Raiz* root = (Raiz*) calloc(1, sizeof(Raiz));

	root->inicio = NULL;

	return root;
}

No* criarNo(int valor) {
	No* node = (No*) calloc(1, sizeof(No));

	node->valor = valor;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void adicionarNo(Raiz* root, int valor) {
	if (root == NULL) {
		exit(-1);
	}

	No* node = criarNo(valor);
	
	if (root->inicio == NULL) {
		root->inicio = node;

		return;
	}
	
	No* anterior = root->inicio;
	No* atual = anterior;

	while (1) {
		// Esquerda
		if (valor < atual->valor) {
			if (atual->left == NULL) {
				atual->left = criarNo(valor);
				break;
			}
			
			anterior = atual;
			atual = atual->left;
			continue;
		}
		// Direita
		else if (valor > atual->valor) {
			if (atual->right == NULL) {
				atual->right = criarNo(valor);
				break;
			}
			
			anterior = atual;
			atual = atual->right;
			continue;
		}
		// Igual
		else {
			break;
		}
	}
}

void apagaArvore(No* inicio) {
	if (inicio != NULL) {
		apagaArvore(inicio->left);
		apagaArvore(inicio->right);
		free(inicio);
	}
}

void append(int fila[], int valor) {
	int i = 0;

	while (fila[i] != '\0') {
		i++;
	}
	
	fila[i] = valor;
}

void printBreadthSearch(No* inicio) {
	if (inicio != NULL) {
		
	}
}


int todosNos[501];

int main() {
	int qtdTestes, qtdNos;

	scanf("%d", &qtdTestes);

	for (int i = 1; i <= qtdTestes; i++) {
		Raiz* root = criarRaiz();
		scanf("%d", &qtdNos);

		for (int j = 0; j < qtdNos; j++) {
			scanf("%d", &todosNos[j]);
		}

		for (int j = 0; j < qtdNos; j++) {
			adicionarNo(root, todosNos[j]);
		}

		memset(todosNos, 0, sizeof(todosNos));
		
		printf("Case %d:\n", i);
		printBreadthSearch(root->inicio);
		printf("\n\n");

		apagaArvore(root->inicio);
	}
	

	return 0;
}