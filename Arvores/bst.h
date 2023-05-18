#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED


// Includes
#include <stdio.h>
#include <stdlib.h>

// Macros
#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

// Structs
typedef struct no {
	int valor;
	struct no* esquerda;
	struct no* direita;
	int altura;
} No;

typedef struct raiz {
	No* inicio;
} Raiz;

// Métodos
Raiz* criarRaiz();
No* criarNo(int valor);
int adicionarNo(Raiz* root, int valor);
int alturaArvore(No* inicio);
void printPreorder(No* inicio);
void printInorder(No* inicio);
void printPostorder(No* inicio);
void apagarArvore(No* inicio);


#endif // BST_H_INCLUDED
