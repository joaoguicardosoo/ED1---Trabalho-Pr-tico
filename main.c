#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct cardapio
{
    int id;
    char desc[20];
    float preco;
};
typedef struct cardapio Cardapio;

Cardapio criarCardapio(Cardapio *menu, int qtd)
{
    menu = malloc(qtd * sizeof(Cardapio));
    if (menu == NULL)
    {
        printf("Falha na alocacao\n");
        exit(1);
    }
    return *menu;
}

int inserirCardapio(Cardapio *menu){
    FILE *arq;
    if (fopen("cardapio.txt", "r") == NULL)
    {
        printf("Falha na abertura do arquivo\n");
        return -1;
    }

    while (fscanf(arq, "%d %s %f", &menu->id, menu->desc, &menu->preco) != EOF);

    return 0;

}
int printacardapio(Cardapio *menu){
    for (int i=1; i <=3; i++){
        printf("%d %s %f", menu[i].id, menu[i].desc, menu[i].preco);
    }


}

int main()
{
    Cardapio *menu;
    int qtd = 3; //Quantidade de itens no menu
    criarCardapio(menu, qtd);
    inserirCardapio(menu);
    printacardapio(menu);
    return 0;
}

