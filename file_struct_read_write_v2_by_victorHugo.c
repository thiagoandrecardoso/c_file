#include <stdio.h>
#include <stdlib.h>
/**
* versão - repassando o "objeto" struct para o arquivo.
* author - Victor Hugo
* improvements - Thiago André 
*/
typedef struct {
  char nome[20];
  char endereco[30];
  char cpf[13];
  long int telefone;
  int idade;
} Aluno;

void inserir_dados(Aluno *aluno);
void ler_dados(Aluno *aluno, char *path);
void criar_arqv(Aluno *aluno, char *path);

int main(void) {
  // Aluno a1 = {"link", "casa", "123", 665, 12};
  Aluno aluno;
  char *path = "aluno.txt";
  inserir_dados(&aluno);
  criar_arqv(&aluno, path);
  ler_dados(&aluno, path);
  return 0;
}


void inserir_dados(Aluno *aluno) {
  printf("Digite o nome: ");
  fgets(aluno->nome, sizeof(aluno->nome), stdin);
  printf("Digite o endereço: ");
  fgets(aluno->endereco, sizeof(aluno->endereco), stdin);
  printf("Digite o cpf: ");
  fgets(aluno->cpf, sizeof(aluno->cpf), stdin);
  printf("Digite o telefone: ");
  scanf("%ld", &aluno->telefone);
  printf("Digite a idade: ");
  scanf("%d", &aluno->idade);
}

void criar_arqv(Aluno *aluno, char *path) {
  FILE *file = fopen(path, "w+");
  if (file == NULL) {
    printf("ERRO: não foi possivel criar o arquivo!\n");
    return;
  }
  if (fwrite(aluno, sizeof(aluno), 1, file) != 1){
    printf("Erro ao escrever\n");
  }
  fclose(file);
}

void ler_dados(Aluno *aluno, char *path) {
  FILE *file = fopen(path, "r");
  if (file == NULL) {
    printf("ERRO: não foi possivel ler o arquivo!\n");
    return;
  }

  fread(aluno, sizeof(aluno), 1, file);
  printf("\nNome: %sEndereço: %sCPF: %sTelefone: %ld\nIdade: %d\n", aluno->nome, \
  aluno->endereco, aluno->cpf, aluno->telefone, aluno->idade);
  fclose(file);
}
