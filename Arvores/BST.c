#include <stdio.h>
#include <stdlib.h>
#include "BST.h"


void print(char* texto) {
	printf("%s\n", texto);
}


int main() {
	Raiz* root = criarRaiz();
	int opcao;

	while (1) {
		while (2) {
			print("-------------------------");
			print(" Árvore Binária de Busca ");
			print("-------------------------");
			print("1) Inserir valor");
			print("2) Imprimir árvore");
			print("3) Ver altura da árvore");
			print("4) Fechar programa");

			printf("Sua opção: ");
			scanf("%d", &opcao);

			if (opcao < 1 || opcao > 4) {
				system(CLEAR_COMMAND);
				print("OPÇÃO INVÁLIDA! Digite novamente!\n");
			} else {
				break;
			}
		}

		if (opcao == 1) {
			int valor, deuCerto;

			printf("Valor para inserir: ");
			scanf("%d", &valor);
			deuCerto = adicionarNo(root, valor);

			system(CLEAR_COMMAND);
			if (deuCerto) {
				printf("Valor %d inserido com sucesso!\n", valor);
			} else {
				print("Valor já estava inserido!");
			}
		}

		else if (opcao == 2) {
			while (2) {
				print("   > ---------------------");
				print("   >  Opções de impressão ");
				print("   > ---------------------");
				print("   > 1) Todas as opções");
				print("   > 2) Preorder");
				print("   > 3) Inorder");
				print("   > 4) Postorder");

				scanf("%d", &opcao);

				if (opcao < 1 || opcao > 4) {
					system(CLEAR_COMMAND);
					print("OPÇÃO INVÁLIDA! Digite novamente!\n");
				} else {
					break;
				}
			}

			system(CLEAR_COMMAND);			

			switch (opcao) {
			case 1:
				printf("Preorder: ");
				printPreorder(root->inicio);
				break;
			
			case 2:
				printf("Inorder: ");
				printInorder(root->inicio);
				break;
			
			case 3:
				printf("Postorder: ");
				printPostorder(root->inicio);
				break;
			
			case 4:
				printf("Preorder:  ");
				printPreorder(root->inicio);

				printf("\nInorder:   ");
				printInorder(root->inicio);

				printf("\nPostorder: ");
				printPostorder(root->inicio);
				break;
			
			default:
				break;
			}
		}
		
		else if (opcao == 3) {
			int altura = alturaArvore(root->inicio);

			system(CLEAR_COMMAND);
			printf("Altura da árvore: %d\n", altura);
		}
		
		else if (opcao == 4) {
			apagarArvore(root->inicio);
			break;
		}

		print("\n");
	}

	return 0;
}