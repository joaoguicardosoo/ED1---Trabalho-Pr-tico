#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


struct cardapio
{
    int id;
    char desc[20];
    float preco;
};
typedef struct cardapio Cardapio;

struct comanda{
    char nome[20];
    float valor;
    int id;
    struct comanda *next;
};
typedef struct comanda Comanda;

struct fila{
    struct comanda *inicio;
    struct comanda *fim;
};
typedef struct fila Fila;

//Cria a fila de comandas
Fila *criarFila(){
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}
//Gera um numero aleatorio de 0 a 100 para o id da comanda
int gerarId(){
    srand(time(NULL));
    int id = rand() % 100;
    return id;
}

//Insere a comanda na fila
int insereFila(Fila *f, char nome[20], int id){
    Comanda *c = (Comanda *)malloc(sizeof(Comanda));
    strcpy(c->nome, nome);
    c->id = id;
    
    if(f->inicio == NULL){
        f->inicio = c;
        f->fim = c;
        c->next = NULL;
    }
    else{
        f->fim->next = c;
        f->fim = c;
        c->next = NULL;
    }
    return 0;
}

//Cria o cardapio
Cardapio *criarCardapio(int qtd)
{
    Cardapio *menu;
    menu = (Cardapio *)malloc(qtd * sizeof(Cardapio));
    if (menu == NULL)
    {
        printf("Falha na alocacao de memoria\n");
        exit(1);
    }

    return menu;
}

//Insere os itens no cardapio
int inserirCardapio(Cardapio *menu, int id, char desc[20], float preco, int aux)
{
    menu[aux].id = id;
    strcpy(menu[aux].desc, desc);
    menu[aux].preco = preco;

    return 0;
}
//Destroi o cardapio
int destruir(Cardapio *menu)
{
    free(menu);
    return 0;
}

//Carrega os itens no cardapio
void carregaItens(Cardapio *menu){
    inserirCardapio(menu, 1, "Pizza", 55.00, 0);
    inserirCardapio(menu, 2, "Coca-cola", 6.00, 1);
    inserirCardapio(menu, 3, "Hamburguer", 25.00, 2);
    inserirCardapio(menu, 4, "Batata frita", 13.00, 3);
    inserirCardapio(menu, 5, "Suco", 7.50, 4);
    inserirCardapio(menu, 6, "Agua", 3.00, 5);
    inserirCardapio(menu, 7, "Pastel", 6.50, 6);
    inserirCardapio(menu, 8, "Macarrão", 19.00, 7);
    inserirCardapio(menu, 9, "Picanha", 89.00, 8);
    inserirCardapio(menu, 10, "Salgado", 3.50, 9);
    inserirCardapio(menu, 11, "Caipirinha", 15.00, 10);
}



int main()
{
    Cardapio *menu;
    int qtd = 11; // Quantidade de itens no menu
    int op = 0; //Opcao do usuario
    char nome[20]; //Nome do usuario
    int id; //Id da comanda
    menu = criarCardapio(qtd);
    carregaItens(menu);
    printf("Digite uma opção\n");
    printf("1 - Fazer pedido\n");
    scanf("%d", &op);
    if(op == 1)
    {
        printf("Digite o nome do cliente:\n");
        scanf("%s", nome);
        id = gerarId();
        printf("Ola %s, o que deseja pedir?Um pedido por vez. Seu número de comanda é: %d\n", nome, id);
        for (int i = 0; i < qtd; i++)
            printf("%d - %s - R$ %.2f\n", menu[i].id, menu[i].desc, menu[i].preco);
        
    }
    
    destruir(menu);
    return 0;
}
