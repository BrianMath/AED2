#include <stdio.h>
#include <stdlib.h>

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

void printPreorder(No* inicio) {
	if (inicio != NULL) {
		printf(" %d", inicio->valor);
		printPreorder(inicio->left);
		printPreorder(inicio->right);
	}
}

void printInorder(No* inicio) {
	if (inicio != NULL) {
		printInorder(inicio->left);
		printf(" %d", inicio->valor);
		printInorder(inicio->right);
	}
}

void printPosorder(No* inicio) {
	if (inicio != NULL) {
		printPosorder(inicio->left);
		printPosorder(inicio->right);
		printf(" %d", inicio->valor);
	}
}

void apagaArvore(No* inicio) {
	if (inicio != NULL) {
		apagaArvore(inicio->left);
		apagaArvore(inicio->right);
		free(inicio);
	}
}


int main() {
	int qtdTestes, qtdNos;
	int todosNos[501];

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
		
		printf("Case %d:\n", i);
		printf("Pre.:");
		printPreorder(root->inicio);
		printf("\nIn..:");
		printInorder(root->inicio);
		printf("\nPost:");
		printPosorder(root->inicio);

		printf("\n\n");

		apagaArvore(root->inicio);
	}
	

	return 0;
}