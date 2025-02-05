#include "OrdenacaoIndireta.hpp"

void shellSort(int *indices, int tamanho, OrdInd_ptr poi, int chave)
{
	int i, j, temp, h;

	for (h = tamanho / 2; h > 0; h /= 2)
	{
		for (i = h; i < tamanho; ++i)
		{
			temp = indices[i];

			for (j = i; j >= h; j -= h)
			{
				switch (chave)
				{
				case NOME:
					if (poi[indices[j - h]].nome > poi[temp].nome)
					{
						troca(&indices[j], &indices[j - h]);
					}
					else
					{
						break;
					}
					break;
				case CPF:
					if (poi[indices[j - h]].cpf > poi[temp].cpf)
					{
						troca(&indices[j], &indices[j - h]);
					}
					else
					{
						break;
					}
					break;
				case ENDERECO:
					if (poi[indices[j - h]].end > poi[temp].end)
					{
						troca(&indices[j], &indices[j - h]);
					}
					else
					{
						break;
					}
					break;
				}
			}
		}
	}
}

void selectionSort(const OrdInd_ptr poi, int indices[], int chave)
{
	for (int i = 0; i < poi->num_de_pessoas; i++)
	{
		int min = i;
		for (int j = i + 1; j < poi->num_de_pessoas; j++)
		{
			switch (chave)
			{
			case NOME:
				if (poi[indices[j]].nome < poi[indices[min]].nome)
				{
					min = j;
				}
				break;
			case CPF:
				if (poi[indices[j]].cpf < poi[indices[min]].cpf)
				{
					min = j;
				}
				break;
			case ENDERECO:
				if (poi[indices[j]].end < poi[indices[min]].end)
				{
					min = j;
				}
				break;
			}
		}
		troca(&indices[i], &indices[min]);
	}
}

void troca(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void particao(int *indices, int l, int r, int *i, int *j, OrdInd_ptr poi, int chave)
{
	*i = l;
	*j = r;
	int pivo = indices[(*i + *j) / 2];

	do
	{

		switch (chave)
		{
		case NOME:
			while (poi[indices[*i]].nome < poi[pivo].nome)
			{
				(*i)++;
			}
			while (poi[indices[*j]].nome > poi[pivo].nome)
			{
				(*j)--;
			}
			break;
		case CPF:
			while (poi[indices[*i]].cpf < poi[pivo].cpf)
			{
				(*i)++;
			}
			while (poi[indices[*j]].cpf > poi[pivo].cpf)
			{
				(*j)--;
			}
			break;
		case ENDERECO:
			while (poi[indices[*i]].end < poi[pivo].end)
			{
				(*i)++;
			}
			while (poi[indices[*j]].end > poi[pivo].end)
			{
				(*j)--;
			}
			break;
		}

		if (*i <= *j)
		{
			troca(&indices[*i], &indices[*j]);
			(*i)++;
			(*j)--;
		}
	} while (*i <= *j);
}

void quickSort(int *indices, int l, int r, OrdInd_ptr poi, int chave)
{
	if (l < r)
	{
		int i, j;
		particao(indices, l, r, &i, &j, poi, chave);
		quickSort(indices, l, j, poi, chave);
		quickSort(indices, i, r, poi, chave);
	}
}

OrdInd_ptr Cria(const char *nomeDoArquivo)
{

	if (nomeDoArquivo == nullptr)
	{
		std::cerr << "Erro: nome do arquivo é nulo!" << std::endl;
		return nullptr;
	}

	std::ifstream arquivo(nomeDoArquivo);
	std::string linha;
	int skip = 0;
	int num_de_pessoas;

	while (std::getline(arquivo, linha))
	{
		if (skip < 5)
		{
			skip++;
			continue;
		}
		std::istringstream ss(linha);
		num_de_pessoas = std::stoi(linha);
		break;
	}
	OrdInd_ptr poi = new OrdInd_t[num_de_pessoas + 1];
	poi->num_de_pessoas = num_de_pessoas;
	return poi;
}

void CarregaArquivo(OrdInd_ptr poi, const char *nomeDoArquivo, int *indices)
{
	std::ifstream arquivo(nomeDoArquivo);

	if (nomeDoArquivo == nullptr)
	{
		std::cerr << "Erro: nome do arquivo é nulo!" << std::endl;
		return;
	}

	std::string linha;
	int contador = 0;
	int skip = 0;

	while (std::getline(arquivo, linha))
	{
		if (skip < 6)
		{
			skip++;
			poi[0].introducao += linha;
			poi[0].introducao += '\n';
			continue;
		}
		std::istringstream ss(linha);
		std::string token;
		if (std::getline(ss, token, ','))
		{
			poi[contador].nome = token;
		}

		if (std::getline(ss, token, ','))
		{
			poi[contador].cpf = token;
		}

		if (std::getline(ss, token, ','))
		{
			poi[contador].end = token;
		}
		if (std::getline(ss, token, ','))
		{
			poi[contador].payload = token;
		}
		indices[contador] = contador;
		contador++;
	}
}
