#ifndef ORDENACAOINDIRETA_H
#define ORDENACAOINDIRETA_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

// definicoes de chaves a serem usadas
#define NOME 1
#define CPF 2
#define ENDERECO 3

typedef struct OrdInd
{
	int num_de_pessoas;
	std::string nome;
	std::string introducao;
	std::string cpf;
	std::string end;
	std::string payload;

} OrdInd_t, *OrdInd_ptr;

void troca(int *x, int *y);
void selectionSort(const OrdInd_ptr poi, int indices[], int chave);
int particao(const OrdInd_ptr poi, int indices[], int esquerda, int direita, int chave);
void quickSort(int indices[], int esquerda, int direita, const OrdInd_ptr poi, int chave);
OrdInd_ptr Cria(const char *nomeDoArquivo);
void CarregaArquivo(OrdInd_ptr poi, const char *nomeDoArquivo, int *indices);
void shellSort(int *indices, int tamanho, OrdInd_ptr poi, int chave);

#endif
