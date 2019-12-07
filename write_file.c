#include <stdio.h>
#include <stdlib.h>
/**
** Thiago André Cardoso Silva
** Aulas particulares de programação (para iniciantes)
** Instagram: @programador_who
** Cel: (085) 999273805
*/

int main (void) {
	/**
	* Cria um ponteiro para um arquivo
	*/
	FILE *fp;

	/**
	* fopen (arquivo que será aberto, tipo de abertura: w = wrte (escrita))
	* w = Abre o arquivo somente para escrita no início do arquivo. Apagará o
	* conteúdo do arquivo se ele já existir, criará um arquivo novo se não
	* existir.
	*/
	fp = fopen("teste.txt", "w");

	/**
	* Verifica se ocorreu erro ao ler o arquivo
	*/
	if(fp == NULL){
		printf("Não foi possível abrir o Arquivo para escrita\n");
		return -1;
	}

	/*
	* Insere caractere a caractere em um arquivo
	* Digite 0 e enter para encerrar.
	* o '0' não será gravado no arquivo se for digitado enter depois.
	*/
	char ch;
	do {
		ch = getchar();
		if (ch != '0') putc(ch, fp);
	} while (ch != '0');

	// Fecha o arquivo.
	fclose(fp);
	return 0;
}
