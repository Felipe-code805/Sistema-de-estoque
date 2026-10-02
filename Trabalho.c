#include <stdio.h>

int main() {
    int opcao = 0;
    int codigo[100];
    char nome[100][50];
    float preco[100];
    int quantidade[100];
    int total_produtos = 0;
    int continuar;
    int codigo_consulta;
    int encontrou;
    int j;
    float total;

    do {
        printf("\n\n====================================\n");
        printf(" SISTEMA DE CONTROLE DE ESTOQUE\n");
        printf("====================================\n\n");
        printf("1 - Cadastrar produtos\n");
        printf("2 - Consultar produtos\n");
        printf("3 - Verificar estoque\n");
        printf("4 - Calcular valor total do estoque\n");
        printf("5 - Sair\n\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n------------------------------------\n");
                printf(" [1] CADASTRO DE PRODUTOS\n");
                printf("------------------------------------\n\n");
                do {
                    if (total_produtos >= 100) {
                        printf("Limite de 100 produtos atingido.\n");
                        break;
                    }

                    printf(">>> Produto %d <<<\n\n", total_produtos + 1);
                    printf("Digite o codigo do produto: ");
                    scanf("%d", &codigo[total_produtos]);

                    printf("Digite o nome do produto: ");
                    scanf("%49s", nome[total_produtos]);

                    printf("Digite o preco do produto: R$ ");
                    scanf("%f", &preco[total_produtos]);

                    printf("Digite a quantidade: ");
                    scanf("%d", &quantidade[total_produtos]);

                    total_produtos++;
                    printf("\n[OK] Produto cadastrado com sucesso.\n");
                    printf("------------------------------------\n\n");

                    printf("Digite 1 para cadastrar outro produto\n");
                    printf("Digite 0 para retornar ao menu\n");
                    printf("Sua escolha: ");
                    scanf("%d", &continuar);
                    printf("\n");
                } while (continuar == 1);
                printf("---------- FIM DO CADASTRO ----------\n");
                break;

            case 2:
                printf("\n------------------------------------\n");
                printf(" [2] CONSULTA DE PRODUTOS\n");
                printf("------------------------------------\n\n");
                printf("Digite o codigo do produto: ");
                scanf("%d", &codigo_consulta);
                printf("\n>>> RESULTADO DA CONSULTA <<<\n\n");
                encontrou = 0;

                for (j = 0; j < total_produtos; j++) {
                    if (codigo[j] != codigo_consulta) {
                        continue;
                    }

                    encontrou = 1;
                    printf("[OK] Produto encontrado\n\n");
                    printf("Codigo: %d\n", codigo[j]);
                    printf("Nome: %s\n", nome[j]);
                    printf("Preco: R$ %.2f\n", preco[j]);
                    printf("Quantidade: %d\n", quantidade[j]);
                    break;
                }

                if (encontrou == 0) {
                    printf("[!] Produto nao encontrado.\n");
                }
                printf("\n------------------------------------\n");
                break;

            case 3:
                printf("\n------------------------------------\n");
                printf(" [3] VERIFICACAO DO ESTOQUE\n");
                printf("------------------------------------\n");
                for (j = 0; j < total_produtos; j++) {
                    printf("\nCodigo: %d\nNome: %s\nQuantidade: %d\nSituacao: ",
                           codigo[j], nome[j], quantidade[j]);

                    if (quantidade[j] == 0) {
                        printf("ESTOQUE ESGOTADO\n");
                    } else if (quantidade[j] <= 5) {
                        printf("ESTOQUE BAIXO\n");
                    } else {
                        printf("ESTOQUE NORMAL\n");
                    }
                    printf("------------------------------------\n");
                }
                break;

            case 4:
                printf("\n------------------------------------\n");
                printf(" [4] VALOR TOTAL DO ESTOQUE\n");
                printf("------------------------------------\n\n");
                total = 0;
                for (j = 0; j < total_produtos; j++) {
                    total += preco[j] * quantidade[j];
                }
                printf("Valor total do estoque: R$ %.2f\n", total);
                printf("\n------------------------------------\n");
                break;

            case 5:
                printf("\n------------------------------------\n");
                printf(" [5] Saindo do sistema...\n");
                printf("------------------------------------\n\n");
                break;

            default:
                printf("\n------------------------------------\n");
                printf(" [!] Opcao invalida.\n");
                printf(" Digite um numero de 1 a 5.\n");
                printf("------------------------------------\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}
