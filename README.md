
Esta implementação tem como objetivo ordenar indiretamente uma base de dados xCSV lida de um arquivo. Serão utilizadas 3 chaves de ordenação diferentes: nome, CPF e endereço, e então serão imprimidas as listas ordenadas por cada chave.
Para resolver este problema, foi seguida uma abordagem de implementar um array de índices com o mesmo número de elementos da lista que deve ser ordenada e ordenando esse array em seu lugar, diminuindo o custo de mover os dados contidos na lista.

Está organizado na seguinte estrutura: OrdenacaoIndireta.hpp contém definições de valores constantes, da estrutura de dados que será utilizada de nome OrdInd, e das funções que serão utilizadas. OrdenacaoIndireta.cpp contém a implementação destas funções, e main.cpp chama essas funções e as utiliza conforme requisitado.
É utilizado um array de ponteiros para a struct OrdInd, facilitando o acesso por índice e a ordenação do array de índices.
As funções Cria e CarregaArquivo lêem o arquivo e criam um array de ponteiros OrdInd, lendo e armazenando os dados de cada pessoa dentro da estrutura. Um array de índices de tamanho igual ao número de pessoas na base de dados também é criado, o qual será usado para realizar a ordenação indireta.
Após isso o código utiliza de três algoritmos de ordenação – QuickSort, SelectionSort e Shellsort – para ordenar o array de índices. Cada algoritmo é utilizado três vezes, uma para cada chave.
