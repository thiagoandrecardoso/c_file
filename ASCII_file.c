#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <string.h>
#define LEN_TEXT 100
/**
** Thiago André Cardoso Silva
** Aulas particulares de programação (para iniciantes)
** Instagram: @programador_who
** Cel: (085) 999273805
*/

/**
* Declaração das funções
*/
int escreverTexto();
int converteArrayCharParaArrayIntASCII_writeInFile(char *texto);

FILE *file;

int main(int argc, char const *argv[]) {
  escreverTexto();
  return 0;
}

int escreverTexto(){
  char *texto;
  texto = (char*) malloc(sizeof(char*) * LEN_TEXT);
  if(!texto) return 0;
  printf("Digite o texto: ");
  fgets(texto, LEN_TEXT, stdin);
  int ok = converteArrayCharParaArrayIntASCII_writeInFile(texto);
  printf("OK %d", ok);
  return 0;
}
/**
* 'w' = abre o arquivo somente para escrita no início do arquivo. Apagará o
* conteúdo do arquivo se ele já existir, criará um arquivo novo se não
* existir. (O w vem do inglês write, escrever)
*
* a+ = abre o arquivo para escrita no final do arquivo e leitura.
*
* strlen retorna a quantidade de caracteres de uma string
* Em strlen(texto) - 1, o '-1' retira o 'enter' que é armazenado.
*/
int converteArrayCharParaArrayIntASCII_writeInFile(char *texto){
  file = fopen("ASCII_int.txt", "a+");
  if(file == NULL) {
    file = fopen("ASCII_int.txt", "w");
  }
  if(file == NULL) return 0; // retorna 0 se não for possível abrir o arquivo
  for (size_t i = 0; i < strlen(texto) - 1; i++) {
    if(texto[i] <= 0) return 0;
    fprintf(file,"%d*", texto[i]);
  }
  fclose(file); // fecha o arquivo
  return 1;
}
// rewind(file); volta para o inicio do arquivo.
// !feof enquanto nao chegar no final do arquivo.
