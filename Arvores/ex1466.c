#include <stdio.h>
#include <stdlib.h>

// Structs - árvore
typedef struct no {
	int valor;
	struct no* left;
	struct no* right;
} No;

typedef struct raiz {
	No* inicio;
} Raiz;

// Structs - fila
typedef struct no_fila {
	int valor;
	struct no_fila* next;
} No_fila;

typedef struct cabeca {
	No_fila* inicio;
} Cabeca;

// Métodos - árvore
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

void printBreadthOrder(Raiz* root, Cabeca* head) {
	
}

void apagarArvore(No* inicio) {
	if (inicio != NULL) {
		apagarArvore(inicio->left);
		apagarArvore(inicio->right);
		free(inicio);
	}
}

// Métodos - fila
Cabeca* criarFila() {
	Cabeca* head = (Cabeca*) calloc(1, sizeof(Cabeca));

	head->inicio = NULL;

	return head;
}

No_fila* criarNo_fila(int valor) {
	No_fila* node = (No_fila*) calloc(1, sizeof(No_fila));

	node->valor = valor;
	node->next = NULL;

	return node;
}

void adicionarNo_fila(Cabeca* head, int valor) {
	if (head == NULL) {
		exit(-1);
	}

	No_fila* node = criarNo_fila(valor);
	
	if (head->inicio == NULL) {
		head->inicio = node;

		return;
	}

	No_fila* aux = head->inicio;

	while (aux->next != NULL) {
		aux = aux->next;
	}
	
	aux->next = node;
}

No_fila* apagarNo_fila(Cabeca* head) {
	if (head == NULL || head->inicio == NULL) {
		exit(-1);
	}
	
	No_fila* aux = head->inicio;
	int valor = aux->valor;

	aux = aux->next;
	free(head->inicio);
	head->inicio = NULL;

	if (aux != NULL) {
		head->inicio = aux;
	}

	return valor;
}


int main() {
	int qtdTestes, qtdNos;
	int todosNos[501];

	scanf("%d", &qtdTestes);

	for (int i = 1; i <= qtdTestes; i++) {
		Raiz* root = criarRaiz();
		Cabeca* head = criarFila();

		scanf("%d", &qtdNos);

		for (int j = 0; j < qtdNos; j++) {
			scanf("%d", &todosNos[j]);
		}

		for (int j = 0; j < qtdNos; j++) {
			adicionarNo(root, todosNos[j]);
		}
		
		printf("Case %d:\n", i);
		printBreadthOrder(root, head);

		printf("\n\n");

		apagarArvore(root->inicio);
	}

	return 0;
}