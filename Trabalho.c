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

        while (scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 5){
            printf("Opcao invalida.\nDigite um numero de 1 a 5: ");
            scanf("%*s");
        }

    switch (opcao) {

    case 1: // cadastro
        continuar = 1;
        do {
            if (i >= 100){
                printf("Estoque cheio.\n");
                break;
            }
            printf("Digite o codigo do produto: ");
            while (scanf("%d", &codigo[i])!= 1 || codigo[i] < 0){
                printf("Codigo invalido.\nDigite um codigo valido: ");
                scanf("%*s");
            }

            encontrou = 0;
            for (int j = 0; j < i; j++){
                if(codigo[j] == codigo [i]){
                    encontrou = 1;
                    break;
                }
            }
            if (encontrou == 1){
                printf("Codigo ja cadastrado.\n");
                continue;
            }

            printf("Digite o nome do produto: ");
            scanf("%s", nome[i]);

            printf("Digite o preco do produto: R$");
            while (scanf("%f", &preco[i]) != 1 || preco[i] < 0){
                printf("Preco invalido.\nDigite um preco valido: R$");
                scanf("%*s");
            }

            printf("Digite a quantidade: ");
            while (scanf("%d", &quantidade[i]) != 1 || quantidade[i] < 0){
                printf("Quantidade invalida.\nDigite uma quantidade valida: ");
                scanf("%*s");
            }

            i++;

            printf("Digite 1 para cadastrar outro produto\n");
            printf("Digite 0 para retornar ao menu\n");
            while (scanf("%d", &continuar) != 1){
                printf("Entrada invalida.\nDigite 1 ou 0: ");
                scanf("%*s");
            }

        } while (continuar == 1);
        break;

    case 2: // Consultar produtos
        printf("Digite o codigo do produto: ");

        while (scanf("%d", &codigo_consulta) != 1 || codigo_consulta < 0){
            printf("Codigo invalido.\nDigite um codigo valido: ");
            scanf("%*s");
        }
        encontrou = 0;

        for(int j = 0; j < i; j++){
            if (codigo[j] == codigo_consulta){
                encontrou = 1;

                printf("Produto encontrado\n");
                printf("Codigo: %d\n", codigo[j]);
                printf("Nome: %s\n", nome[j]);
                printf("Preco: %.2f\n", preco[j]);
                printf("Quantidade: %d\n", quantidade[j]);
                break;
            }
        }
        if (encontrou == 0) {
            printf("Produto nao encontrado\n");
        }
        
        break;
    
    case 3: // Verificar estoque
        if (i == 0){
            printf("Nenhum produto cadastrado.\n");
            break;
        }
        
        for (int j = 0; j < i; j++){
            printf("Produto: %s\n", nome[j]);
            if (quantidade[j] == 0) {
                printf ("ESTOQUE ESGOTADO\n");
            } else if (quantidade[j] <= 5) {
                printf ("ESTOQUE BAIXO\n");
            } else {
                printf("ESTOQUE NORMAL\n");
            }
        }
        
        break;
    
    case 4:{// Calculo
        float total = 0;

        if (i == 0){
            printf("Nenhum produto cadastrado.\n");
            break;
        }

        for (int j = 0; j < i; j++){
            total += preco [j] * quantidade [j];
        }
        printf("Valor total do estoque: R$ %.2f\n", total);
        break;
    } // Eu usei {} para isolar a variável total dentro do case 4 para não gerar conflito.

    case 5:
        // Sair do sistema
        printf("Saindo do sistema...\n");
        break;

    default:
        //opção inválida
        printf("Opcao invalida.\nPor favor, digite uma opcao de 1 a 5.\n");
        break;

        }
    } while(opcao != 5);
    return 0;
}
