<h1 align="left">Sistema de Busca Sequencial Indexada 📋</h1>

###

<p align="left">Este projeto implementa um sistema de busca sequencial indexada em um arquivo contendo 1 milhão de registros ordenados gerados aleatoriamente. O sistema utiliza uma tabela auxiliar de índices para otimizar a busca.</p>

###

<h2 align="left">| Descrição ℹ️</h2>

###

<p align="left">O programa gera um array de números inteiros ordenados e permite ao usuário buscar por valores específicos dentro desse array. Se o valor buscado estiver presente, o programa informa a posição do valor e o índice correspondente na tabela de índices.</p>

###

<h3 align="left">Mas afinal, o que é Busca Sequencial? 🤔</h3>

###

<p align="left">A busca sequencial consiste em percorrer cada elemento de uma lista ou array um a um até encontrar o valor desejado ou chegar ao final da lista. Este método é ineficiente para grandes conjuntos de dados, pois pode exigir um número significativo de comparações, especialmente se o valor desejado estiver perto do final da lista ou não estiver presente.</p>

###

<h3 align="left">Então qual é a solução para um grande conjunto de dados? >> Adicionar a indexação! 😸</h3>

###

<p align="left">Na busca sequencial indexada, um índice é criado em intervalos regulares, permitindo que o algoritmo salte diretamente para a parte relevante do array, em vez de fazer uma varredura completa. Isso reduz o número de comparações necessárias, tornando a busca mais eficiente. A indexação envolve a criação de uma tabela de índices que contém referências a posições específicas em um array ou lista. Esses índices podem ser usados para localizar rapidamente intervalos em que os dados estão armazenados.</p>

###

<h2 align="left">| Explicação passo a passo do código 👩🏾‍💻</h2>

###

<h3 align="left">Geração de Números Ordenados</h3>

###

<p align="left">O projeto começa gerando um array de 1.000.000 de números inteiros aleatórios, mas ordenados. Isso é feito pela função carregarNumerosOrdenados(), que usa rand() para criar números e garantir que eles estejam em ordem crescente.</p>

###

<h3 align="left">Criação da Tabela de Índices</h3>

###

<p align="left">A função criarTabelaIndices() é responsável por criar uma tabela de índices. Para isso, ela armazena a posição de cada 1000º número do array em um array separado de índices. Isso permite que a busca sequencial indexada localize rapidamente os intervalos onde os dados podem estar.</p>

###

<h3 align="left">Busca Sequencial Indexada</h3>

###

<p align="left">A função buscaSequencialIndexada() implementa o algoritmo de busca sequencial indexada. Primeiro, ela utiliza a tabela de índices para identificar rapidamente o intervalo onde o valor buscado pode estar. Depois, realiza uma busca sequencial apenas dentro desse intervalo, verificando cada elemento até encontrar o valor ou determinar que ele não está presente.</p>

###

<h3 align="left">Interação com o Usuário</h3>

###

<p align="left">O programa interage com o usuário, solicitando que ele insira um valor para buscar. O loop continua até que o usuário insira um número negativo, momento em que o programa é encerrado. O resultado da busca é exibido para o usuário, informando se o valor foi encontrado, sua posição e o índice correspondente.</p>

###

<h2 align="left">| Conclusão ⭐</h2>

###

<p align="left">O projeto é uma excelente oportunidade para aprender sobre algoritmos de busca e manipulação de arrays em C. A implementação da busca sequencial indexada ajuda a entender como melhorar a eficiência de buscas em grandes conjuntos de dados, e o uso de arrays ordenados é uma prática comum em muitas aplicações de programação.</p>

###
