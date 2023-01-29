typedef struct cardapio Cardapio;
typedef struct cliente Cliente;

Cardapio *criarCardapio();
int inserirCardapio(Cardapio *menu, int id, char nome[20], float preco);
void leItens(Cardapio *menu);
void adicionarItem(Cliente* cliente, Cardapio comanda);
void imprimeComanda(Cardapio *menu);
int destruir(Cardapio *menu);
