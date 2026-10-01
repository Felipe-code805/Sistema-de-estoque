#include <stdio.h>

int main(){
    int opcao;
    char nome[100][50];
    float preco [100];
    int quantidade[100];
    int continuar;
    int codigo[100];
    int i = 0;
    int codigo_consulta;
    int encontrou = 0;

    do{
        printf("====================\n");
        printf("    ESTOQUE 2.0\n");
        printf("====================\n");
        printf("[1] Cadastrar produtos\n");
        printf("[2] Consultar produtos\n");
        printf("[3] Verificar estoque\n");
        printf("[4] Calcular valor total do estoque\n");
        printf("[5] Sair do sistema\n");

        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

    

    switch (opcao) {

    case 1: // cadastro
        do {
            printf("Digite o codigo do produto: ");
            scanf("%d", &codigo[i]);

            printf("Digite o nome do produto: ");
            scanf("%s", &nome);

            printf("Digite o preco do produto: R$");
            scanf("%f", &preco);

            printf("Digite a quantidade: ");
            scanf("%d", &quantidade);

            i++;

            printf("Digite 1 para cadastrar outro produto\n");
            printf("Digite 0 para retornar ao menu\n");

            scanf("%d", &continuar);

        } while (continuar == 1);
        break;

    case 2: // Consultar produtos
        printf("Digite o codigo do produto: ");
        scanf("%d", &codigo_consulta);

        for (int j = 0; j < i; j++){
            if (codigo[j] == codigo_consulta) {
                encontrou = 1;
                break;
            }
        }
        if (encontrou == 1) {
            printf("Produto encontrado");
        } else {
            printf("Produto nao encontrado");
        }
        
        break;
    
    case 3: // Verificar estoque
        if (quantidade == 0) {
            printf ("ESTOQUE ESGOTADO\n");
        } else if (quantidade <= 5) {
            printf ("ESTOQUE BAIXO\n");
        } else {
            printf("ESTOQUE NORMAL\n");
        }
        break;
    
    case 4:{// Calculo
        float total = 0;

        for (int j = 0; j < i; j++){
            total += preco [j] * quantidade [i];
        }
        printf("Valor total do estoque: R$ %.2f\n", total);
        break;
    } // Eu usei {} para isolar a variável total dentro do case 4 para não gerar conflito.

    case 5:
        // Sair do sistema
        printf("Saindo do sistema...");
        break;

    default:
        //opção inválida
        printf("Opcao invalida.\nPor favor, digite uma opcao de 1 a 5.\n");
        break;

        }
    } while(opcao != 5);
    return 0;
}