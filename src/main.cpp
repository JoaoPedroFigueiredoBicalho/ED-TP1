#include "OrdenacaoIndireta.hpp"

int main(int argc, char **argv)
{

	if (argc < 2)
	{
		std::cerr << "Erro: o nome do arquivo não foi fornecido!" << std::endl;
		return 1; // Return an error code
	}

	int chave;
	auto start = high_resolution_clock::now();
	OrdInd_ptr poi = Cria(argv[1]);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	std::cout << "criar array: " << duration.count() << " nanoseconds" << std::endl
			  << std::endl;

	int indices[poi->num_de_pessoas];

	auto start2 = high_resolution_clock::now();
	CarregaArquivo(poi, argv[1], indices);
	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
	std::cout << "carregar arquivo: " << duration2.count() << " nanoseconds" << std::endl
			  << std::endl;
	/*
	for (chave = NOME; chave <= ENDERECO; chave++) // chave rotaciona pelas 3 possíveis
	{
		selectionSort(poi, indices, chave);
		for (int k = 0; k < poi->num_de_pessoas; k++)
		{
			if (k == 0)
				std::cout << poi[0].introducao;
			std::cout << poi[indices[k]].nome << "," << poi[indices[k]].cpf << "," << poi[indices[k]].end << "," << poi[indices[k]].payload << std::endl;
		}
	}
	for (chave = NOME; chave <= ENDERECO; chave++)
	{
		quickSort(indices, 0, (poi->num_de_pessoas - 1), poi, chave);
		for (int k = 0; k < poi->num_de_pessoas; k++)
		{
			if (k == 0)
				std::cout << poi[0].introducao;
			std::cout << poi[indices[k]].nome << "," << poi[indices[k]].cpf << "," << poi[indices[k]].end << "," << poi[indices[k]].payload << std::endl;
		}
	}
	for (chave = NOME; chave <= ENDERECO; chave++)
	{
		shellSort(indices, poi->num_de_pessoas, poi, chave);
		for (int k = 0; k < poi->num_de_pessoas; k++)
		{
			if (k == 0)
				std::cout << poi[0].introducao;
			std::cout << poi[indices[k]].nome << "," << poi[indices[k]].cpf << "," << poi[indices[k]].end << "," << poi[indices[k]].payload << std::endl;
		}
	}
*/
	auto start3 = high_resolution_clock::now();
	for (chave = NOME; chave <= ENDERECO; chave++) // chave rotaciona pelas 3 possíveis
	{
		selectionSort(poi, indices, chave);
	}
	auto stop3 = high_resolution_clock::now();
	auto duration3 = duration_cast<nanoseconds>(stop3 - start3);
	std::cout << "selection: " << duration3.count() << " nanoseconds" << std::endl
			  << std::endl;

	auto start4 = high_resolution_clock::now();
	for (chave = NOME; chave <= ENDERECO; chave++)
	{
		quickSort(indices, 0, (poi->num_de_pessoas - 1), poi, chave);
	}
	auto stop4 = high_resolution_clock::now();
	auto duration4 = duration_cast<nanoseconds>(stop4 - start4);
	std::cout << "quickSort: " << duration4.count() << " nanoseconds" << std::endl
			  << std::endl;

	auto start5 = high_resolution_clock::now();
	for (chave = NOME; chave <= ENDERECO; chave++)
	{
		shellSort(indices, poi->num_de_pessoas, poi, chave);
	}
	auto stop5 = high_resolution_clock::now();
	auto duration5 = duration_cast<nanoseconds>(stop5 - start5);
	std::cout << "shellSort: " << duration5.count() << " nanoseconds" << std::endl
			  << std::endl;

	delete[] poi;
}
