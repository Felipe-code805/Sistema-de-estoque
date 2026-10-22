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

int lerInteiro(char mensagem[], int minimo, int maximo);
float lerDecimal(char mensagem[]);
int ehNome(char texto[]);
void lerNome(char mensagem[], char destino[]);
int lerTexto(char texto[], int tamanho);
int ehInteiro(char texto[]);
int textoParaInteiro(char texto[]);
int ehDecimal(char texto[]);
float textoParaDecimal(char texto[]);
int codigoJaExiste(Produto produtos[], int ate, int codigo);

int mostrarMenuOpcao(int opcao) {
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

    opcao = lerInteiro ("Digite uma opcao entre 1 e 7: ", 1, 7);

    printf("\n");

    return opcao;
}

void mostrarTitulo(char tipo[]) {
    printf("====================\n");
    printf("%s PRODUTOS\n", tipo);
    printf("====================\n");
}

int cadastrarProdutos(Produto produto[], int quantidade) {
    quantidade = lerInteiro(
        "Quantos produtos deseja cadastrar? (1 a 100): ",
        1, 100
    );

    for (int i = 0; i < quantidade; i++) {
        printf("-----------------\n");
        printf("    Produto %d\n", i+1);
        printf("-----------------\n");

        while (1) {
            produto[i].codigo = lerInteiro(
                "Código do produto: ", 1, 2147483647
            );

            if (codigoJaExiste(produto, i, produto[i].codigo)) {
                printf("Esse codigo ja foi cadastrado. Digite outro.\n");
            } else {
                break;
            }
        }

        lerNome("Nome do produto: ", produto[i].nome);

        produto[i].preco = lerDecimal("Preco do produto (use ponto, ex: 12.50): ");

        produto[i].quantidade = lerInteiro(
            "Quantidade do produto: ", 0, 2147483647
        );
    }

    return quantidade;
}

void mostrarProdutosCadastrados(Produto produtos[], int quantidade) {
    if (quantidade == 0){
        printf("Nenhum produto cadastrado.\n\n");
        return;
    }
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

void consultarProduto(Produto produtos[], int quantidade) {
    int codigoProdutoConsulta;
    int encontrado = 0;

    if(quantidade == 0){
        printf("Nenhum produto cadastrado.\n\n");
        return;
    }

    codigoProdutoConsulta = lerInteiro(
        "Digite o código do produto que deseja consultar: ",
        1, 2147483647
    );

    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].codigo == codigoProdutoConsulta) {
            printf("Produto encontrado!\n\n");
            
            printf("Codigo: %d \n", produtos[i].codigo);
            printf("Nome: %s \n", produtos[i].nome);
            printf("Preco: %.2f \n", produtos[i].preco);
            printf("Quantidade: %d \n", produtos[i].quantidade);
            
            encontrado = 1;
            break;
        }
    }
    if (encontrado == 0){
        printf("Produto com código %d nao encontrado.\n\n", codigoProdutoConsulta);
    }
}

void calcularPrecoEstoque(Produto produtos[], int quantidade) {
    float totalValorEstoque = 0.0;
    
    if(quantidade == 0){
        printf("Nenhum produto cadastrado. Valor do estoque: R$ 0.00\n\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        float totalValorProdutos = produtos[i].quantidade * produtos[i].preco;
        totalValorEstoque += totalValorProdutos;
    }

    printf("Valor total em estoque:\n");
    printf("R$: %.2f\n\n", totalValorEstoque);
}

int lerInteiro(char mensagem[], int minimo, int maximo) {
    char texto[50];

    while (1) {
        printf("%s", mensagem);
        int coube = lerTexto(texto, 50);

        if (coube && ehInteiro(texto)) {
            int valor = textoParaInteiro(texto);

            if (valor >= minimo && valor <= maximo) {
                return valor;
            }
        }

        printf("Entrada invalida. Digite um numero inteiro de %d a %d.\n", minimo, maximo);
    }
}

float lerDecimal(char mensagem[]) {
    char texto[50];

    while (1) {
        printf("%s", mensagem);
        int coube = lerTexto(texto, 50);

        if (coube && ehDecimal(texto)) {
            return textoParaDecimal(texto);
        }

        printf("Entrada invalida. Digite um numero com PONTO (ex: 12.50).\n");
    }
}

int ehNome(char texto[]) {
    int temLetra = 0;

    if (texto[0] == '\0') {
        return 0;
    }

    for (int i = 0; texto[i] != '\0'; i++) {
        int ehLetra = (texto[i] >= 'A' && texto[i] <= 'Z') ||
                      (texto[i] >= 'a' && texto[i] <= 'z') ||
                      (texto[i] < 0);   // letras acentuadas

        if (ehLetra) {
            temLetra = 1;
        } else if (texto[i] != ' ') {
            return 0;
        }
    }

    return temLetra;
}

void lerNome(char mensagem[], char destino[]) {
    while (1) {
        printf("%s", mensagem);
        int coube = lerTexto(destino, 50);

        if (coube && ehNome(destino)) {
            return;
        }

        printf("Entrada invalida! Use apenas LETRAS e espacos (ate 49 caracteres).\n");
    }
}

int lerTexto(char texto[], int tamanho) {
    fgets(texto, tamanho, stdin);

    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == '\n' || texto[i] == '\r') {
            texto[i] = '\0';
            return 1;
        }
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    return 0;
}

int ehInteiro(char texto[]) {
    if (texto[0] == '\0') {
        return 0;
    }

    int i;
    for (i = 0; texto[i] != '\0'; i++) {
        if (texto[i] < '0' || texto[i] > '9') {
            return 0;
        }
    }

    if (i > 9) {
        return 0;
    }

    return 1;
}

int textoParaInteiro(char texto[]) {
    int valor = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        valor = valor * 10 + (texto[i] - '0');
    }

    return valor;
}
int ehDecimal(char texto[]) {
    int pontos = 0;
    int digitos = 0;
    int tamanho;

    for (tamanho = 0; texto[tamanho] != '\0'; tamanho++) {
        if (texto[tamanho] >= '0' && texto[tamanho] <= '9') {
            digitos++;
        } else if (texto[tamanho] == '.') {
            pontos++;
        } else {
            return 0;       // vírgula, letra, símbolo, espaço...
        }
    }

    if (digitos == 0 || pontos > 1 || tamanho > 12) {
        return 0;
    }

    // o ponto não pode ser o primeiro nem o último caractere (".5" ou "5.")
    if (texto[0] == '.' || texto[tamanho - 1] == '.') {
        return 0;
    }

    return 1;
}


float textoParaDecimal(char texto[]) {
    float valor = 0;
    float divisor = 1;
    int depoisDoPonto = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == '.') {
            depoisDoPonto = 1;
        } else if (depoisDoPonto == 0) {
            valor = valor * 10 + (texto[i] - '0');
        } else {
            divisor = divisor * 10;
            valor = valor + (texto[i] - '0') / divisor;
        }
    }

    return valor;
}

int codigoJaExiste(Produto produtos[], int ate, int codigo){
    for(int i = 0; i < ate; i++){
        if(produtos [i].codigo == codigo){
            return 1;
        }
    }
    return 0;
}

int main() {
    // variáveis
    int opcao = 0;
    int quantidadeProdutos = 0;
    Produto produtos[100];

    do {
        opcao = mostrarMenuOpcao(opcao);

        switch (opcao) {
            case 1:
                mostrarTitulo("CADASTRAR");
                quantidadeProdutos = cadastrarProdutos(produtos, quantidadeProdutos);
                break;
            case 2:
                mostrarTitulo("LISTAR");
                mostrarProdutosCadastrados(produtos, quantidadeProdutos);
                break;
            case 3:
                mostrarTitulo("CONSULTAR");
                consultarProduto(produtos, quantidadeProdutos);
                break;
            case 4:
                mostrarTitulo("SALVAR");
                break;
            case 5:
                mostrarTitulo("CARREGAR");
                break;
            case 6:
                mostrarTitulo("CALCULAR");
                calcularPrecoEstoque(produtos, quantidadeProdutos);
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
