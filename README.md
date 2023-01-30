<h1 align="center"> Trabalho prático - Estrutura de Dados 1 </h1> 

Grupo: Gustavo Borges, João Guilherme e Jerusa Carneiro

Um restaurante funciona da seguinte maneira: cada cliente escolhe diferentes itens do cardápio. O cardápio tem todos os itens disponíveis, que são descritos em uma lista (por exemplo, um array). Cada item aparece na lista com um número de identificação (inteiro), a descrição (nome do item) e o preço (real). Na saída do restaurante, os clientes fazem uma fila invariavelmente grande e são atendidos pela gerente do restaurante.

Cada cliente tem uma comanda com a lista dos produtos consumidos. Para cada cliente atendido, a gerente informa o preço total, somando os valores dos itens da comanda. Além disso, o restaurante está agraciando os clientes com um pequeno chocolate. A gerente mantém uma pilha de chocolates diversos e entrega ao cliente atendido o chocolate do topo da pilha.

# :hammer: Como fizemos o trabalho prático

Fizemos a Estrutura do cardapio e do cliente com sua comanda. O programa possui a função de ler o arquivo "cardapio.txt" e imprimir o cardapio. 
Usamos uma função para inserir aleatoriamente os itens do cardapio na comanda para cada cliente e no fim também recebe um cholate aleatorio. Além disso, faz a soma dos itens consumidos e imprime na tela o valor total da comanda e qual cholate o cliente recebeu.

restaurante.c: esse arquivo contém a função principal (main) e a implementação das funções do TAD.
restaurante.h: esse arquivo contém as declarações das funções do TAD.

# 🛣️ Fluxo
<img src="https://i.imgur.com/EirmSw0.png" width="400px" />
