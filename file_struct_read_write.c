#include<stdio.h>
#include<stdlib.h>
#include <string.h>
/**
** Thiago André Cardoso Silva
** Aulas particulares de programação (para iniciantes)
** Instagram: @programador_who
** Cel: (085) 999273805
*/

typedef struct{
  char nome[20];
  char endereco[30];
  char cpf[12];
  long int telefone;
  int idade;
}Aluno;

/**
* variáveis globais
*/
FILE *file;
char *path = "alunos.txt";
char *read_type = "w+";

/**
* declaração das funções.
*/
void abrir_arquivp();
void inserir_dados_no_arquivo();
void ler_dados_do_arquivo();
void limpar_arquivo();

int main(int argc, char const *argv[]) {
  abrir_arquivp();
  inserir_dados_no_arquivo();
  ler_dados_do_arquivo();
  limpar_arquivo();
  fclose(file);
  return 0;
}

/**
* Implementação das funções
*/
void abrir_arquivp(){
  file = fopen(path, read_type);
  if(file == NULL) {
    printf("Erro ao abrir o arquivo");
    return;
  }
}

void inserir_dados_no_arquivo(){
  Aluno aluno;
  setbuf(stdin, NULL);
  printf("Digite o nome: ");
  fgets(aluno.nome, 20, stdin);
  printf("Digite o endereço: ");
  fgets(aluno.endereco, 30, stdin);
  printf("Digite o CPF: ");
  fgets(aluno.cpf, 12, stdin);
  printf("Digite a idade: ");
  scanf("%d", &aluno.idade);
  printf("Digite o telefone: ");
  scanf("%lu", &aluno.telefone);
  fprintf(file, "%s%s%s%d%lu", aluno.nome, aluno.endereco, aluno.cpf, aluno.idade, aluno.telefone);
  // if (fwrite(&aluno, sizeof(Aluno), 1, file) != 1) {
  //   printf("erro ao escrever\n");
  // }
}

void ler_dados_do_arquivo(){
  Aluno aluno;
  fscanf(file, "%s%s%s%d%lu", aluno.nome, aluno.endereco, aluno.cpf, &aluno.idade, &aluno.telefone);
  printf("Nome: %s", aluno.nome);
  printf("Endereço: %s", aluno.endereco);
  printf("CPF: %s\n", aluno.cpf);
  printf("Idade: %d\n", aluno.idade);
  printf("Telefone: %lu\n", aluno.telefone);
}

void limpar_arquivo(){
  fclose(fopen(path, read_type));
}
