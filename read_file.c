#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
** Thiago André Cardoso Silva
** Aulas particulares de programação (para iniciantes)
** Instagram: @programador_who
** Cel: (085) 999273805
*/

int main(int argc, char const *argv[]) {
	/**
	* Cria um ponteiro para um arquivo
	*/
	FILE *fp;

	/**
	* fopen (arquivo que será aberto, tipo de abertura: r = read (leitura))
	*/
	fp = fopen("./teste.txt", "r");

	/**
	* Verifica se ocorreu erro ao ler arquivo
	*/
	if(fp == NULL){
		printf("Não foi possível abrir o Arquivo para leitura\n");
		return -1;
	}

	/**
	* A função "do while" irá ler caractere por caractere do arquivo
	* até chegar ao final (EOF = fim de arquivo)
	*/
	char ch;
	do {
		ch = getc(fp); // pega 1 caractere por vez
		printf("%c",ch);
		printf("-");
	} while (ch != EOF);

	printf("\n");
	fclose(fp);

	return 0;
}
