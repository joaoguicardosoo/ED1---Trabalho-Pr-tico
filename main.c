#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ITEMS 18
#define MAX_CLIENTS 15


//Estrutura do Cardapio
typedef struct {
    int id;
    char nome[30];
    float preco;
} Cardapio;

// Estrutura para o cliente e sua comanda
typedef struct {
    int id;
    int qtdItens;
    float total;
    int chocolate; // 0 = branco, 1 = preto
} Cliente;

//Cria o cardapio
Cardapio *criarCardapio()
{
    Cardapio *menu;
    menu = (Cardapio *)malloc(MAX_ITEMS * sizeof(Cardapio));
    if (menu == NULL)
    {
        printf("Falha na alocacao de memoria\n");
        exit(1);
    }

    return menu;
}

//Insere os itens no cardapio
int inserirCardapio(Cardapio *menu, int id, char nome[20], float preco)
{
    menu->id = id;
    strcpy(menu->nome, nome);
    menu->preco = preco;

    return 0;
}

//Carrega os itens no cardapio
void leItens(Cardapio *menu)
{

    FILE *file = fopen("cardapio.txt", "r"); //funcao para abrir o arquivo "cardapio" em modo "somente leitura"

    if(!file)//Se houve erro na abertura
    {
        printf("Arquivo nao pode ser aberto!\n"); //retorna erro

        return 0;
    }

    for(int i = 0; i < MAX_ITEMS; i++) //funcao para ler lista do txt e inserir na estrutura "cardapio"
    {
        fscanf(file, "%d", &menu[i].id);
        fscanf(file, "%s", &menu[i].nome);
        fscanf(file, "%f", &menu[i].preco);
    }

    fclose(file); //Fecha o arquivo
}

//Função para adicionar itens na comanda do cliente
void adicionarItem(Cliente* cliente, Cardapio comanda)
{
    cliente->qtdItens++; //Adiciona o item
    cliente->total += comanda.preco; //Calcula o preço total dos itens adicionados
}

//Função para imprimir na tela o Cardapio que foi lido do arquivo
void imprimeComanda(Cardapio *menu)
{
    printf("Cardapio: \n");
    for (int i = 0; i < MAX_ITEMS; i++)
            printf("%d - %s - R$ %.2f\n", menu[i].id, menu[i].nome, menu[i].preco);
}

//Destroi o cardapio
int destruir(Cardapio *menu)
{
    free(menu);
    return 0;
}

int main()
{
    srand(time(NULL)); //Função para que a cada execução do programa os itens consumidos pelos clientes sejam diferentes e, consequentemente, o valor total será diferente

    Cardapio *menu; //Inicializa o menu
    menu = criarCardapio(MAX_ITEMS); //Cria o cardapio

    leItens(menu); //Lê os itens do cardapio que estão no arquivo
    imprimeComanda(menu); //Imprime os itens do cardapio

    printf("\n");

    Cliente fila[MAX_CLIENTS]; //Cria a fila de Clientes
    int inicio = 0, fim = 0;

    // Adiciona clientes na fila e itens na comanda de cada cliente
    for (int i = 0; i < MAX_CLIENTS; i++) {
        fila[fim].id = i;
        adicionarItem(&fila[fim], menu[rand() % MAX_ITEMS]); //adiciona aleatoriamente itens na comanda
        adicionarItem(&fila[fim], menu[rand() % MAX_ITEMS]); //adiciona aleatoriamente itens na comanda
        fila[fim].chocolate = rand() % 2; //adiciona aleatoriamente o chocolate (preto ou branco) para o cliente
        fim++;
    }

    // Imprime o valor total do consumo de cada cliente e o tipo de chocolate recebido
    while (inicio != fim) {
        printf("Cliente %d: R$%.2f - Chocolate %s\n", fila[inicio].id, fila[inicio].total, fila[inicio].chocolate == 0 ? "branco" : "preto");
        inicio++;
    }

    destruir(menu); //Destroi o cardapio

    return 0;
}
