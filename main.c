#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX 10
// O cardápio tem todos os itens disponíveis, que são descritos em uma lista (por exemplo, um array).
// Cada item possui: identificação (inteiro), a descrição (nome do item) e o preço (real).
// Saída do restaurante, os clientes fazem uma fila grande
// Estrutura estática sequencial quanto uma estrutura dinâmica encadeada





struct cardapio
{
    int id;
    char descricao[50];
    float preco;
};
typedef struct cardapio Cardapio; // Cardapio é um apelido para struct cardapio

struct lista
{
    Cardapio *itens;
    int qtd = MAX;
};
typedef struct lista Lista; // Lista é um apelido para struct lista




//////////////////////////////////////////////////////////////////
struct node {               // Estrutura de dados para a fila
    char info;
    struct node *next;
};

typedef struct node Node;   // Node é um apelido para struct node

struct pilha {              // Estrutura de dados para a pilha
    Node *topo;
};

typedef struct pilha Pilha; // Pilha é um apelido para struct pilha


Node *newNode()             // Cria um novo nó
{
    Node *n;
    n = malloc(sizeof(Node));
    return n;
}


void deleteNode(Node *n)    // Deleta o nó e libera a memória
{
    if (n != NULL) free(n);
}


Pilha *criar()              // Cria uma pilha vazia
{
    Pilha *P;
    P = malloc(sizeof(Pilha));
    if (P != NULL) P->topo = NULL; // pilha vazia
    return P;
}











int main (){
    
  
  
 return 0; 
}
