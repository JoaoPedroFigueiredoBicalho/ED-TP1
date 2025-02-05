#include "OrdenacaoIndireta.hpp"

int main(int argc, char **argv)
{

	int chave;
	OrdInd_ptr poi = Cria(argv[1]); //criação do array de ponteiros do tamanho necessário

	int indices[poi->num_de_pessoas]; //alocação do array de indices para ordenação indireta

	CarregaArquivo(poi, argv[1], indices);
	for (chave = NOME; chave <= ENDERECO; chave++) // chave rotaciona pelas 3 possíveis
	{
		selectionSort(poi, indices, chave);
		for (int k = 0; k < poi->num_de_pessoas; k++) //loop de impressão das informações
		{
			if (k == 0)
				std::cout << poi[0].introducao;
			std::cout << poi[indices[k]].nome << "," << poi[indices[k]].cpf << "," << poi[indices[k]].end << "," << poi[indices[k]].payload << std::endl;
		}
	}
	for (chave = NOME; chave <= ENDERECO; chave++) // chave rotaciona pelas 3 possíveis
	{
		quickSort(indices, 0, (poi->num_de_pessoas - 1), poi, chave);
		for (int k = 0; k < poi->num_de_pessoas; k++) //loop de impressão das informações
		{
			if (k == 0)
				std::cout << poi[0].introducao;
			std::cout << poi[indices[k]].nome << "," << poi[indices[k]].cpf << "," << poi[indices[k]].end << "," << poi[indices[k]].payload << std::endl;
		}
	}
	for (chave = NOME; chave <= ENDERECO; chave++) // chave rotaciona pelas 3 possíveis
	{
		shellSort(indices, poi->num_de_pessoas, poi, chave);
		for (int k = 0; k < poi->num_de_pessoas; k++) //loop de impressão das informações
		{
			if (k == 0)
				std::cout << poi[0].introducao;
			std::cout << poi[indices[k]].nome << "," << poi[indices[k]].cpf << "," << poi[indices[k]].end << "," << poi[indices[k]].payload << std::endl;
		}
	}

	delete[] poi; // liberação da memória alocada
}
