#include <stdio.h>
//SISTEMA VERSAO 3

// usando "typedef" eu não preciso colocar sempre a palavra "struct" ao criar uma variável do tipo Produto
typedef struct Produto
{
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
} Produto;

void mostrarTitulo(char tipo[]) {
    printf("====================\n");
    printf("%s PRODUTOS\n", tipo);
    printf("====================\n");
}

void cadastrarProdutos(Produto produto[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("-----------------\n");
        printf("    Produto %d\n", i+1);
        printf("-----------------\n");
        
        printf("Código do produto: ");
        // a função setbuf limpa o buffer da entrada do usuário entre os inputs
        setbuf(stdin, NULL);
        scanf(" %d", &produto[i].codigo);
        setbuf(stdin, NULL);

        printf("Nome do produto: ");
        // com esse comando, não precisa se preocupar com o buffer da entrada do usuário
        fgets(produto[i].nome, 50, stdin);

        printf("Preco do produto: ");
        setbuf(stdin, NULL);
        scanf(" %f", &produto[i].preco);
        setbuf(stdin, NULL);

        printf("Quantidade do produto: ");
        setbuf(stdin, NULL);
        scanf(" %d", &produto[i].quantidade);
        setbuf(stdin, NULL);
    }
}

void mostrarProdutosCadastrados(Produto produtos[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("-----------------\n");
        printf("    Produto %d\n", i+1);
        printf("-----------------\n");

        printf("Codigo: %d \n", produtos[i].codigo);
        printf("Nome: %s \n", produtos[i].nome);
        printf("Preco: %.2f \n", produtos[i].preco);
        printf("Quantidade: %d \n", produtos[i].quantidade);

        printf("_________________________________\n");
        printf("´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´\n");
        printf("\n");
    }
}

int main() {
    // variáveis
    int opcao;
    int quantidadeProdutos;
    Produto produtos[100];

    do {
        printf("====================\n");
        printf("    ESTOQUE 3.0\n");
        printf("====================\n");
        printf("[1] Cadastrar produtos\n");
        printf("[2] Listar produtos\n");
        printf("[3] Consultar produto\n");
        printf("[4] Salvar dados\n");
        printf("[5] Carregar dados\n");
        printf("[6] Calcular valor do estoque\n");
        printf("[7] Sair do sistema\n");

        printf("Digite uma opcao: ");

        while (scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 7){
            printf("Opcao invalida.\nDigite um numero de 1 a 7: ");
            scanf("%*s");
        }

        printf("\n");

        switch (opcao) {
            case 1:
                mostrarTitulo("CADASTRAR");

                printf("Quantos produtos deseja cadastrar? (1 a 100): ");
                setbuf(stdin, NULL);
                scanf(" %d", &quantidadeProdutos);
                setbuf(stdin, NULL);

                cadastrarProdutos(produtos, quantidadeProdutos);
                break;
            case 2:
                mostrarTitulo("LISTAR");
                mostrarProdutosCadastrados(produtos, quantidadeProdutos);
                break;
            case 3:
                mostrarTitulo("CONSULTAR");
                break;
            case 4:
                mostrarTitulo("SALVAR");
                break;
            case 5:
                mostrarTitulo("CARREGAR");
                break;
            case 6:
                mostrarTitulo("CALCULAR");
                break;
            case 7:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida.\nPor favor, digite uma opcao de 1 a 7.\n");
                break;
        }
    } while(opcao != 7);
    
    return 0;
}